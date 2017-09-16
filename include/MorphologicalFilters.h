#ifndef MORPHOLOGICALFILTERS_H
#define MORPHOLOGICALFILTERS_H

#include "BinImage.h"

class MorphologicalFilters
{
public:
    MorphologicalFilters();
    MorphologicalFilters(cv::Mat binaryImage);
    ~MorphologicalFilters();

    const cv::Mat getImage() {return filtredImage;};
    const cv::Mat getCopyImage() {return filtredImageCopy;};

    void OpenFilter();
    void CloseFilter();
    void Erosion();
    void Dilation();
    void CopyFiltredImage();

private:
    cv::Mat filtredImage;
    cv::Mat filtredImageCopy;
    static const int OPENSIZE = 3;
    static const int CLOSESIZE = 1;
    static const int EROSESIZE = 1;
    static const int DILATESIZE = 1;
};

#endif // MORPHOLOGICALFILTERS_H
