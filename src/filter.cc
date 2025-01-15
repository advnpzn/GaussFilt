#include "filter.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>

#include <algorithm>
#include <cmath>
#include <vector>

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

std::vector<std::vector<float>> generate2DGaussianKernel(int kernelSize,
                                                         float sigma) {
  std::vector<std::vector<float>> kernel(kernelSize,
                                         std::vector<float>(kernelSize, 0.0f));
  float sum{};
  int radius = kernelSize / 2;

  // Generate Kernal values
  for (int y = -radius; y <= radius; ++y) {
    for (int x = -radius; x <= radius; ++x) {
      float value = std::exp(-(x * x + y * y) / (2 * sigma * sigma));
      kernel[y + radius][x + radius] = value;
      sum += value;
    }
  }

  //Normalize the kernel
  for (int y = 0; y < kernelSize; ++y) {
    for (int x = 0; x < kernelSize; ++x) {
      kernel[y][x] /= sum;
    }
  }

  return kernel;
}

void guassianBlur(sf::Image& image, int kernelSize, float sigma) {
  std::vector<float> kernel = generate1DGaussianKernel(kernelSize, sigma);
  int radius = kernelSize / 2;

  const unsigned int width = image.getSize().x;
  const unsigned int height = image.getSize().y;

  for (unsigned int y = 0; y < height; ++y) {
    for (unsigned int x = 0; x < width; ++x) {
      float r = 0, g = 0, b = 0;

      for (int kx = -radius; kx <= radius; ++kx) {
        int nx = std::clamp(static_cast<int>(x) + kx, 0,
                            static_cast<int>(width) - 1);
        sf::Color neighborColor = image.getPixel(nx, y);
        float weight = kernel[kx + radius];

        r += neighborColor.r * weight;
        g += neighborColor.g * weight;
        b += neighborColor.b * weight;
      }

      sf::Uint8 finalR = static_cast<sf::Uint8>(std::clamp(r, 0.0f, 255.0f));
      sf::Uint8 finalG = static_cast<sf::Uint8>(std::clamp(g, 0.0f, 255.0f));
      sf::Uint8 finalB = static_cast<sf::Uint8>(std::clamp(b, 0.0f, 255.0f));

      image.setPixel(x, y, sf::Color(finalR, finalG, finalB));
    }
  }

  for (unsigned int y = 0; y < height; ++y) {
    for (unsigned int x = 0; x < width; ++x) {
      float r = 0, g = 0, b = 0;

      for (int ky = -radius; ky <= radius; ++ky) {
        int ny = std::clamp(static_cast<int>(y) + ky, 0,
                            static_cast<int>(height) - 1);
        sf::Color neighborColor = image.getPixel(x, ny);
        float weight = kernel[ky + radius];

        r += neighborColor.r * weight;
        g += neighborColor.g * weight;
        b += neighborColor.b * weight;
      }

      sf::Uint8 finalR = static_cast<sf::Uint8>(std::clamp(r, 0.0f, 255.0f));
      sf::Uint8 finalG = static_cast<sf::Uint8>(std::clamp(g, 0.0f, 255.0f));
      sf::Uint8 finalB = static_cast<sf::Uint8>(std::clamp(b, 0.0f, 255.0f));

      image.setPixel(x, y, sf::Color(finalR, finalG, finalB));
    }
  }
}

std::vector<float> generate1DGaussianKernel(int kernelSize, float sigma) {
  std::vector<float> kernel(kernelSize, 0.0f);
  float sum = 0.0f;
  int radius = kernelSize / 2;

  for (int i = -radius; i <= radius; ++i) {
    float value = std::exp(-(i * i) / (2 * sigma * sigma));
    kernel[i + radius] = value;
    sum += value;
  }

  // Normalize the kernel
  for (float& weight : kernel) {
    weight /= sum;
  }

  return kernel;
}

}  // namespace Filter