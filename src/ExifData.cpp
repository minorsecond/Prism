//
// Created by rossw on 11/5/2022.
//
#include <exiv2/image.hpp>
#include <exiv2/error.hpp>
#include <exiv2/easyaccess.hpp>

#include "ExifData.h"

ExifData::ExifData(const std::string &file_path) {
    std::unique_ptr<Exiv2::Image> image{Exiv2::ImageFactory::open(file_path)};
    image->readMetadata();

    if (!image->exifData().empty()) {
        this->Data = image->exifData();
    } else {
        const std::string error{"No exif data found in file"};
        throw Exiv2::Error(Exiv2::kerErrorMessage, error);
    }
}

std::string ExifData::camera_make() {
    return this->Data.findKey(Exiv2::ExifKey(tags.CameraMake))->getValue()->toString();
}

std::string ExifData::camera_model() {
    return this->Data.findKey(Exiv2::ExifKey(tags.CameraModel))->getValue()->toString();
}

std::string ExifData::camera_orientation() {
    return this->Data.findKey(Exiv2::ExifKey(tags.CameraOrientation))->getValue()->toString();
}

std::string ExifData::camera_serial_num() {
    return this->Data.findKey(Exiv2::ExifKey(tags.CameraSerialNumber))->getValue()->toString();
}

std::string ExifData::x_resolution() {
    return this->Data.findKey(Exiv2::ExifKey(tags.XResolution))->getValue()->toString();
}

std::string ExifData::y_resolution() {
    return this->Data.findKey(Exiv2::ExifKey(tags.YResolution))->getValue()->toString();
}

std::string ExifData::exposure_time() {
    return this->Data.findKey(Exiv2::ExifKey(tags.ExposureMode))->getValue()->toString();
}

std::string ExifData::iso() {
    return this->Data.findKey(Exiv2::ExifKey(tags.ISO))->getValue()->toString();
}

std::string ExifData::date_hms() {
    return this->Data.findKey(Exiv2::ExifKey(tags.DateHMS))->getValue()->toString();
}

std::string ExifData::aperture_value() {
    return this->Data.findKey(Exiv2::ExifKey(tags.ApertureValue))->getValue()->toString();
}

std::string ExifData::meter_mode() {
    return this->Data.findKey(Exiv2::ExifKey(tags.MeterMode))->getValue()->toString();
}

std::string ExifData::image_number() {
    return this->Data.findKey(Exiv2::ExifKey(tags.ImageNumber))->getValue()->toString();
}

std::string ExifData::exposure_mode() {
    return this->Data.findKey(Exiv2::ExifKey(tags.ExposureMode))->getValue()->toString();
}

std::string ExifData::white_balance() {
    return this->Data.findKey(Exiv2::ExifKey(tags.WhiteBalance))->getValue()->toString();
}

std::string ExifData::lens_make() {
    return this->Data.findKey(Exiv2::ExifKey(tags.LensMake))->getValue()->toString();
}

std::string ExifData::lens_model() {
    return this->Data.findKey(Exiv2::ExifKey(tags.LensModel))->getValue()->toString();
}

std::string ExifData::lens_serial_num() {
    return this->Data.findKey(Exiv2::ExifKey(tags.LensSerialNumber))->getValue()->toString();
}
