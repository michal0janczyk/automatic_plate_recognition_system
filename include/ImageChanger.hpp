#ifndef IMAGECHANGER_HPP
#define IMAGECHANGER_HPP

#include "ContoursFinder.hpp"

class ImageChanger
{
public:
    ImageChanger();
    ~ImageChanger();

    std::vector<std::vector<std::vector<bool>>> changeImage(std::vector<std::vector<cv::Mat>> vectorOfSigns);
    void swapImageToBinary(std::vector<cv::Mat> signs);

private:
    std::vector<std::vector<std::vector<bool>>> vectorOfBinarySigns;
    std::vector<std::vector<bool>> binSigns;
    std::vector<bool> tmpVec;
    std::vector<cv::Mat> tempVector;
    float height;
    float width;
    static const int LATTICESIZEWIDTH = 27;
    static const int LATTICESIZEHEIGHT = 40;
};

#endif // IMAGECHENGER_HPP
