#ifndef IMGUI_H
#define IMGUI_H

#include <imgui-SFML.h>
#include <imgui.h>

#include "filter.h"
#include "image.h"

namespace GaussFilt {
class Gui {
 public:
  Gui(GaussFilt::GaussianFilter& filter, GaussFilt::ImageHandler);
  ~Gui() = default;

  void render();

 private:
  GaussFilt::GaussianFilter filter;
  GaussFilt::ImageHandler imageHandler;
};
}  // namespace GaussFilt

#endif  // IMGUI_H