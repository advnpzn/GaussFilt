#ifndef GUI_H
#define GUI_H

#include "image.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <argparse/argparse.hpp>

namespace GaussFilt {
class Gui {
 public:
  Gui(sf::RenderWindow& window, argparse::ArgumentParser& parser);
  ~Gui() = default;

  void start();
  void shutdown();

 private:
  sf::RenderWindow& renderWindow;
  sf::Clock deltaClock;
  sf::Event event;
  sf::Sprite sprite;
  sf::Texture texture;
  GaussFilt::ImageHandler image;
  GaussFilt::ImageHandler imageHandler;

  float v1;
  float v2;
  float v3;

  int r;
  int g;
  int b;

  enum Mode { DEFAULT, RGB, GRAYSCALE, GAUSSIAN };

  Mode currentMode;

  void draw();
  void display();
  void clear();
};
}  // namespace GaussFilt

#endif  // GUI_H