// fileio.hh
// T. M. Kelley
// Jun 24, 2011
// (c) Copyright 2011 LANSLLC, all rights reserved

#ifndef FILEIO_HH
#define FILEIO_HH

#include "types.hh"
#include <istream>
#include <sstream>
#include <vector>
#include <stdint.h>

namespace nut {
template <typename fp_t, typename vector_t>
struct MatStateRowP {
  uint32_t zone;
  fp_t m_encl;
  fp_t radius;
  fp_t density;
  vector_t velocity;

  fp_t ye;
  fp_t eta;
  fp_t temperature;
  fp_t entropy;
  fp_t u;

  fp_t lnue_capture;
  fp_t enue_capture;
  fp_t lnueb_capture;
  fp_t enueb_capture;
  fp_t lnue_pair;

  fp_t enue_pair;
  fp_t lnueb_pair;
  fp_t enueb_pair;
  fp_t lnux_pair;
  fp_t enux_pair;

  bool operator==(MatStateRowP<fp_t, vector_t> const & a) const
  {
    return zone == a.zone && m_encl == a.m_encl && radius == a.radius &&
           density == a.density && velocity == a.velocity &&

           ye == a.ye && eta == a.eta && temperature == a.temperature &&
           entropy == a.entropy && u == a.u &&

           lnue_capture == a.lnue_capture && enue_capture == a.enue_capture &&
           lnueb_capture == a.lnueb_capture &&
           enueb_capture == a.enueb_capture && lnue_pair == a.lnue_pair &&

           enue_pair == a.enue_pair && lnueb_pair == a.lnueb_pair &&
           enueb_pair == a.enueb_pair && lnux_pair == a.lnux_pair &&
           enux_pair == a.enux_pair;
  }  // operator==

};  // MatStateRowP

/*!\brief read a material state file into a vector of structures,
 * one structure per line. Conversion from string to number is
 * performed, but that's it. */
template <typename fp_t, typename vector_t>
std::vector<MatStateRowP<fp_t, vector_t> >
read_mat_state_file(std::istream & i);

/*!\brief convert a line (string) to a MatStateRowP */
template <typename fp_t, typename vector_t>
MatStateRowP<fp_t, vector_t>
line_to_struct(std::string const & l);

template <typename fp_t, typename vector_t>
std::vector<MatStateRowP<fp_t, vector_t> >
read_mat_state_file(std::istream & i)
{
  std::vector<MatStateRowP<fp_t, vector_t> > v;
  v.reserve(2700);
  while(!i.eof()) {
    std::string line;
    std::getline(i, line);
    if(line != "") {
      MatStateRowP<fp_t, vector_t> row = line_to_struct<fp_t, vector_t>(line);
      v.push_back(row);
    }
  }
  return v;
}  // read_mat_state_file

template <typename fp_t, typename vector_t>
MatStateRowP<fp_t, vector_t>
line_to_struct(std::string const & l)
{
  size_t dim = {vector_t::dim};
  MatStateRowP<fp_t, vector_t> row;
  std::stringstream sstr(l);
  sstr >> row.zone >> row.m_encl >> row.radius >> row.density;
  for(uint32_t d = 0; d < dim; ++d) { sstr >> row.velocity[d]; }
  sstr >> row.ye >> row.eta >> row.temperature >> row.entropy >> row.u >>
      row.lnue_capture >> row.enue_capture >> row.lnueb_capture >>
      row.enueb_capture >> row.lnue_pair >> row.enue_pair >> row.lnueb_pair >>
      row.enueb_pair >> row.lnux_pair >> row.enux_pair;

  return row;
}  // line_to_struct

}  // namespace nut

#endif  // include guard

// version
// $Id$

// End of file
