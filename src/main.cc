#include "cli.h"

#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Vector2.hpp>

#include <cstdlib>
#include <filesystem>
#include <iostream>

int main(int argc, char* argv[]) {

  GaussFilt::Cli cli(argc, argv);

  const std::filesystem::path& inputImagePath =
      cli.getParser().get<std::filesystem::path>("--input");

  const bool& gui = cli.getParser().get<bool>("--gui");

  if (gui) {
    std::cout << "GUI mode is not implemented yet." << std::endl;
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}