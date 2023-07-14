#include <iostream>

#include "Kokkos_core.hpp"
#include "Kokkos_StdAlgorithms.hpp"

void doWork();

int main(int argc, char** argv) {
  Kokkos::initialize(argc, argv);
  doWork();
  Kokkos::finalize();
	return EXIT_SUCCESS;
}

void doWork() {
  const size_t N = 1024;
  Kokkos::View<double*> items ("x", N);

  for (size_t i = 0; i < N; ++i) {
    items[i] = static_cast<double>(i);
  }

  const auto [minItem, maxItem] = Kokkos::Experimental::minmax_element(
    Kokkos::DefaultExecutionSpace(),
    items
  );

  std::cout
    << "Min item: " << *minItem
    << "\nMax item: " << *maxItem
    << '\n';

  double sum = 0;
  Kokkos::parallel_reduce("Parallel Reduction", N, KOKKOS_LAMBDA (const size_t i, double& update) {
    update += items(i);
  }, sum);

  std::cout
    << "Sum: " << sum
    << "\n(should be " << (N / 2) * (0 + N-1) << ")\n";
}