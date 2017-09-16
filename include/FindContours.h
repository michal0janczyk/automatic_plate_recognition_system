#ifndef FINDCONTOURS_H
#define FINDCONTOURS_H

class FindContours
{
public:
    FindContours();
    FindContours(cv::Mat &binImage);
    ~FindContours();

    const std::vector<std::vector<cv::Point>> getPtContours(){return ptContours;};
    const std::vector<cv::Mat> getSigns(){return signs;};

    void cutChar(cv::Mat &binImage);
    void sortContours(cv::Mat &binImage);

private:
    std::vector<std::vector<cv::Point>> ptContours;
    std::vector<cv::Mat> signs;

    const float MAXHEIGHT = 0.9;
    const float MINHEIGHT = 0.6;
};

#endif // FINDCONTOURS_H
