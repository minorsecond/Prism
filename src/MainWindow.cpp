//
// Created by rossw on 11/4/2022.
//

#include <QFileDialog>
#include <QStandardPaths>
#include <regex>
#include <filesystem>
#include <algorithm>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    /*
     * Set up the main window.
     */

    ui->setupUi(this);
    this->setFixedSize(700, 325);
    ui->progressBar->setValue(0);
    ui->outputPathEdit->setDisabled(true);
    ui->outputPathBrowseButton->setDisabled(true);

    const std::array<std::string, 4> white_space_replacement_strings{"None", ".", "_", "-"};
    for (const std::string &replacement_char: white_space_replacement_strings) {
        ui->whiteSpaceReplacementSelector->addItem(QString::fromStdString(replacement_char));
    }

    populate_attribute_picker();

    connect(ui->inputPathBrowseButton, &QPushButton::clicked, this,
            &MainWindow::clicked_input_browse_button);
    connect(ui->outputPathBrowseButton, &QPushButton::clicked, this,
            &MainWindow::clicked_output_browse_button);
    connect(ui->mainButtonBox, &QDialogButtonBox::accepted, this, &MainWindow::clicked_ok);
    connect(ui->attributeSelectorInput, &QComboBox::activated, this, &MainWindow::add_attribute);
    connect(ui->seperateOutputPathCheckbox, &QCheckBox::stateChanged, this,
            &MainWindow::enable_disable_output_path_edit);
}

void MainWindow::populate_attribute_picker() {
    for (const auto &exif_pair: this->exif_attributes) {
        ui->attributeSelectorInput->addItem(QString::fromStdString(exif_pair.first));
    }
}

void MainWindow::get_input_directory() {
    QString input_path{QFileDialog::getExistingDirectory(this, "Select input directory")};
    ui->inputPathEdit->setText(input_path);
}

void MainWindow::get_output_directory() {
    QString output_path{QFileDialog::getExistingDirectory(this, "Select output directory")};
    ui->outputPathEdit->setText(output_path);
}

std::string MainWindow::regex_finder(const std::string &in_string) {
    const std::string start_delim{"{"};
    const std::string end_delim{"}"};

    size_t first{in_string.find(start_delim)};
    size_t last{in_string.find(end_delim)};

    return in_string.substr(first, (last + 1) - first);
}

std::vector<ExifData> MainWindow::read_images() {
    std::vector<std::string> file_extensions{};
    std::vector<ExifData> images{};
    const std::string input_path{ui->inputPathEdit->text().toStdString()};

    const std::vector<std::string> jpeg_ext{".jpg", ".jpeg"};
    const std::vector<std::string> raw_ext{".raw", ".cr2", ".dng"};
    const std::vector<std::string> tiff_ext{".tiff", ".tif"};

    if (ui->jpgCheckBox->isChecked()) {
        file_extensions.insert(file_extensions.end(), jpeg_ext.begin(), jpeg_ext.end());
    }
    if (ui->rawCheckBox->isChecked()) {
        file_extensions.insert(file_extensions.end(), raw_ext.begin(), raw_ext.end());
    }
    if (ui->tiffCheckBox->isChecked()) {
        file_extensions.insert(file_extensions.end(), tiff_ext.begin(), tiff_ext.end());
    }

    for (const auto &entry: std::filesystem::directory_iterator(input_path)) {
        for (const std::string &ext: file_extensions) {
            std::string extension{entry.path().extension().string()};
            std::transform(extension.begin(), extension.end(), extension.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            if (extension == ext) {
                ExifData data(entry.path().string());
                images.push_back(data);
            }
        }
    }

    return images;
}

void MainWindow::add_attribute() {
    std::string chosen_attribute{};
    if (!ui->pathFormatLineEdit->text().toStdString().empty()) {
        chosen_attribute += "-";
    }

    chosen_attribute += regex_finder(ui->attributeSelectorInput->currentText().toStdString());
    const std::string filename_format_text{ui->pathFormatLineEdit->text().toStdString() + chosen_attribute};
    ui->pathFormatLineEdit->setText(QString::fromStdString(filename_format_text));
    ui->pathFormatLineEdit->setFocus();
}

std::string MainWindow::replace_whitespaces(std::string in_string) {
    const char whitespace_replacement{ui->whiteSpaceReplacementSelector->currentText().toStdString()[0]};
    std::replace(in_string.begin(), in_string.end(), ' ', whitespace_replacement);

    return in_string;
}

std::map<std::string, std::string> MainWindow::format_to_path(const std::vector<ExifData> &images,
                                                              const std::string &output_path) {
    std::map<std::string, std::string> images_with_paths{};

    for (const ExifData &image: images) {
        const std::string image_filename{std::filesystem::path(image.image_path).filename().string()};

        std::string path_format{ui->pathFormatLineEdit->text().toStdString()};

        path_format = std::regex_replace(path_format, std::regex(R"(\{cmake\})"), image.camera_make());
        path_format = std::regex_replace(path_format, std::regex(R"(\{cmodel\})"), image.camera_model());
        path_format = std::regex_replace(path_format, std::regex(R"(\{cserial\})"), image.camera_serial_num());
        path_format = std::regex_replace(path_format, std::regex(R"(\{corient\})"), image.camera_orientation());
        path_format = std::regex_replace(path_format, std::regex(R"(\{xres\})"), image.x_resolution());
        path_format = std::regex_replace(path_format, std::regex(R"(\{yres\})"), image.y_resolution());
        path_format = std::regex_replace(path_format, std::regex(R"(\{etimes\})"), image.exposure_time());
        path_format = std::regex_replace(path_format, std::regex(R"(\{iso\})"), image.iso());
        path_format = std::regex_replace(path_format, std::regex(R"(\{dtime\})"), image.date_hms());
        path_format = std::regex_replace(path_format, std::regex(R"(\{aperval\})"), image.aperture_value());
        path_format = std::regex_replace(path_format, std::regex(R"(\{meter\})"), image.meter_mode());
        path_format = std::regex_replace(path_format, std::regex(R"(\{inum\})"), image.image_number());
        path_format = std::regex_replace(path_format, std::regex(R"(\{xmode\})"), image.exposure_mode());
        path_format = std::regex_replace(path_format, std::regex(R"(\{wb\})"), image.white_balance());
        path_format = std::regex_replace(path_format, std::regex(R"(\{lmake\})"), image.lens_make());
        path_format = std::regex_replace(path_format, std::regex(R"(\{lmodel\})"), image.lens_model());
        path_format = std::regex_replace(path_format, std::regex(R"(\{lserial\})"), image.lens_serial_num());

        path_format = replace_whitespaces(path_format);
        const std::string new_root_path{output_path + "/" + path_format};
        const std::string new_image_path{new_root_path + "/" + image_filename};
        images_with_paths[image.image_path] = new_image_path;
    }

    return images_with_paths;
}

std::string MainWindow::get_output_path() {
    if (ui->seperateOutputPathCheckbox->isChecked()) {
        return ui->outputPathEdit->text().toStdString();
    } else {
        return ui->inputPathEdit->text().toStdString();
    }
}

void MainWindow::create_path(const std::string &path) {

    if (!std::filesystem::exists(path)) {
        try {
            std::filesystem::create_directories(path);
        } catch (std::exception &e) {
            throw e;
        }
    }
}

void MainWindow::move_images(const std::map<std::string, std::string> &image_paths) {
    size_t image_counter{0};

    for (const auto &item: image_paths) {
        const std::string source{item.first};
        const std::string destination{item.second};
        const std::string dir_path{std::filesystem::path(destination).parent_path().string()};

        create_path(dir_path);
        std::filesystem::rename(source, destination);
        image_counter += 1;
        ui->progressBar->setValue(image_counter);
    }
}

void MainWindow::process_images() {
    const std::string output_path{get_output_path()};
    const std::vector<ExifData> images{read_images()};
    const std::map<std::string, std::string> image_paths{format_to_path(images, output_path)};
    ui->progressBar->setMaximum(images.size());
    move_images(image_paths);
}

void MainWindow::enable_disable_output_path_edit() {
    const bool seperate_output_path{ui->seperateOutputPathCheckbox->isChecked()};

    ui->outputPathEdit->setEnabled(seperate_output_path);
    ui->outputPathBrowseButton->setEnabled(seperate_output_path);
}

void MainWindow::clicked_input_browse_button() {
    const QString desktop_path{QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)};
    QString dir_path{QFileDialog::getExistingDirectory(this, tr("Open Folder"), desktop_path,
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks)};
    ui->inputPathEdit->setText(dir_path);
}

void MainWindow::clicked_output_browse_button() {
    const QString desktop_path{QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)};
    QString dir_path{QFileDialog::getExistingDirectory(this, tr("Open Folder"), desktop_path,
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks)};
    ui->outputPathEdit->setText(dir_path);
}

void MainWindow::clicked_ok() {
    process_images();
}
