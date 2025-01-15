#include "image.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>

bool GaussFilt::ImageHandler::loadFromFile(
    const std::filesystem::path& inputImagePath) {

  if (!image.loadFromFile(inputImagePath)) {
    return false;
  }

  return true;
}

bool GaussFilt::ImageHandler::saveToFile(
    const std::filesystem::path& outputImagePath) {

  return image.saveToFile(outputImagePath);
}

void GaussFilt::ImageHandler::convertToGrayscale(float v1, float v2, float v3) {

  sf::Vector2 size = image.getSize();
  imageData.resize(size.x, std::vector<double>(size.y));

  for (unsigned int y = 0; y < size.y; ++y) {
    for (unsigned int x = 0; x < size.x; ++x) {

      sf::Color pixel = image.getPixel(x, y);

      // Luminosity method (https://en.wikipedia.org/wiki/Grayscale#Luma_coding_in_video_systems)
      double grayScale = v1 * pixel.r + v2 * pixel.g + v3 * pixel.b;

      image.setPixel(x, y, sf::Color(grayScale, grayScale, grayScale));
    }
  }
}

sf::Vector2u GaussFilt::ImageHandler::getSize() {
  return image.getSize();
}

sf::Image& GaussFilt::ImageHandler::getImage() {
  return image;
}