#include "image.h"

#include <SFML/System/Vector2.hpp>

#include <filesystem>

bool GaussFilt::ImageHandler::loadFromFile(
    const std::filesystem::path& inputImagePath) {

  if (!image.loadFromFile(inputImagePath)) {
    return false;
  }

  convertToGrayscale();

  return true;
}

bool GaussFilt::ImageHandler::saveToFile(
    const std::filesystem::path& outputImagePath) {

  sf::Vector2 size = image.getSize();

  for (unsigned int y = 0; y < size.y; ++y) {
    for (unsigned int x = 0; x < size.x; ++x) {

      double pixelValue = imageData[x][y] * 255.0;
      sf::Color pixel(pixelValue, pixelValue, pixelValue);
      image.setPixel(x, y, pixel);
    }
  }

  return image.saveToFile(outputImagePath);
}

void GaussFilt::ImageHandler::convertToGrayscale() {

  sf::Vector2 size = image.getSize();
  imageData.resize(size.x, std::vector<double>(size.y));

  for (unsigned int y = 0; y < size.y; ++y) {
    for (unsigned int x = 0; x < size.x; ++x) {

      sf::Color pixel = image.getPixel(x, y);

      double grayScale = 0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b;
      image.setPixel(x, y, sf::Color(grayScale, grayScale, grayScale));
    }
  }
}