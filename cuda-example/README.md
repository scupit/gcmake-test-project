# CUDA Basic Example

This example project demonstrates basic [CUDA](https://developer.nvidia.com/cuda-toolkit) usage
with [GCMake](https://github.com/scupit/gcmake-rust).

## Building

This project can be built with or without CUDA. To build with CUDA support, make sure
you have a working CUDA install on your system and set the
cache variable `GCMAKE_ENABLE_CUDA` to `ON` or some other truthy value.

Example command line configuration:

``` sh
cmake -S . -B build -DGCMAKE_ENABLE_CUDA=ON
cmake --build build -j10
```
