#include "pch.h"
#include "../Project15/SimilarityChecker.cpp"

#include <iostream>
using namespace std;

TEST(SimilarityCheckerTest, InvalidInputTest) {
    SimilarityChecker stSimilarirtyChecker;
    EXPECT_THROW(stSimilarirtyChecker.checkCharCount("2SCV", "74HDN3"), invalid_argument);
}