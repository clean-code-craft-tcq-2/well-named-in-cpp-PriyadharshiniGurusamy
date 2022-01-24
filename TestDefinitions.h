#include <iostream>
#include "ColorCodeInterface.h"
#include <assert.h>

int printCounter = 0;
int getColorPairCounter = 0;

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void mockPrint(int /*PairNumber*/, std::string /*ColorPair*/)
{
    printCounter++;
}
TelCoColorCoder::ColorPair mockGetColorPair(int PairNumber)
{
    getColorPairCounter++;
    return TelCoColorCoder::GetColorFromPairNumber(pairNumber);
}

void testPrintColorPairManual()
{
    printCounter = 0;
    getColorPairCounter = 0;  
    TelCoColorCoder::PrintManual(mockGetColorPair, mockPrint);
    assert(printCounter == 23);
}
