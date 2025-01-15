#include "cli.h"
#include "gui.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {

  GaussFilt::Cli cli(argc, argv);

  const bool& isGui = cli.getParser().get<bool>("--gui");

  if (!isGui) {
    std::cout << "CLI mode is not implemented yet." << std::endl;
    return EXIT_SUCCESS;
  }

  sf::RenderWindow window;
  GaussFilt::Gui gui(window, cli.getParser());

  gui.start();
  gui.shutdown();

  return EXIT_SUCCESS;
}