#ifndef PRIVATE_HEADERS_EXAMPLE_HPP
#define PRIVATE_HEADERS_EXAMPLE_HPP

#include "CGEN_TEST/PRIVATE_HEADERS_EXAMPLE/SomeClass.hpp"

// When uncommented, this will work fine when the library is compiled. However, it will
// fail with an error when this entry file is included by some other project because
// the "src/..." directory is private. Private headers cannot be #included by consumers,
// and this counts as a "transitive #include".
// #include "CGEN_TEST/PRIVATE_HEADERS_EXAMPLE/ImplHelper.private.hpp"

#endif
