#ifndef POSSIBLECHAR_HPP
#define POSSIBLECHAR_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class PossibleChar
{
public:
    PossibleChar();
    PossibleChar(std::vector<cv::Point> _contour);
    ~PossibleChar();

    double distanceBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar);
    double angleBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar);

    static bool sortCharsLeftToRight(const PossibleChar &pcLeft, const PossibleChar & pcRight)
    {
        return(pcLeft.intCenterX < pcRight.intCenterX);
    }

    bool operator == (const PossibleChar& otherPossibleChar) const
    {
        if (this -> contour == otherPossibleChar.contour) return true;
        else return false;
    }

    bool operator != (const PossibleChar& otherPossibleChar) const
    {
        if (this -> contour != otherPossibleChar.contour) return true;
        else return false;
    }

    std::vector<cv::Point> contour;
    cv::Rect boundingRect;

    int intCenterX;
    int intCenterY;

    double dblDiagonalSize;
    double dblAspectRatio;
};

#endif // POSSIBLECHAR_HPP
