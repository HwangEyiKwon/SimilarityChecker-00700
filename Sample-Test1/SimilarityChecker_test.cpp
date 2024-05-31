#include "pch.h"
#include "../Project15/SimilarityChecker.cpp"

#include <iostream>
using namespace std;

class SimilarityCheckerTestFixture : public testing::Test {
public:
    SimilarityChecker stSimilarirtyChecker;
    void assertIllegalArgument(string str1, string str2) {
        try {
            stSimilarirtyChecker.checkCharCount(str1, str2);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
    }
};

TEST_F(SimilarityCheckerTestFixture, AssertIllegalArgumentTest) {
    SimilarityChecker stSimilarirtyChecker;
    assertIllegalArgument("2SCV", "74HDN3");
    assertIllegalArgument("SCV", "74HDN3");
    assertIllegalArgument("2SCV", "HDN");
    assertIllegalArgument("JASLFAJKSDLFJSCV", "HDN");
    assertIllegalArgument("ASD", "JASLFAJKSDLFJSCV");
}