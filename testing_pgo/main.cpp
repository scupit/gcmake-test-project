#include "inner-lib.hpp"
#include "inner-static.hpp"

int main() {
  echoFromInnerLib("Echoing from inner lib");
  anotherInnerLibPrint("Echoing from inner lib");
  printFromInnerStatic("Printing from inner static");

	return 0;
}
