#include "../include/imageloader/ConsoleLoader.hpp"

ConsoleLoader::ConsoleLoader()
{
    //ctor
}

cv::Mat ConsoleLoader::loadImage()
{
    std::cout << "Enter the name of file with extension: ";
    std::cin >> fileName;

    inputImage = cv::imread(fileName);

    if(inputImage.empty())
    {
        std::cout << "Error. Image not read from file.";
    }

    return inputImage;
}

ConsoleLoader::~ConsoleLoader()
{
    //dtor
}
