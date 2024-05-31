#include "pch.h"
#include "../Project15/SimilarityChecker.cpp"

using namespace std;

class SimilarityCheckerTestFixture : public testing::Test {
public:
    SimilarityChecker stSimilarirtyChecker;
    void assertIllegalArgument(string str1, string str2) {
        try {
            stSimilarirtyChecker.getLengthCheckPoint(str1, str2);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
    }
};

TEST_F(SimilarityCheckerTestFixture, AssertIllegalArgumentTest) {
    assertIllegalArgument("2SCV", "74HDN3");
    assertIllegalArgument("SCV", "74HDN3");
    assertIllegalArgument("2SCV", "HDN");
    assertIllegalArgument("JASLFAJKSDLFJSCV", "HDN");
    assertIllegalArgument("ASD", "JASLFAJKSDLFJSCV");
}

TEST_F(SimilarityCheckerTestFixture, LengthCheckTest00) {
    string str1 = "ASD";
    string str2 = "DSA";
    EXPECT_EQ(stSimilarirtyChecker.getLengthCheckPoint(str1, str2), 60);
}

TEST_F(SimilarityCheckerTestFixture, LengthCheckTest01) {
    string str1 = "A";
    string str2 = "BB";
    EXPECT_EQ(stSimilarirtyChecker.getLengthCheckPoint(str1, str2), 0);
}

TEST_F(SimilarityCheckerTestFixture, LengthCheckTest02) {
    string str1 = "AAABB";
    string str2 = "BAA";
    EXPECT_EQ(stSimilarirtyChecker.getLengthCheckPoint(str1, str2), 20);
}

TEST_F(SimilarityCheckerTestFixture, LengthCheckTest03) {
    string str1 = "AA";
    string str2 = "AAE";
    EXPECT_EQ(stSimilarirtyChecker.getLengthCheckPoint(str1, str2), 30);
}