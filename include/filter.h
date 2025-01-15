#ifndef FILTER_H
#define FILTER_H

#include <SFML/Graphics/Image.hpp>
#include <vector>

namespace Filter {
void convertToGrayScale(sf::Image& image, float v1, float v2, float v3);
void modifyRGB(sf::Image& image, int r, int g, int b);
void guassianBlur(sf::Image& image, int kernelSize, float sigma);
std::vector<float> generate1DGaussianKernel(int kernelSize, float sigma);
std::vector<std::vector<float>> generate2DGaussianKernel(int kernelSize,
                                                         float sigma);

}  // namespace Filter

#endif  // FILTER_H