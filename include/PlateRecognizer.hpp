#ifndef PLATERECOGNIZER_HPP
#define PLATERECOGNIZER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "PlateFinder.hpp"
#include "CharRecognizer.hpp"
#include "BestResultDisplayer.hpp"
#include "InputHandler.hpp"
#include <stdexcept>

namespace apr
{
    class PlateRecognizer
        : public InputHandler,
          public PlateFinder,
          public CharRecognizer,
          public BestResultDisplayer
    {
    public:
        PlateRecognizer();
        ~PlateRecognizer();

        std::string recognizePlate();
        std::string recognizePlate(std::string inputPath);
        std::string recognizePlate(unsigned char* inputArray);
        std::string recognizePlateAndDisplayCoordinates();
        std::string recognizePlateAndDisplayCoordinates(std::string inputPath);
        std::string recognizePlateAndDisplayCoordinates(unsigned char* inputArray);
        std::string recognizePlateFromImagesSeries(std::vector<cv::Mat> vectorOfPlates);
        std::string recognizePlateFromImagesSeries();

    };
}

#endif // PLATERECOGNIZER_HPP
