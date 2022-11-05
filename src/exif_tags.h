//
// Created by rossw on 11/5/2022.
//

#ifndef PRISM_EXIF_TAGS_H
#define PRISM_EXIF_TAGS_H

#include <exiv2/exiv2.hpp>

struct Tags {
    static inline const Exiv2::ExifKey CameraMake = Exiv2::ExifKey("Exif.Image.Make");
    static inline const Exiv2::ExifKey CameraModel = Exiv2::ExifKey("Exif.Image.Model");
    static inline const Exiv2::ExifKey CameraOrientation = Exiv2::ExifKey("Exif.Image.Orientation");
    static inline const Exiv2::ExifKey CameraSerialNumber = Exiv2::ExifKey("Exif.Image.CameraSerialNumber");
    static inline const Exiv2::ExifKey XResolution = Exiv2::ExifKey("Exif.Image.XResolution");
    static inline const Exiv2::ExifKey YResolution = Exiv2::ExifKey("Exif.Image.YResolution");
    static inline const Exiv2::ExifKey ExposureTime = Exiv2::ExifKey("Exif.Image.ExposureTime");
    static inline const Exiv2::ExifKey ISO = Exiv2::ExifKey("Exif.Image.ISOSpeedRatings");
    static inline const Exiv2::ExifKey DateHMS = Exiv2::ExifKey("Exif.Image.DateTimeOriginal");
    static inline const Exiv2::ExifKey ApertureValue = Exiv2::ExifKey("Exif.Image.ApertureValue");
    static inline const Exiv2::ExifKey MeterMode = Exiv2::ExifKey("Exif.Image.MeteringMode");
    static inline const Exiv2::ExifKey ImageNumber = Exiv2::ExifKey("Exif.Image.ImageNumber");
    static inline const Exiv2::ExifKey ExposureMode = Exiv2::ExifKey("Exif.Photo.ExposureMode");
    static inline const Exiv2::ExifKey WhiteBalance = Exiv2::ExifKey("Exif.Photo.WhiteBalance");
    static inline const Exiv2::ExifKey LensMake = Exiv2::ExifKey("Exif.Photo.LensMake");
    static inline const Exiv2::ExifKey LensModel = Exiv2::ExifKey("Exif.Photo.LensModel");
    static inline const Exiv2::ExifKey LensSerialNumber = Exiv2::ExifKey("Exif.Photo.LensSerialNumber");
};

#endif //PRISM_EXIF_TAGS_H
