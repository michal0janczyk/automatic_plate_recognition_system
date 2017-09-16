#include "../include/PlateFinder.hpp"

PlateFinder::PlateFinder()
{

}

PlateFinder::~PlateFinder()
{

}

std::vector<PossiblePlate> PlateFinder::findPlate(cv::Mat inputImage, int flag)
{
    vectorOfPossiblePlates.clear();
    ImageResizer imageResizer;
    cv::Mat resizedImage = imageResizer.resizeImage(inputImage, IMAGE_RESIZE_WIDTH, IMAGE_RESIZE_HEIGHT);
    cv::Mat cloneImage = resizedImage.clone();

    Preprocess preprocessImage;
    vectorOfBinaryImage = preprocessImage.imagePreprocess(resizedImage);

    ContoursFinder imageContoursFinder;
    ContoursFinder imageContoursFinder2;
    vectorOfContoursPointInScen1 = imageContoursFinder.findAllContoursInScene(vectorOfBinaryImage[0]);
    vectorOfContoursPointInScen2 = imageContoursFinder2.findAllContoursInScene(vectorOfBinaryImage[1]);

    PossibleCharInSceneFinder findPossibleCharInScene1;
    vectorOfPossibleCharInScene1 = findPossibleCharInScene1.findAllPossibleCharsInScene(vectorOfContoursPointInScen1);
    PossibleCharInSceneFinder findPossibleCharInScene2;
    vectorOfPossibleCharInScene2 = findPossibleCharInScene2.findAllPossibleCharsInScene(vectorOfContoursPointInScen2);

    ImpossibleCharsRemover impossibleCharsRemover1;
    cleanedVectorOfPossibleCharInScene1 = impossibleCharsRemover1.removeImpossibleChars(vectorOfPossibleCharInScene1);
    ImpossibleCharsRemover impossibleCharsRemover2;
    cleanedVectorOfPossibleCharInScene2 = impossibleCharsRemover2.removeImpossibleChars(vectorOfPossibleCharInScene2);

    VectorOfMatchingCharsBuilder vectorOfMatchingCharsBuilder1;
    vectorOfVectorsOfMatchingCharsInScene1 = vectorOfMatchingCharsBuilder1.findVectorOfVectorsOfMatchingChars(cleanedVectorOfPossibleCharInScene1);
    VectorOfMatchingCharsBuilder vectorOfMatchingCharsBuilder2;
    vectorOfVectorsOfMatchingCharsInScene2 = vectorOfMatchingCharsBuilder2.findVectorOfVectorsOfMatchingChars(cleanedVectorOfPossibleCharInScene2);

    PlateCutter plateCutter1;
    vectorOfPossiblePlates1 = plateCutter1.cutPlateFromScene(cloneImage, vectorOfVectorsOfMatchingCharsInScene1);
    PlateCutter plateCutter2;
    vectorOfPossiblePlates2 = plateCutter2.cutPlateFromScene(cloneImage, vectorOfVectorsOfMatchingCharsInScene2);

    PossiblePlate possiblePlate1 = vectorOfPossiblePlates1[0];
    PossiblePlate possiblePlate2 = vectorOfPossiblePlates2[0];

    if(flag != 0)
    {
        cv::Point2i plateCoordinates[4];
        PlateCoordinatesFinder plateCoordinatesFinder;
        plateCoordinatesFinder.findingPlateCoordinates(cloneImage, possiblePlate1, possiblePlate2, plateCoordinates);

        for (int i = 0; i < 4; i++)
        {
            std::cout << "\n" << plateCoordinates[i];
        }
    }

    vectorOfPossiblePlates.push_back(possiblePlate1);
    vectorOfPossiblePlates.push_back(possiblePlate2);

    return vectorOfPossiblePlates;
}
