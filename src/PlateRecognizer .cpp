#include "../include/PlateRecognizer.hpp"

namespace apr
{
    PlateRecognizer::PlateRecognizer()
    {

    }

    PlateRecognizer::~PlateRecognizer()
    {

    }

    std::string PlateRecognizer::recognizePlate()
    {
        cv::Mat inputImage = InputHandler::loadImage();
        std::vector<PossiblePlate> vectorOfPossiblePlate = PlateFinder::findPlate(inputImage, 0);
        std::string result = CharRecognizer::recognizeChar(vectorOfPossiblePlate);
        return result;
    }

    std::string PlateRecognizer::recognizePlate(std::string inputPath)
    {
        cv::Mat inputImage = InputHandler::loadImage(inputPath);
        std::vector<PossiblePlate> vectorOfPossiblePlate = PlateFinder::findPlate(inputImage, 0);
        std::string result = CharRecognizer::recognizeChar(vectorOfPossiblePlate);
        return result;
    }

    std::string PlateRecognizer::recognizePlate(unsigned char* inputArray)
    {
        cv::Mat inputImage = InputHandler::loadImage(inputArray);
        std::vector<PossiblePlate> vectorOfPossiblePlate = PlateFinder::findPlate(inputImage, 0);
        std::string result = CharRecognizer::recognizeChar(vectorOfPossiblePlate);
        return result;
    }

    std::string PlateRecognizer::recognizePlateAndDisplayCoordinates()
    {
        cv::Mat inputImage = InputHandler::loadImage();
        std::vector<PossiblePlate> vectorOfPossiblePlate = PlateFinder::findPlate(inputImage, 1);
        std::string result = CharRecognizer::recognizeChar(vectorOfPossiblePlate);
        return result;
    }

    std::string PlateRecognizer::recognizePlateAndDisplayCoordinates(std::string inputPath)
    {
        cv::Mat inputImage = InputHandler::loadImage(inputPath);
        std::vector<PossiblePlate> vectorOfPossiblePlate = PlateFinder::findPlate(inputImage, 1);
        std::string result = CharRecognizer::recognizeChar(vectorOfPossiblePlate);
        return result;
    }

    std::string PlateRecognizer::recognizePlateAndDisplayCoordinates(unsigned char* inputArray)
    {
        cv::Mat inputImage = InputHandler::loadImage(inputArray);
        std::vector<PossiblePlate> vectorOfPossiblePlate = PlateFinder::findPlate(inputImage, 1);
        std::string result = CharRecognizer::recognizeChar(vectorOfPossiblePlate);
        return result;
    }

    std::string PlateRecognizer::recognizePlateFromImagesSeries()
    {
        std::vector<cv::Mat> vectorOfPlates = InputHandler::loadSeriesOfImage();
        std::vector<std::string> vectorOfResults;
        std::vector<PossiblePlate> vectorOfPossiblePlate;
        for(int i = 0; i < vectorOfPlates.size(); i++)
        {
            vectorOfPossiblePlate.clear();
            vectorOfPossiblePlate = PlateFinder::findPlate(vectorOfPlates[i], 0);
            std::string result = CharRecognizer::recognizeChar(vectorOfPossiblePlate);
            vectorOfResults.push_back(result);
        }
        std::string finalResult = BestResultDisplayer::displayBestResult(vectorOfResults);
        return finalResult;
    }
}
