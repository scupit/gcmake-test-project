#include "CUDA_EXAMPLE/Helper.hpp"

#include <iostream>
#include <thrust/device_vector.h>

__global__ void addVecKernel(float *A, float *B, float* C) {
  int i = threadIdx.x;
  C[i] = A[i] + B[i];
}

// Assumes xs and ys are the same length
std::vector<float> addVec(const std::vector<float>& xs, const std::vector<float>& ys) {
  std::cout << "Using CUDA to add vectors...\n";
  std::vector<float> result;
  const auto size = xs.size();
  result.reserve(size);

  thrust::device_vector<float> A(xs.begin(), xs.end());
  thrust::device_vector<float> B(ys.begin(), ys.end());

  thrust::device_vector<float> C(size);

  addVecKernel<<<1, size>>>(
    thrust::raw_pointer_cast(A.data()),
    thrust::raw_pointer_cast(B.data()),
    thrust::raw_pointer_cast(C.data())
  );

  thrust::copy(C.begin(), C.end(), std::back_inserter(result));
  return result;
}
          
