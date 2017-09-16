#ifndef IMPOSSIBLEPLATEELIMINATOR_HPP
#define IMPOSSIBLEPLATEELIMINATOR_HPP

#include <vector>
#include<opencv2/core/core.hpp>

class ImpossiblePlateEliminator
{
public:
    ImpossiblePlateEliminator();
    ~ImpossiblePlateEliminator();

    std::vector<std::vector<cv::Mat>> eliminateImpossiblePlate(std::vector<std::vector<cv::Mat>> inputImage);

private:
    int numberOfCharsInPlateEqual7;
    int numberOfCharsInPlateEqual8;
    std::vector<std::vector<cv::Mat>> outputImage;
    std::vector<std::vector<cv::Mat>> rejectedImage;
};

#endif // IMPOSSIBLEPLATEELIMINATOR_HPP
