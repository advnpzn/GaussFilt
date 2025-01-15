#include "gui.h"
#include "config.h"
#include "filter.h"
#include "image.h"

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <argparse/argparse.hpp>

#include <cstdlib>
#include <filesystem>

GaussFilt::Gui::Gui(sf::RenderWindow& renderWindow,
                    argparse::ArgumentParser& parser)
    : renderWindow(renderWindow),
      currentMode(DEFAULT),
      v1(0.299f),
      v2(0.587f),
      v3(0.114f) {

  const std::filesystem::path& inputImagePath =
      parser.get<std::filesystem::path>("--input");

  if (!image.loadFromFile(inputImagePath)) {
    std::exit(1);
  }

  renderWindow.create(sf::VideoMode(image.getSize().x, image.getSize().y),
                      PROJECT_NAME);

  if (!ImGui::SFML::Init(renderWindow)) {
    throw std::runtime_error("Failed to initialize ImGui-SFML.");
  }
  ImGui::GetIO().IniFilename = nullptr;

  texture.loadFromImage(image.getImage());
  sprite = sf::Sprite(texture);
}

void GaussFilt::Gui::start() {
  while (renderWindow.isOpen()) {
    while (renderWindow.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);
      if (event.type == sf::Event::Closed) {
        renderWindow.close();
      }
    }
    draw();
    clear();
    display();
  }
}

void GaussFilt::Gui::draw() {
  ImGui::SFML::Update(renderWindow, deltaClock.restart());

  ImGui::SetNextWindowSize(ImVec2(300, 150), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowPos(ImVec2(image.getSize().x - (300 + 10), 10),
                          ImGuiCond_FirstUseEver);
  ImGui::Begin("Controls");
  ImGui::BeginDisabled();
  ImGui::RadioButton("RGB", (int*)&currentMode, RGB);
  ImGui::EndDisabled();
  ImGui::SameLine();
  ImGui::RadioButton("Grayscale", (int*)&currentMode, GRAYSCALE);
  ImGui::SameLine();
  ImGui::RadioButton("Gaussian", (int*)&currentMode, GAUSSIAN);
  ImGui::NewLine();

  sf::Image tempImage = image.getImage();

  if (currentMode == RGB) {
    ImGui::SliderInt("R", &r, 0, 255);
    ImGui::SliderInt("G", &g, 0, 255);
    ImGui::SliderInt("B", &b, 0, 255);

    Filter::modifyRGB(tempImage, r, g, b);

  } else if (currentMode == GRAYSCALE) {
    ImGui::SliderFloat("Weight (R)", &v1, 0.0f, 5.0f);
    ImGui::SliderFloat("Weight (G)", &v2, 0.0f, 5.0f);
    ImGui::SliderFloat("Wright (B)", &v3, 0.0f, 5.0f);

    Filter::convertToGrayScale(tempImage, v1, v2, v3);
  }
  texture.loadFromImage(tempImage);
  ImGui::End();
}

void GaussFilt::Gui::clear() {
  renderWindow.clear();
}

void GaussFilt::Gui::display() {
  renderWindow.draw(sprite);
  ImGui::SFML::Render(renderWindow);
  renderWindow.display();
}

void GaussFilt::Gui::shutdown() {
  ImGui::SFML::Shutdown();
}