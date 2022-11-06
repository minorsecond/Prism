//
// Created by rossw on 11/5/2022.
//

#include <exiv2/image.hpp>
#include <iostream>
#include <math.h>

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
    return ExifTagValue(Tags::ExposureMode) + "s";
}

std::string ExifData::iso() const {
    return ExifTagValue(Tags::ISO);
}

std::string ExifData::date_hms() const {
    return ExifTagValue(Tags::DateHMS);
}

std::string ExifData::aperture_value() const {
    const std::string value{ExifTagValue(Tags::ApertureValue)};
    const std::vector<std::string> split_value{split_string(value)};
    const double numerator{std::stod(split_value[0])};
    const double denominator{std::stod(split_value[1])};
    const double f_value{(numerator / denominator)};
    const double rounded{static_cast<float>(static_cast<int>(f_value * 10.)) / 10.};
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << rounded;
    return "f" + stream.str();
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
    std::unique_ptr<Exiv2::Value> v{Exiv2::Value::create(Exiv2::asciiString)};
    auto pos{Data.findKey(tag)};
    if (pos == Data.end()) {
        return "Unknown(" + tag.tagName() + ")";
    };
    try {
        const std::string val{pos->value().toString()};
        if (val.empty()) {
            return "Unknown(" + tag.tagName() + ")";
        } else {
            return pos->value().toString();
        }
    } catch (std::exception &e) {
        return "Unknown(" + tag.tagName() + ")";
    }
}

std::vector<std::string> ExifData::split_string(std::string in_string) {
    std::vector<std::string> result;
    std::string current;

    for (int i{0}; i < in_string.size(); i++) {
        if (in_string[i] == '/') {
            if (!current.empty()) {
                result.push_back(current);
                current = "";
            }
            continue;
        }
        current += in_string[i];
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}
