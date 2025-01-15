#ifndef GAUSSFIL_CLI_H
#define GAUSSFIL_CLI_H

#include <argparse/argparse.hpp>

namespace GaussFilt {

class Cli {
 public:
  Cli(int argc, char* argv[]);
  ~Cli() = default;

  argparse::ArgumentParser& getParser();

 private:
  argparse::ArgumentParser parser;
};
}  // namespace GaussFilt

#endif  //GAUSSFIL_CLI_H