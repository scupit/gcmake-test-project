# gcmake-basic-tests

This is the largest test project for gcmake-rust. It aims to be an example of what a full-fledged C++
project setup could look like with GCMake, while also acting as the main test case for the majority
of its features.

## IMPORTANT NOTE

Read the [cppfront configuration README](https://github.com/scupit/gcmake-dependency-configs/tree/develop/cppfront) before building this project.
If you don't, your build will probably fail.

## Documentation generation

Building this project's documentation requires a few extra programs, most of which can be downloaded using Python's `pip`:

- [Doxygen](https://www.doxygen.nl/) for generating the XML information to be consumed by Sphinx
- [Sphinx](https://www.sphinx-doc.org/en/master/) for generating the final documentation: `pip install -U sphinx`
- [Breathe](https://breathe.readthedocs.io/en/latest/) for allowing Sphinx to actually make use of Doxygen's output: `pip install breathe`
- [Exhale](https://exhale.readthedocs.io/en/latest/) for automatic documentation of our entire API (comprised of all project files processed by Doxygen): `pip install exhale`
- [sphinx_rtd_theme](https://github.com/readthedocs/sphinx_rtd_theme) for nicer-looking documentation: `pip install sphinx-rtd-theme`
