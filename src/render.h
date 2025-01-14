#ifndef GAUSSFILT_RENDER_H
#define GAUSSFILT_RENDER_H

#include "image.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace GaussFilt {
class Renderer {
 public:
  Renderer(const ImageHandler& imageHandler);
  ~Renderer() = default;
  void display();

 private:
  const ImageHandler& imageHandler;
  sf::RenderWindow window;
};
}  // namespace GaussFilt

#endif  // GAUSSFILT_RENDER_H