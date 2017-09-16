#include "../include/CharRecognizer.hpp"

CharRecognizer::CharRecognizer()
{

}

CharRecognizer::~CharRecognizer()
{

}

std::string CharRecognizer::recognizeChar(std::vector<PossiblePlate> vectorOfPossiblePlates)
{
    cv::Mat licensePlate1 = vectorOfPossiblePlates[0].plateImage;
    cv::Mat licensePlate2 = vectorOfPossiblePlates[1].plateImage;

    ImageResizer plateResizer1;
    cv::Mat resizedPlate1 = plateResizer1.resizeImage(licensePlate1, PLATE_RESIZE_WIDTH, PLATE_RESIZE_HEIGHT);
    ImageResizer plateResizer2;
    cv::Mat resizedPlate2 = plateResizer2.resizeImage(licensePlate2, PLATE_RESIZE_WIDTH, PLATE_RESIZE_HEIGHT);

    Preprocess preprocessPlate1;
    vectorOfBinaryPlate1 = preprocessPlate1.platePreprocess(resizedPlate1);
    Preprocess preprocessPlate2;
    vectorOfBinaryPlate2 = preprocessPlate2.platePreprocess(resizedPlate2);

    ContoursFinder plateContoursFinder1_1;
    ContoursFinder plateContoursFinder1_2;
    ContoursFinder plateContoursFinder2_1;
    ContoursFinder plateContoursFinder2_2;

    cv::Mat binaryPlateClone1 = vectorOfBinaryPlate1[0].clone();
    cv::Mat binaryPlateClone2 = vectorOfBinaryPlate1[1].clone();
    cv::Mat binaryPlateClone3 = vectorOfBinaryPlate2[0].clone();
    cv::Mat binaryPlateClone4 = vectorOfBinaryPlate2[1].clone();

    plateContoursFinder1_1.findAllContoursInScene(vectorOfBinaryPlate1[0]);
    plateContoursFinder1_1.sortContours(binaryPlateClone1);
    plateContoursFinder1_1.cutChar(binaryPlateClone1);

    plateContoursFinder1_2.findAllContoursInScene(vectorOfBinaryPlate1[1]);
    plateContoursFinder1_2.sortContours(binaryPlateClone2);
    plateContoursFinder1_2.cutChar(binaryPlateClone2);

    plateContoursFinder2_1.findAllContoursInScene(vectorOfBinaryPlate2[0]);
    plateContoursFinder2_1.sortContours(binaryPlateClone3);
    plateContoursFinder2_1.cutChar(binaryPlateClone3);

    plateContoursFinder2_2.findAllContoursInScene(vectorOfBinaryPlate2[1]);
    plateContoursFinder2_2.sortContours(binaryPlateClone4);
    plateContoursFinder2_2.cutChar(binaryPlateClone4);

    signsMean1 = plateContoursFinder1_1.getVectorOfSigns();
    signsMean2 = plateContoursFinder1_2.getVectorOfSigns();
    signsGaus1 = plateContoursFinder2_1.getVectorOfSigns();
    signsGaus2 = plateContoursFinder2_2.getVectorOfSigns();

    tempVectorOfSigns.push_back(signsMean1);
    tempVectorOfSigns.push_back(signsMean2);
    tempVectorOfSigns.push_back(signsGaus1);
    tempVectorOfSigns.push_back(signsGaus2);

    ImpossiblePlateEliminator eleminatePlates;
    vectorOfSigns = eleminatePlates.eliminateImpossiblePlate(tempVectorOfSigns);

    ImageChanger imageChanger;
    vectorOfBinarySigns = imageChanger.changeImage(vectorOfSigns);

    CharComparision charComparision;
    result  = charComparision.compareChar(vectorOfBinarySigns);

    return result;
}
