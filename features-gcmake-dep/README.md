# Dependency Features Example Project

This project is an example of using a GCMake dependency which defines "features".

## Initial Build

The initial build of this project should be done in three steps:

1. Run `gcmake-rust` on this project.
2. Configure and Generate a CMake build. **The build will fail, but will still clone the GCMake dependency project. This is expected.**
3. Run `gcmake-rust` on this project again. This time it will generate the correct CMakeLists using actual project information from the cloned GCMake dependency.

### Why does the first configuration (step 2) fail?

Before the [basic-features](../basic-features/) GCMake dependency project (imported as `features-lib` in our
[cmake_data.yaml](./cmake_data.yaml)) is cloned, GCMake has no way of knowing its actual CMake project
name or other internal configuration details. The tool does its best to guess, but will generally
get that information wrong. However, it is still able to write a correct FetchContent 'clone' configuration
in the CMakeLists.txt. *Step 2* runs the CMakeLists until the GCMake dependency is cloned correctly, at
which point the build fails due to nonexistent targets and other such incorrect info caused by the reason just
described. However, at that point the dependency project has been fully cloned succesfully (probably).
*Step 3* reconfigures the whole project tree just like step 1, but no longer needs to guess the
GCMake dependency project info since the dependency is fully available.

That is also part of the reason why GCMake configuration outputs (CMakeLists.txt, Config.cmake.in,
install-deb-development-packages.sh, cmake/, etc.) should be committed into source control. An existing
CMakeLists file would allow dependency projects to be automatically recursively cloned, while a missing
CMakeLists file might result in the builder having to do these additional build steps for every dependency
level. That would be a huge pain.
