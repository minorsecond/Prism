//
// Created by rossw on 11/5/2022.
//

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
    return ExifTagValue(tags.CameraMake);
}

std::string ExifData::camera_model() {
    return ExifTagValue(tags.CameraModel);
}

std::string ExifData::camera_orientation() {
    return ExifTagValue(tags.CameraOrientation);
}

std::string ExifData::camera_serial_num() {
    return ExifTagValue(tags.CameraSerialNumber);
}

std::string ExifData::x_resolution() {
    return ExifTagValue(tags.XResolution);
}

std::string ExifData::y_resolution() {
    return ExifTagValue(tags.YResolution);
}

std::string ExifData::exposure_time() {
    return ExifTagValue(tags.ExposureMode);
}

std::string ExifData::iso() {
    return ExifTagValue(tags.ISO);
}

std::string ExifData::date_hms() {
    return ExifTagValue(tags.DateHMS);
}

std::string ExifData::aperture_value() {
    return ExifTagValue(tags.ApertureValue);
}

std::string ExifData::meter_mode() {
    return ExifTagValue(tags.MeterMode);
}

std::string ExifData::image_number() {
    return ExifTagValue(tags.ImageNumber);
}

std::string ExifData::exposure_mode() {
    return ExifTagValue(tags.ExposureMode);
}

std::string ExifData::white_balance() {
    return ExifTagValue(tags.WhiteBalance);
}

std::string ExifData::lens_make() {
    return ExifTagValue(tags.LensMake);
}

std::string ExifData::lens_model() {
    return ExifTagValue(tags.LensModel);
}

std::string ExifData::lens_serial_num() {
    return ExifTagValue(tags.LensSerialNumber);
}

std::string ExifData::ExifTagValue(const Exiv2::ExifKey &tag) {
    const Exiv2::ExifData::iterator pos{Data.findKey(tag)};
    const std::unique_ptr<Exiv2::Value> val{pos->getValue()};
    return val->toString();
}
