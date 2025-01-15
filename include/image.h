#ifndef GAUSSFILT_IMAGE_H
#define GAUSSFILT_IMAGE_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Vector2.hpp>
#include <filesystem>
#include <vector>

namespace GaussFilt {
class ImageHandler {
 public:
  bool loadFromFile(const std::filesystem::path& inputImagePath);
  bool saveToFile(const std::filesystem::path& outputImagePath);
  const std::vector<std::vector<double>> getImageData();
  void setPixels(const std::vector<std::vector<double>>& imageData);
  void convertToGrayscale(float v1, float v2, float v3);
  sf::Vector2u getSize();
  sf::Image& getImage();

 private:
  std::vector<std::vector<double>> imageData;
  sf::Image image;
};
}  // namespace GaussFilt

#endif  // GAUSSFILT_IMAGE_H