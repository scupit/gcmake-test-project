# Emscripten + Custom HTML

This project is a working example of using a custom HTML shell file with Emscripten.

## The shell file

To use a custom HTML file with an executable, set `emscripten_html_shell` for that
executable to the html file path **relative to the root project**.

``` yaml
output:
  do-things:
    output_type: Executable
    entry_file: main.cpp
    link:
      - FTXUI::{ dom, screen }
    emscripten_html_shell: custom-shell.html # Important line
```

The custom HTML shell file [custom-shell.html](https://emscripten.org/docs/tools_reference/emcc.html#emcc-shell-file) is a modified combination of the
[Emscripten minimal shell file](https://github.com/emscripten-core/emscripten/blob/main/src/shell_minimal.html)
and the [FTXUI example shell file](https://github.com/ArthurSonzogni/FTXUI/blob/master/examples/index.html).

It uses [xterm.js](https://www.npmjs.com/package/xterm)
and its addons [xterm-addon-fit](https://www.npmjs.com/package/xterm-addon-fit) +
[xterm-addon-webgl](https://www.npmjs.com/package/xterm-addon-webgl)
to emulate a terminal environment in the browser so that output from FTXUI can be properly rendered
in full color.
