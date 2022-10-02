# GCMake Test Project

A collection of test cases and working example projects for the
[gcmake-rust](https://github.com/scupit/gcmake-rust) C/C++ project configuration tool.

## Building a Project

**NOTE:** In order to demonstrate the GCMake tool, none of these projects contain CMakeLists.txt files.
This is fine since these are the "test cases" and exist for GCMake demonstration and testing
purposes. However, your project should commit the auto-generated CMakeLists.txt and related
files (cmake/*.cmake and Config.cmake.in) so that consumers can just use your project with CMake
automatically without needing the GCMake tool.

Build steps:

1. Make sure you have installed [gcmake-rust](https://github.com/scupit/gcmake-rust).
2. `cd` into one of these projects (Ex: `cd using-catch2`).
3. Run `gcmake-rust` to generate a full CMake configuration for the project.
4. Build the project as you usually would using CMake.

Some projects (such as *basic-tests* and *emscripten-sdl-imgui*) require a dependency (such as *SDL2*)
which has to be manually built and installed on your system. See the
[gcmake-dependency-configs](https://github.com/scupit/gcmake-dependency-configs) repository for the
list of dependencies which require a manual build and install step, and instructions for each.

## GCMake Repository Links

- [gcmake-rust](https://github.com/scupit/gcmake-rust): The gcmake C/C++ project configuration tool
- [gcmake-test-project](https://github.com/scupit/gcmake-test-project): The 'test case' project for
    gcmake-rust which also acts as its working example.
- [gcmake-dependency-configs](https://github.com/scupit/gcmake-dependency-configs): The
    [dependency compatibility layer](predefined_dependency_doc.md) repository which allows non-gcmake
    projects to be imported and consumed 'out of the box' by gcmake-rust.
