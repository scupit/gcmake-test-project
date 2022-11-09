# Crow example project

## READ THIS

The build will not initially work out-of-the-box. Crow's call to *find_package(asio)* conflicts
with ours, since ours has some extra functionality. I haven't found a way to disable theirs from our code
yet, so this temporary solution will have to do for now.

Once *Crow* has successfully been cloned, open *dep/Crow/CMakeLists.txt* and change the line:

``` cmake
find_package( asio REQUIRED )
```

to

``` cmake
if( NOT TARGET asio::asio )
  find_package( asio REQUIRED )
endif()
```

This will cause Crow to use our asio target instead of the one it would otherwise create. This is kind of an
annoying solution, but for now it works. Maybe I'll open a pull request to see if that bit can be changed.
