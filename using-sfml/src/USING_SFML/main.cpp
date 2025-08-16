#include <cstdlib>
#include <string>
#include "fmt/core.h"
#include "SFML/Graphics.hpp"

int main()
{
  fmt::println("Creating window");
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  window.setFramerateLimit(60);

  const std::string fontPath = "resources/USING_SFML/arial.ttf";
  sf::Font font;

  fmt::println("Loading font at path \"./{}\"", fontPath);
  if (!font.loadFromFile(fontPath)) {
    return EXIT_FAILURE;
  }

  sf::Text text;
  text.setFillColor(sf::Color::Red);

  // This is the long form. These can also be set in the constructor.
  text.setString("Some cool text");
  text.setCharacterSize(36);
  text.setFont(font);

  fmt::println("Starting main loop");
  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();
  }

  return EXIT_SUCCESS;
}