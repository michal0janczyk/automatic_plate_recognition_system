#ifndef POSSIBLEPLATE_HPP
#define POSSIBLEPLATE_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "PossibleChar.hpp"

class PossiblePlate
{
public:
    PossiblePlate();
    ~PossiblePlate();

    cv::Mat plateImage;
    cv::RotatedRect rrLocationOfPlateInScene;
};

#endif // POSSIBLEPLATE_HPP
