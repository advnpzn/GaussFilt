#ifndef FILTER_H
#define FILTER_H

#include <SFML/Graphics/Image.hpp>

namespace Filter {
void convertToGrayScale(sf::Image& image, float v1, float v2, float v3);
void modifyRGB(sf::Image& image, int r, int g, int b);
void guassianFilter();
}  // namespace Filter

#endif  // FILTER_H