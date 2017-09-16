#include "AddMargins.h"

AddMargins::AddMargins()
{
}

AddMargins::AddMargins(std::vector<std::vector<cv::Mat>> signs)
{
    for(std::size_t i = 0; i < signs.size(); i++)
    {
        signsWithMargins = signs[i];

        for(std::size_t j = 0; j < signsWithMargins.size(); j++)
        {
            signHeight = signsWithMargins[j].size().height;
            signWidth = signsWithMargins[i].size().width;
            signWithMarginsWidth = LARGESTLETTERWIDTH * signHeight / LARGESTLETTERHEIGHT;
            marginWidth = (signWithMarginsWidth - signWidth) / 2.0;

            if(marginWidth < 0)
            {
                marginWidth = 0;
            }

            cv::copyMakeBorder(signsWithMargins[i], signsWithMargins[i],
                           TOPMARGIN, BOTTOMMARGIN, marginWidth, marginWidth,
                           cv::BORDER_ISOLATED, MARGINPIXELVALUE);
        }
        vectorOfSignsWithMargins.push_back(signsWithMargins);
    }
}

AddMargins::~AddMargins()
{
}
