//
// Created by rossw on 11/4/2022.
//

#ifndef PRISM_MAINWINDOW_H
#define PRISM_MAINWINDOW_H

#include <vector>

#include <QtWidgets/QMainWindow>
#include "../gui/ui_mainwindow.h"
#include "ExifData.h"


class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override = default;

private:
    Ui::MainWindow *ui;

    void populate_attribute_picker();

    std::smatch regex_finder(const std::string &in_string);

    void get_input_directory();

    void get_output_directory();

    std::vector<std::string> get_attributes();

    std::vector<ExifData> read_images();

    void add_attribute();

    std::string replace_whitespaces(std::string in_string);

    std::map<std::string, std::string>
    format_paths(const std::vector<ExifData> &images, const std::string &output_path);

    std::string get_output_path();

    std::map<std::string, std::string> exif_attributes{
            {"Camera Make {cmake}",                            "Exif.Image.Make"},
            {"Camera Model {cmodel}",                          "Exif.Image.Model"},
            {"Camera Orientation {corient}",                   "Exif.Image.Orientation"},
            {"Image X Resolution {xres}",                      "Exif.Photo.FocalPlaneXResolution"},
            {"Image Y Resolution {yres}",                      "Exif.Photo.FocalPlaneYResolution"},
            {"Exposure Time {etime}",                          "Exif.Photo.ExposureTime"},
            {"ISO {iso}",                                      "Exif.Photo.ISOSpeedRatings"},
            {"Date & Time Created (YYYY-MM-DD HH-MM) {dtime}", "Exif.Photo.DateTimeOriginal"},
            //"Date & Time Created (YYYY-MM-DD HH-MM-SS) {dtimes}": "Exif.Photo.DateTimeOriginal",
            {"Aperture Value {aperval}",                       "Exif.Photo.ApertureValue"},
            {"Metering Mode {meter}",                          "Exif.Photo.MeteringMode"},
            {"Image Number {inum}",                            "Exif.Image.ImageNumber"},
            {"Exposure Mode {exmode}",                         "Exif.Photo.ExposureMode"},
            {"White Balance Mode {wb}",                        "Exif.Photo.WhiteBalance"},
            {"Camera Serial Number {cserial}",                 "Exif.Photo.BodySerialNumber"},
            {"Lens Make {lmake}",                              "Exif.Photo.LensMake"},
            {"Lens Model {lmodel}",                            "Exif.Photo.LensModel"},
            {"Lens Serial Number {lserial}",                   "Exif.Photo.LensSerialNumber"}
    };
};


#endif //PRISM_MAINWINDOW_H
