#include "DrawRedRectangle.h"

DrawRedRectangle::DrawRedRectangle()
{
}

DrawRedRectangle::DrawRedRectangle(cv::Mat &originalImage, PossiblePlate &possPlate)
{
    cv::Point2f p2fRectPoints[4];

    possPlate.rrLocationOfPlateInScene.points(p2fRectPoints);

    for (int i = 0; i < 4; i++)
    {
        cv::line(originalImage, p2fRectPoints[i], p2fRectPoints[(i + 1) % 4], cv::Scalar(0.0, 0.0, 255.0), 2);
    }
}

void DrawRedRectangle::writeLicensePlateCharsOnImage(cv::Mat &originalImage,PossiblePlate &possPlate ,std::string res)
{
    cv::Point ptCenterOfTextArea;
    cv::Point ptLowerLeftTextOrigin;

    int intFontFace = CV_FONT_HERSHEY_SIMPLEX;
    double dblFontScale = 7;
    int intFontThickness = 3;
    int intBaseline = 0;

    cv::Size textSize = cv::getTextSize(res, intFontFace, dblFontScale, intFontThickness, &intBaseline);

    ptCenterOfTextArea.x = (int)possPlate.rrLocationOfPlateInScene.center.x;

    if (possPlate.rrLocationOfPlateInScene.center.y < (originalImage.rows * 0.75))
    {

        ptCenterOfTextArea.y = (int)std::round(possPlate.rrLocationOfPlateInScene.center.y) + (int)std::round((double)possPlate.imgPlate.rows * 1.6);
    }
    else
    {

        ptCenterOfTextArea.y = (int)std::round(possPlate.rrLocationOfPlateInScene.center.y) - (int)std::round((double)possPlate.imgPlate.rows * 1.6);
    }

    ptLowerLeftTextOrigin.x = (int)(ptCenterOfTextArea.x - (textSize.width / 2));
    ptLowerLeftTextOrigin.y = (int)(ptCenterOfTextArea.y + (textSize.height / 2));


    cv::putText(originalImage, res, ptLowerLeftTextOrigin, intFontFace, dblFontScale, cv::Scalar(0.0, 255.0, 255.0), intFontThickness);
}

DrawRedRectangle::~DrawRedRectangle()
{
}
