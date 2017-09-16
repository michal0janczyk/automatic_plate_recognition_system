#include "SimilarSigns.h"

SimilarSigns::SimilarSigns()
{
}

SimilarSigns::SimilarSigns(std::vector<std::vector<bool>> binSigns)
{

    for (std::size_t i = 0; i < binSigns.size(); i++)
    {
        similarChars.clear();
        percent.clear();

        std::ifstream baseFile("BASE.txt");
        compatibilityMax = 0;

        for(int j = 0; j < BASESIZE; j++)

        {
            baseFile >> tempFit;
            similarChars.push_back(tempFit);
            compatibility = 0;

            for (std::size_t k = 0; k < binSigns[i].size(); k++)
            {
                baseFile >> logic;
                if(binSigns[i][k] == logic)
                {
                    compatibility++;
                }
            }
            percent.push_back(compatibility);

            if(compatibilityMax < compatibility)
            {
                compatibilityMax = compatibility;
                bestFit = tempFit;
            }
        }
        std::cout << "\n\nBest fit: " << bestFit << " Compatibility: "  << 100.0*(compatibilityMax/(LATTICESIZEHEIGHT*LATTICESIZEWIDTH)) << "% \n";

        for (int l = 0; l < BASESIZE; l++)
        {
            if(percent[l] > compatibilityMax - 0.1*LATTICESIZEHEIGHT*LATTICESIZEWIDTH)
            {
                if(static_cast<int>(similarChars[l]) != static_cast<int>(bestFit))
                {
                    std::cout << "    Sign: " << similarChars[l] << " Compatibility: " << 100.0*(percent[l]/(LATTICESIZEHEIGHT*LATTICESIZEWIDTH)) << "%\n";
               }
            }
        }
        baseFile.close();
    }
}

SimilarSigns::~SimilarSigns()
{
}
