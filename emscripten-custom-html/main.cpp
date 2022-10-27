// This is a slightly modified version of the ftxui-starter example main.cpp:
// https://github.com/ArthurSonzogni/ftxui-starter/blob/master/src/main.cpp

#include <iostream>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

using namespace ftxui;

auto itemSummary() {
  auto content = vbox({
    hbox({text(L"- Green:   ") | flex, text(L"14") | bold}) | color(Color::Green),
    hbox({text(L"- Y: ") | flex, text(L"Y") | bold}) | color(Color::Yellow),
    hbox({text(L"- Red:  ") | flex, text(L"R")}) | color(Color::Red),
  });

  return window(text(L" Window title "), content);
}

int main(void) {
  auto document = vbox({
    itemSummary(),
    hbox({
      itemSummary(),
      itemSummary(),
      itemSummary() | flex,
    }),
    itemSummary()
  });

  // Limit the size of the document to 80 char.
  document = document | size(WIDTH, LESS_THAN, 80);

  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);

  screen.Print();

  std::cout << "Something noice\n" 
    << "Another noice\n"
    << "Third one noice"
    << std::endl;

  return EXIT_SUCCESS;
}
