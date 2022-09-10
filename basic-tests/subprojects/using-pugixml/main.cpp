#include <iostream>
#include <string>

#include "pugixml.hpp"

int main() {
  const std::string documentPath = "resources/CGEN_TEST/USING_PUGIXML/SomeDocument.xml";
  pugi::xml_document document;
  pugi::xml_parse_result result = document.load_file(documentPath.c_str());

  if (!result) {
    std::cout << "Failed to parse the document at ./" << documentPath << ". Is the file missing?" << std::endl;
    return EXIT_FAILURE;
  }

  for (const pugi::xml_node& item : document.child("List").children("Item")) {
    std::cout << "Item:\n\tName: " << item.attribute("name").value();

    for (const auto& bodyNode : item.children("Body")) {
      std::cout << "\n\tBody:\n\t\tText: " << bodyNode.child_value() << '\n';
    }
  }

	return EXIT_SUCCESS;
}
