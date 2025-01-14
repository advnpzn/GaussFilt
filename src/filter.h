#include <vector>

namespace GaussFilt {
class GaussianFilter {
 public:
  GaussianFilter(int kernelSize, double sigma);
  const std::vector<std::vector<double>> getKernel();

 private:
};
}  // namespace GaussFilt