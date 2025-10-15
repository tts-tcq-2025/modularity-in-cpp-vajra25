#include "ColorCoder.h"
#include <sstream>

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    const int numberOfMajorColors = sizeof(MajorColorNames)/sizeof(MajorColorNames[0]);
    const int numberOfMinorColors = sizeof(MinorColorNames)/sizeof(MinorColorNames[0]);

    ColorPair::ColorPair(MajorColor major, MinorColor minor):
        majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajor() const { return majorColor; }
    MinorColor ColorPair::getMinor() const { return minorColor; }

    std::string ColorPair::ToString() const {
        return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
    }

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
