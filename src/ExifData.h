//
// Created by rossw on 11/5/2022.
//

#ifndef PRISM_EXIFDATA_H
#define PRISM_EXIFDATA_H

#include <exiv2/exiv2.hpp>
#include <exiv2/image.hpp>
#include <exiv2/error.hpp>

#include <string>

struct Tags {
    const Exiv2::ExifKey CameraMake = Exiv2::ExifKey("Exif.Image.Make");
    const Exiv2::ExifKey CameraModel = Exiv2::ExifKey("Exif.Image.Model");
    const Exiv2::ExifKey CameraOrientation = Exiv2::ExifKey("Exif.Image.Orientation");
    const Exiv2::ExifKey CameraSerialNumber = Exiv2::ExifKey("Exif.Image.CameraSerialNumber");
    const Exiv2::ExifKey XResolution = Exiv2::ExifKey("Exif.Image.XResolution");
    const Exiv2::ExifKey YResolution = Exiv2::ExifKey("Exif.Image.YResolution");
    const Exiv2::ExifKey ExposureTime = Exiv2::ExifKey("Exif.Image.ExposureTime");
    const Exiv2::ExifKey ISO = Exiv2::ExifKey("Exif.Image.ISOSpeedRatings");
    const Exiv2::ExifKey DateHMS = Exiv2::ExifKey("Exif.Image.DateTimeOriginal");
    const Exiv2::ExifKey ApertureValue = Exiv2::ExifKey("Exif.Image.ApertureValue");
    const Exiv2::ExifKey MeterMode = Exiv2::ExifKey("Exif.Image.MeteringMode");
    const Exiv2::ExifKey ImageNumber = Exiv2::ExifKey("Exif.Image.ImageNumber");
    const Exiv2::ExifKey ExposureMode = Exiv2::ExifKey("Exif.Image.ExposureMode");
    const Exiv2::ExifKey WhiteBalance = Exiv2::ExifKey("Exif.Image.WhiteBalance");
    const Exiv2::ExifKey LensMake = Exiv2::ExifKey("Exif.Image.LensMake");
    const Exiv2::ExifKey LensModel = Exiv2::ExifKey("Exif.Image.LensModel");
    const Exiv2::ExifKey LensSerialNumber = Exiv2::ExifKey("Exif.Image.LensSerialNumber");
};

class ExifData {
public:
    explicit ExifData(const std::string &file_path);

    std::string image_path;

    std::string camera_make() const;

    std::string camera_model() const;

    std::string camera_orientation() const;

    std::string camera_serial_num() const;

    std::string x_resolution() const;

    std::string y_resolution() const;

    std::string exposure_time() const;

    std::string iso() const;

    std::string date_hms() const;

    std::string aperture_value() const;

    std::string meter_mode() const;

    std::string image_number() const;

    std::string exposure_mode() const;

    std::string white_balance() const;

    std::string lens_make() const;

    std::string lens_model() const;

    std::string lens_serial_num() const;

private:
    Tags tags;
    Exiv2::ExifData Data;

    std::string ExifTagValue(const Exiv2::ExifKey &tag) const;
};


#endif //PRISM_EXIFDATA_H
