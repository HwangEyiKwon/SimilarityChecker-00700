#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class SimilarityChecker {
public:
    static const int MAX_ALPHABET_CHECKER_POINT = 40;
    int getAlphabetCheckPoint(string str1, string str2) {
        checkIllegalArgument(str1, str2);

        int totalCount = getTotalCount(makeUniqueCharList(str1 + str2));
        int sameCount = getSameCount(makeUniqueCharList(str1), makeUniqueCharList(str2));

        if (totalCount == sameCount) return MAX_ALPHABET_CHECKER_POINT;
        if (sameCount == 0) return 0;
        return (MAX_ALPHABET_CHECKER_POINT * sameCount) / totalCount;
    }

private:
    int getSameCount(vector<char> uniqueCharListOfStr1, vector<char> uniqueCharListOfStr2)
    {
        int sameCount = 0;
        for (const char& ch1 : uniqueCharListOfStr1) {
            for (const char& ch2 : uniqueCharListOfStr2) {
                if (ch1 == ch2) sameCount++;
            }
        }
        return sameCount;
    }

    int getTotalCount(vector<char> totalAlphabet)
    {
        int totalCount = 0;
        for (const char& ch1 : totalAlphabet) {
            totalCount++;
        }
        return totalCount;
    }

    vector<char> makeUniqueCharList(string str) {
        vector<char> uniqueCharList;

        for (const char& ch : str) {
            uniqueCharList.push_back(ch);
        }

        sort(uniqueCharList.begin(), uniqueCharList.end());
        uniqueCharList.erase(unique(uniqueCharList.begin(), uniqueCharList.end()), uniqueCharList.end());

        return uniqueCharList;
    }

    void checkIllegalArgument(string& str1, string& str2)
    {
        for (const char& ch : str1) {
            if (ch < 'A' || ch > 'Z') throw invalid_argument("Input Only A~Z!!!");
        }
        for (const char& ch : str2) {
            if (ch < 'A' || ch > 'Z') throw invalid_argument("Input Only A~Z!!!");
        }

        if (str1.size() > 10 || str2.size() > 10) throw length_error("Input Size must be under 10!!!");
    }
};