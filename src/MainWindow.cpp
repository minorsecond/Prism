//
// Created by rossw on 11/4/2022.
//

#include <QFileDialog>
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

std::vector<std::string> MainWindow::get_attributes() {
    std::vector<std::string> attributes_to_get{};
    const std::string filename_structure{ui->pathFormatLineEdit->text().toStdString()};
    std::smatch selected_attributes{regex_finder(filename_structure)};

    for (const auto &item: exif_attributes) {
        const std::string name{item.first};
        const std::string exif_tag{item.second};
        std::string result{};
        std::smatch tag_abbrev{regex_finder(name)};

        //for (std::string attribute : selected_attributes) {
        //    if (tag_abbrev == attribute) {
        //        attributes_to_get.push_back(exif_tag);
        //    }
        //}
    }

    return attributes_to_get;
}

std::smatch MainWindow::regex_finder(const std::string &in_string) {
    const std::regex pattern{"{(.*?)}"};
    std::smatch m{};
    std::regex_search(in_string, m, pattern);

    return m;
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
            if (entry.path().extension() == ext) {
                ExifData data(input_path);
                images.push_back(data);
            }
        }
    }

    return images;
}

void MainWindow::add_attribute() {
    const std::string chosen_attribute{regex_finder(ui->attributeSelectorInput->currentText().toStdString()).str()};
    const std::string filename_format_text{ui->pathFormatLineEdit->text().toStdString() + chosen_attribute};
    ui->pathFormatLineEdit->setText(QString::fromStdString(filename_format_text));
}

std::string MainWindow::replace_whitespaces(std::string in_string) {
    const char whitespace_replacement{ui->whiteSpaceReplacementSelector->currentText().toStdString()[0]};
    std::replace(in_string.begin(), in_string.end(), ' ', whitespace_replacement);

    return in_string;
}

std::map<std::string, std::string> MainWindow::format_paths(const std::vector<ExifData> &images,
                                                            const std::string &output_path) {
    std::map<std::string, std::string> images_with_paths{};

    for (const ExifData &image: images) {
        const std::string image_filename{image.image_path};

        //test = std::regex_replace(test, std::regex("def"), "klm");
        std::string path_format{ui->pathFormatLineEdit->text().toStdString()};
        path_format = std::regex_replace(path_format, std::regex("{cmake}"), image.camera_make());
        path_format = std::regex_replace(path_format, std::regex("{cmodel}"), image.camera_model());
        path_format = std::regex_replace(path_format, std::regex("{cserial}"), image.camera_serial_num());
        path_format = std::regex_replace(path_format, std::regex("{corient}"), image.camera_orientation());
        path_format = std::regex_replace(path_format, std::regex("{xres}"), image.x_resolution());
        path_format = std::regex_replace(path_format, std::regex("{yres}"), image.y_resolution());
        path_format = std::regex_replace(path_format, std::regex("{etimes}"), image.exposure_time());
        path_format = std::regex_replace(path_format, std::regex("{iso}"), image.iso());
        path_format = std::regex_replace(path_format, std::regex("{dtime}"), image.date_hms());
        path_format = std::regex_replace(path_format, std::regex("{aperval}"), image.aperture_value());
        path_format = std::regex_replace(path_format, std::regex("{meter}"), image.meter_mode());
        path_format = std::regex_replace(path_format, std::regex("{inum}"), image.image_number());
        path_format = std::regex_replace(path_format, std::regex("{xmode}"), image.exposure_mode());
        path_format = std::regex_replace(path_format, std::regex("{wb}"), image.white_balance());
        path_format = std::regex_replace(path_format, std::regex("{lmake}"), image.lens_make());
        path_format = std::regex_replace(path_format, std::regex("{lmodel}"), image.lens_model());
        path_format = std::regex_replace(path_format, std::regex("{lserial}"), image.lens_serial_num());

        path_format = replace_whitespaces(path_format);
        const std::string new_root_path{output_path + path_format};
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
