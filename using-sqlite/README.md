# SQLite Test Project

This is an example SQLite project, which also acts as a test for the URL dependency download method.

## Running the executable

When running the built `using-sqlite.exe`, make sure your working directory is either the project root
(which contains *cmake_data.yaml*) or the binary directory (i.e. *build/bin/Debug*). The program will
fail to open an SQLITE database if the current working directory doesn't contain the
*resources/USING_SQLITE* directory.
