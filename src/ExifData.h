//
// Created by rossw on 11/5/2022.
//

#ifndef PRISM_EXIFDATA_H
#define PRISM_EXIFDATA_H

#include <string>

struct Tags {
    const std::string CameraMake = "Exif.Image.Make";
    const std::string CameraModel = "Exif.Image.Model";
    const std::string CameraOrientation = "Exif.Image.Orientation";
    const std::string CameraSerialNumber = "Exif.Image.CameraSerialNumber";
    const std::string XResolution = "Exif.Image.XResolution";
    const std::string YResolution = "Exif.Image.YResolution";
    const std::string ExposureTime = "Exif.Image.ExposureTime";
    const std::string ISO = "Exif.Image.ISOSpeedRatings";
    const std::string DateHMS = "Exif.Image.DateTimeOriginal";
    const std::string ApertureValue = "Exif.Image.ApertureValue";
    const std::string MeterMode = "Exif.Image.MeteringMode";
    const std::string ImageNumber = "Exif.Image.ImageNumber";
    const std::string ExposureMode = "Exif.Image.ExposureMode";
    const std::string WhiteBalance = "Exif.Image.WhiteBalance";
    const std::string LensMake = "Exif.Image.LensMake";
    const std::string LensModel = "Exif.Image.LensModel";
    const std::string LensSerialNumber = "Exif.Image.LensSerialNumber";
};

class ExifData {
public:
    explicit ExifData(const std::string &file_path);

    std::string camera_make();

    std::string camera_model();

    std::string camera_orientation();

    std::string camera_serial_num();

    std::string x_resolution();

    std::string y_resolution();

    std::string exposure_time();

    std::string iso();

    std::string date_hms();

    std::string aperture_value();

    std::string meter_mode();

    std::string image_number();

    std::string exposure_mode();

    std::string white_balance();

    std::string lens_make();

    std::string lens_model();

    std::string lens_serial_num();

private:
    Tags tags;
    Exiv2::ExifData Data;
};


#endif //PRISM_EXIFDATA_H
