//
// Created by rossw on 11/5/2022.
//

#include <exiv2/image.hpp>

#include "ExifData.h"

ExifData::ExifData(const std::string &file_path) {
    std::unique_ptr<Exiv2::Image> image{Exiv2::ImageFactory::open(file_path)};
    image->readMetadata();

    if (!image->exifData().empty()) {
        this->Data = image->exifData();
        image_path = file_path;
    } else {
        const std::string error{"No exif data found in file"};
        throw Exiv2::Error(Exiv2::kerErrorMessage, error);
    }
}

std::string ExifData::camera_make() const {
    return ExifTagValue(Tags::CameraMake);
}

std::string ExifData::camera_model() const {
    return ExifTagValue(Tags::CameraModel);
}

std::string ExifData::camera_orientation() const {
    return ExifTagValue(Tags::CameraOrientation);
}

std::string ExifData::camera_serial_num() const {
    return ExifTagValue(Tags::CameraSerialNumber);
}

std::string ExifData::x_resolution() const {
    return ExifTagValue(Tags::XResolution);
}

std::string ExifData::y_resolution() const {
    return ExifTagValue(Tags::YResolution);
}

std::string ExifData::exposure_time() const {
    return ExifTagValue(Tags::ExposureMode);
}

std::string ExifData::iso() const {
    return ExifTagValue(Tags::ISO);
}

std::string ExifData::date_hms() const {
    return ExifTagValue(Tags::DateHMS);
}

std::string ExifData::aperture_value() const {
    return ExifTagValue(Tags::ApertureValue);
}

std::string ExifData::meter_mode() const {
    return ExifTagValue(Tags::MeterMode);
}

std::string ExifData::image_number() const {
    return ExifTagValue(Tags::ImageNumber);
}

std::string ExifData::exposure_mode() const {
    return ExifTagValue(Tags::ExposureMode);
}

std::string ExifData::white_balance() const {
    return ExifTagValue(Tags::WhiteBalance);
}

std::string ExifData::lens_make() const {
    return ExifTagValue(Tags::LensMake);
}

std::string ExifData::lens_model() const {
    return ExifTagValue(Tags::LensModel);
}

std::string ExifData::lens_serial_num() const {
    return ExifTagValue(Tags::LensSerialNumber);
}

std::string ExifData::ExifTagValue(const Exiv2::ExifKey &tag) const {
    const auto pos{Data.findKey(tag)};
    const std::unique_ptr<Exiv2::Value> val{pos->getValue()};
    return val->toString();
}
