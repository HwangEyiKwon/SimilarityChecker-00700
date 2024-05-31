#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class SimilarityChecker {
public:
    static const int MAX_ALPHABET_CHECKER_POINT = 40;
    static const int MAX_LENGTH_CHECKER_POINT = 60;
  
    int getAlphabetCheckPoint(string str1, string str2) {
        checkIllegalArgument(str1, str2);

        int totalCount = getTotalCount(makeUniqueCharList(str1 + str2));
        int sameCount = getSameCount(makeUniqueCharList(str1), makeUniqueCharList(str2));

        if (totalCount == sameCount) return MAX_ALPHABET_CHECKER_POINT;
        if (sameCount == 0) return 0;
        return (MAX_ALPHABET_CHECKER_POINT * sameCount) / totalCount;
    }
    
    int getLengthCheckPoint(string str1, string str2) {
        checkIllegalArgument(str1, str2);

        if (IsSameLength(str1, str2)) return MAX_LENGTH_CHECKER_POINT;
        if (IsDoubleLengthDiff(str1, str2)) return 0;

        return calcPartialPoint(str1, str2);
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
  
    int calcPartialPoint(std::string& str1, std::string& str2)
    {
        int result = 0;
        int gap = 0;
        int shortLength = 0;

        if (str1.size() >= str2.size()) {
            gap = str1.size() - str2.size();
            shortLength = str2.size();
        }
        else
        {
            gap = str2.size() - str1.size();
            shortLength = str1.size();
        }

        result = ((shortLength - gap) * MAX_LENGTH_CHECKER_POINT) / shortLength;
        return result;
    }

    bool IsSameLength(std::string& str1, std::string& str2)
    {
        return str1.size() == str2.size();
    }

    bool IsDoubleLengthDiff(std::string& str1, std::string& str2)
    {
        return str1.size() >= str2.size() * 2 || str1.size() * 2 <= str2.size();
    }

    void checkIllegalArgument(std::string& str1, std::string& str2)
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