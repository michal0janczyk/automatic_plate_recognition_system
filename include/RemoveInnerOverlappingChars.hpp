#ifndef REMOVEINNEROVERLAPPINGCHARS_HPP
#define REMOVEINNEROVERLAPPINGCHARS_HPP

#include "PossibleChar.hpp"

class RemoveInnerOverlappingChars
{
public:
    RemoveInnerOverlappingChars();
    ~RemoveInnerOverlappingChars();

    std::vector<PossibleChar> removeInnerOverlappingChars(std::vector<PossibleChar> &vectorOfMatchingChars);

private:
    const double MIN_DIAG_SIZE_MULTIPLE_AWAY = 0.1;
};

#endif // REMOVEINNEROVERLAPPINGCHARS_HPP
