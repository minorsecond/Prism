//
// Created by rossw on 11/4/2022.
//

#ifndef PRISM_MAINWINDOW_H
#define PRISM_MAINWINDOW_H

#include <vector>
#include <QtWidgets/QMainWindow>

#include "../gui/ui_mainwindow.h"
#include "ExifData.h"
#include "exif_tags.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override = default;

private:
    Ui::MainWindow *ui;

    void populate_attribute_picker();

    std::string regex_finder(const std::string &in_string);

    void get_input_directory();

    void get_output_directory();

    std::vector<Exiv2::ExifKey> get_attributes();

    std::vector<ExifData> read_images();

    void add_attribute();

    std::string replace_whitespaces(std::string in_string);

    std::map<std::string, std::string>
    format_paths(const std::vector<ExifData> &images, const std::string &output_path);

    std::string get_output_path();

    std::map<std::string, Exiv2::ExifKey> exif_attributes{
            {"Camera Make {cmake}",                            Tags::CameraMake},
            {"Camera Model {cmodel}",                          Tags::CameraModel},
            {"Camera Orientation {corient}",                   Tags::CameraOrientation},
            {"Image X Resolution {xres}",                      Tags::XResolution},
            {"Image Y Resolution {yres}",                      Tags::YResolution},
            {"Exposure Time {etime}",                          Tags::ExposureTime},
            {"ISO {iso}",                                      Tags::ISO},
            {"Date & Time Created (YYYY-MM-DD HH-MM) {dtime}", Tags::DateHMS},
            //"Date & Time Created (YYYY-MM-DD HH-MM-SS) {dtimes}": "Exif.Photo.DateTimeOriginal",
            {"Aperture Value {aperval}",                       Tags::ApertureValue},
            {"Metering Mode {meter}",                          Tags::MeterMode},
            {"Image Number {inum}",                            Tags::ImageNumber},
            {"Exposure Mode {exmode}",                         Tags::ExposureMode},
            {"White Balance Mode {wb}",                        Tags::WhiteBalance},
            {"Camera Serial Number {cserial}",                 Tags::CameraSerialNumber},
            {"Lens Make {lmake}",                              Tags::LensMake},
            {"Lens Model {lmodel}",                            Tags::LensModel},
            {"Lens Serial Number {lserial}",                   Tags::LensSerialNumber}
    };
};


#endif //PRISM_MAINWINDOW_H
