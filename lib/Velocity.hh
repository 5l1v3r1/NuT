// Velocity.hh
// T. M. Kelley
// Jun 15, 2011
// (c) Copyright 2011 LANSLLC, all rights reserved

#ifndef VELOCITY_HH
#define VELOCITY_HH

#include "Assert.hh"
#include "types.hh"
#include <vector>

namespace nut {
template <typename geo_t, typename vector_t>
struct Velocity {
  typedef std::vector<vector_t> vec_vec;

  vec_vec vs;

  explicit Velocity(vec_vec const & vs_) : vs(vs_) {}

  explicit Velocity(size_t const sz) : vs(sz) {}

  vector_t const & v(cell_t const cidx) const
  {
    cellOK(cidx);
    return vs.at(cidx - 1);
  }

  vector_t & v(cell_t const cidx)
  {
    cellOK(cidx);
    return vs.at(cidx - 1);
  }

  cell_t n_cell() const { return vs.size(); }

  size_t size() const { return vs.size(); }

private:
  void cellOK(cell_t const cell_idx) const
  {
    nut::InOpenRange(cell_idx, cell_t(0), cell_t(this->n_cell() + 1),
                     "cell id");
  }

};  // Velocity

template <typename vector_t>
struct vel_t {
  vector_t v;
};
}  // namespace nut

#endif  // include guard

// version
// $Id$

// End of file
