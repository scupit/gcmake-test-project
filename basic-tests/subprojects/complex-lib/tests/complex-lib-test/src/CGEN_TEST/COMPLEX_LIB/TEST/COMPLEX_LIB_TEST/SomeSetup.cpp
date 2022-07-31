
#include "CGEN_TEST/COMPLEX_LIB/ComplexLibHelpers.hpp"

double doTimes4(const double n) noexcept {
  return doubledItem(doubledItem(n));
}