#ifndef T_IMPL_H_COMPLEX_LIB_NOICE
#define T_IMPL_H_COMPLEX_LIB_NOICE

#include <iostream>

template <typename T>
void Noice<T>::printName() {
  std::cout << T() << '\n';
}

#endif
