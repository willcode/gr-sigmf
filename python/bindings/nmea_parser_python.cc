/*
 * Copyright 2021 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(nmea_parser.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(2e6cd04ac2be28662dddf7cd03b48fe4)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <sigmf/nmea_parser.h>

void bind_nmea_parser(py::module& m)
{
    using nmea_message    = ::gr::sigmf::nmea_message;
    using gprmc_message    = ::gr::sigmf::gprmc_message;
    using gpgga_message    = ::gr::sigmf::gpgga_message;

    py::class_<nmea_message,
        std::shared_ptr<nmea_message>>(m, "nmea_message")
        .def(py::init<gr::sigmf::nmea_message const &>(), py::arg("arg0"))
        .def(py::init<>())
        ;

    py::class_<gprmc_message, gr::sigmf::nmea_message,
        std::shared_ptr<gprmc_message>>(m, "gprmc_message")
        .def(py::init<uint32_t,std::string,std::string,bool,double,double,double,double,double>(),
            py::arg("timestamp"),
            py::arg("date"),
            py::arg("time"),
            py::arg("valid"),
            py::arg("lat"),
            py::arg("lon"),
            py::arg("speed_knots"),
            py::arg("track_angle"),
            py::arg("magnetic_variation")
        )
        .def(py::init<gr::sigmf::gprmc_message const &>(), py::arg("arg0"))
        .def_static("parse", &gprmc_message::parse, py::arg("raw"))
        .def_readwrite("timestamp", &gprmc_message::timestamp)
        .def_readwrite("date", &gprmc_message::date)
        .def_readwrite("time", &gprmc_message::time)
        .def_readwrite("valid", &gprmc_message::valid)
        .def_readwrite("lat", &gprmc_message::lat)
        .def_readwrite("lon", &gprmc_message::lon)
        .def_readwrite("speed_knots", &gprmc_message::speed_knots)
        .def_readwrite("track_angle", &gprmc_message::track_angle)
        .def_readwrite("magnetic_variation", &gprmc_message::magnetic_variation)
        ;

    py::class_<gpgga_message, gr::sigmf::nmea_message,
        std::shared_ptr<gpgga_message>>(m, "gpgga_message")

        .def(py::init<std::string,double,double,uint32_t,uint32_t,double,double,double>(),
            py::arg("time"),
            py::arg("lat"),
            py::arg("lon"),
            py::arg("fix_quality"),
            py::arg("num_sats"),
            py::arg("hdop"),
            py::arg("altitude_msl"),
            py::arg("geoid_hae")
            )
        .def(py::init<gr::sigmf::gpgga_message const &>(), py::arg("arg0"))
        .def_static("parse", &gpgga_message::parse, py::arg("raw"))
        .def_readwrite("time", &gpgga_message::time)
        .def_readwrite("lat", &gpgga_message::lat)
        .def_readwrite("lon", &gpgga_message::lon)
        .def_readwrite("fix_quality", &gpgga_message::fix_quality)
        .def_readwrite("num_sats", &gpgga_message::num_sats)
        .def_readwrite("hdop", &gpgga_message::hdop)
        .def_readwrite("altitude_msl", &gpgga_message::altitude_msl)
        .def_readwrite("geoid_hae", &gpgga_message::geoid_hae)
        ;

        m.def("nmea_split", &::gr::sigmf::nmea_split, py::arg("s"));
        m.def("nmea_extract", &::gr::sigmf::nmea_extract, py::arg("raw"));
        m.def("nmea_parse_degrees", &::gr::sigmf::nmea_parse_degrees,
            py::arg("value"),
            py::arg("dir")
        );

        m.def("nmea_parse_magnetic_variation", &::gr::sigmf::nmea_parse_magnetic_variation,
            py::arg("value"),
            py::arg("dir")
        );

        m.def("nmea_parse_datetime", &::gr::sigmf::nmea_parse_datetime,
            py::arg("date"),
            py::arg("time")
        );
}
