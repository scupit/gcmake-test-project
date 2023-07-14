#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

void printClockDiff(const char name[], clock_t* start, clock_t* end);

inline int transformNum(int n) {
  return (n * 2) + 1;
}

int main(void) {
  const size_t size = 1024 * 1024 * 1024;
  int* const data = (int*) malloc(size * sizeof(int));

  clock_t beginParallel = clock();

  #pragma omp parallel for
  for (size_t i = 0; i < size; ++i) {
    data[i] = transformNum((int) i);
  }
  clock_t endParallel = clock();
  printClockDiff("Parallel", &beginParallel, &endParallel);

  int* const otherData = (int*) malloc(size * sizeof(int));

  clock_t beginSerial = clock();
  for (size_t i = 0; i < size; ++i) {
    otherData[i] = transformNum((int) i);
  }
  clock_t endSerial = clock();
  printClockDiff("Serial", &beginSerial, &endSerial);

	return EXIT_SUCCESS;
}

void printClockDiff(const char name[], clock_t* start, clock_t* end) {
  double cpuTimeUsedSeconds = (double)(*end - *start) / CLOCKS_PER_SEC;
  printf("(%s) took %f seconds\n", name, cpuTimeUsedSeconds);
}