#include "../include/ImpossiblePlateEliminator.hpp"

ImpossiblePlateEliminator::ImpossiblePlateEliminator()
{

}

ImpossiblePlateEliminator::~ImpossiblePlateEliminator()
{

}

std::vector<std::vector<cv::Mat>> ImpossiblePlateEliminator::eliminateImpossiblePlate(std::vector<std::vector<cv::Mat>> inputImage)
{
    numberOfCharsInPlateEqual7 = 0;
    numberOfCharsInPlateEqual8 = 0;

    for(std::size_t i = 0; i < inputImage.size(); i++)
    {
        if(int(inputImage[i].size())==7)
        {
            numberOfCharsInPlateEqual7++;
        }
        if(int(inputImage[i].size())==8)
        {
            numberOfCharsInPlateEqual8++;
        }
    }

    if(numberOfCharsInPlateEqual8 >= numberOfCharsInPlateEqual7)
    {
        outputImage.clear();
        for(std::size_t i = 0; i < inputImage.size(); i++)
        {
            if(inputImage[i].size()==8)
            {
                outputImage.push_back(inputImage[i]);
            }
        }
    }
    else
    {
        outputImage.clear();
        for(std::size_t i = 0; i < inputImage.size(); i++)
        {
            if(inputImage[i].size()==7)
            {
                outputImage.push_back(inputImage[i]);
            }
        }
    }

    return outputImage;
}


