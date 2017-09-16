#include "../include/InputHandler.hpp"

InputHandler::InputHandler()
{

}

InputHandler::~InputHandler()
{

}

cv::Mat InputHandler::loadImage()
{
    cv::Mat inputImage;
    do
    {
        std::cout << "Enter the name of file with extension: ";
        std::cin >> fileName;

        inputImage = cv::imread(fileName);

        if(inputImage.empty())
        {
            std::cout << "Error. Image not read from file. Please enter the name again. \n";
        }
    }while(inputImage.empty());

    return inputImage;
}

cv::Mat InputHandler::loadImage(std::string inputPath)
{
    cv::Mat inputImage = cv::imread(inputPath);

    if(inputImage.empty())
    {
        std::cout << "Error. Image not read from file. Please enter the name again.";
    }

    return inputImage;
}

cv::Mat InputHandler::loadImage(unsigned char* inputArray)
{
    cv::Mat inputImage = cv::Mat(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8UC3, inputArray).clone();

    return inputImage;
}

std::vector<cv::Mat> InputHandler::loadSeriesOfImage()
{
    std::cout << "Enter the name of file with extension.  \n Type '0' to complete. \n";
    do
    {
        std::cin >> fileName;

        if(fileName != "0")
        {
            cv::Mat inputImage;
            do
            {
                inputImage = cv::imread(fileName);
                if(inputImage.empty())
                {
                    std::cout << "Error. Image not read from file. Please enter the name again.";
                }
                else
                {
                    seriesOfImage.push_back(inputImage);
                }
            } while(inputImage.empty());
        }
    } while (fileName != "0");
    return seriesOfImage;
}
