#ifndef GAUSSFILT_IMAGE_H
#define GAUSSFILT_IMAGE_H

#include <SFML/Graphics/Image.hpp>
#include <filesystem>
#include <vector>

namespace GaussFilt {
class ImageHandler {
 public:
  bool loadFromFile(const std::filesystem::path& inputImagePath);
  bool saveToFile(const std::filesystem::path& outputImagePath);
  const std::vector<std::vector<double>> getImageData();
  void setPixels(const std::vector<std::vector<double>>& imageData);
  void convertToGrayscale();

 private:
  std::vector<std::vector<double>> imageData;
  sf::Image image;
};
}  // namespace GaussFilt

#endif  // GAUSSFILT_IMAGE_H