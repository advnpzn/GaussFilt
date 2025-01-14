#include "cli.h"
#include "config.h"

#include <argparse/argparse.hpp>
#include <filesystem>
#include <iostream>

GaussFilt::Cli::Cli(int argc, char* argv[])
    : parser(PROJECT_NAME, PROJECT_VERSION) {
  parser.add_description(PROJECT_DESCRIPTION);

  parser.add_argument("-i", "--input")
      .help("Input image path")
      .required()
      .action([](const std::string& inputImagePath) {
        return std::filesystem::path(inputImagePath);
      });
  parser.add_argument("-g", "--gui").help("Enable/Disable GUI").flag();

  try {
    parser.parse_args(argc, argv);
  } catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << parser;
    std::exit(1);
  }
}

argparse::ArgumentParser& GaussFilt::Cli::getParser() {
  return parser;
}
