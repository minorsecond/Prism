//
// Created by rossw on 11/5/2022.
//

#ifndef PRISM_EXIFDATA_H
#define PRISM_EXIFDATA_H

#include <exiv2/exiv2.hpp>
#include <exiv2/image.hpp>
#include <exiv2/error.hpp>
#include <string>

#include "exif_tags.h"

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
    Exiv2::ExifData Data{};

    std::string ExifTagValue(const Exiv2::ExifKey &tag) const;
};


#endif //PRISM_EXIFDATA_H
