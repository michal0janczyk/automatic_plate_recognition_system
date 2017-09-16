#include "MorphologicalFilters.h"

MorphologicalFilters::MorphologicalFilters()
{

}

MorphologicalFilters::MorphologicalFilters(cv::Mat binaryImage)
{
    filtredImage = binaryImage;
}

void MorphologicalFilters::OpenFilter()
{
    cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE,
                    cv::Size(2 * OPENSIZE + 1, 2 * OPENSIZE + 1),
                    cv::Point(OPENSIZE, OPENSIZE) );

    cv::morphologyEx(filtredImage, filtredImage, cv::MORPH_OPEN, element);
}

void MorphologicalFilters::CloseFilter()
{
    cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE,
                    cv::Size(2 * CLOSESIZE + 1, 2 * CLOSESIZE + 1),
                    cv::Point(CLOSESIZE, CLOSESIZE) );

    cv::morphologyEx(filtredImage, filtredImage, cv::MORPH_CLOSE, element);
}

void MorphologicalFilters::Erosion()
{
    cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE,
                    cv::Size(2 * EROSESIZE + 1, 2 * EROSESIZE + 1),
                    cv::Point(EROSESIZE, EROSESIZE) );

    cv::erode(filtredImage, filtredImage, element);
}

void MorphologicalFilters::Dilation()
{
    cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE,
                    cv::Size( 2 * DILATESIZE + 1, 2 * DILATESIZE + 1),
                    cv::Point(DILATESIZE, DILATESIZE) );

    cv::dilate(filtredImage, filtredImage, element);

    cv::imshow( "Dilated Image",  filtredImage);
}

void MorphologicalFilters::CopyFiltredImage()
{
    filtredImageCopy = filtredImage.clone();
}

MorphologicalFilters::~MorphologicalFilters()
{

}
