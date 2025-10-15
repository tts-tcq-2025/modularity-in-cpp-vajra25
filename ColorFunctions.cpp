#include "ColorFunctions.h"
#include <sstream>

namespace TelCoColorCoder
{
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBased = pairNumber - 1;
        MajorColor major = (MajorColor)(zeroBased / numberOfMinorColors);
        MinorColor minor = (MinorColor)(zeroBased % numberOfMinorColors);
        return ColorPair(major, minor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    std::vector<std::string> GetColorCodeReference() {
        std::vector<std::string> reference;
        for (int i = 0; i < numberOfMajorColors; ++i) {
            for (int j = 0; j < numberOfMinorColors; ++j) {
                int pairNumber = GetPairNumberFromColor((MajorColor)i, (MinorColor)j);
                std::ostringstream oss;
                oss << pairNumber << " - " << MajorColorNames[i] << " " << MinorColorNames[j];
                reference.push_back(oss.str());
            }
        }
        return reference;
    }
}
