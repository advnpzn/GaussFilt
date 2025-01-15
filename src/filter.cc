#include "filter.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>

namespace Filter {

void convertToGrayScale(sf::Image& image, float v1, float v2, float v3) {
  for (unsigned int x = 0; x < image.getSize().x; x++) {
    for (unsigned int y = 0; y < image.getSize().y; y++) {
      sf::Color pixel = image.getPixel(x, y);
      double grayScale = v1 * pixel.r + v2 * pixel.g + v3 * pixel.b;
      image.setPixel(x, y, sf::Color(grayScale, grayScale, grayScale));
    }
  }
}

void modifyRGB(sf::Image& image, int r, int g, int b) {
  for (unsigned int x = 0; x < image.getSize().x; x++) {
    for (unsigned int y = 0; y < image.getSize().y; y++) {
      sf::Color pixel = image.getPixel(x, y);
      pixel.r = r * r / 255;
      pixel.g = g * g / 255;
      pixel.b = b * b / 255;
      image.setPixel(x, y, pixel);
    }
  }
}

void guassianFilter();

}  // namespace Filter