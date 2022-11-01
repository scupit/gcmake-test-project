#include <iostream>

#if USING_THE_FEATURES_LIB
  #include "FEATURES_BASIC/features-lib.hpp"
#endif

int main() {
  #if USING_THE_FEATURES_LIB
    // Prints the gcmake depenendcy's enabled features.
    printEnabledFeatures();
  #else
    std::cout << "The features library is turned off." << std::endl;
  #endif

	return EXIT_SUCCESS;
}
