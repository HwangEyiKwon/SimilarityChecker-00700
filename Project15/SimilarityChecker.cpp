#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
    static const int MAX_LENGTH_CHECKER_POINT = 60;

    int getLengthCheckPoint(string str1, string str2) {
        checkIllegalArgument(str1, str2);

        if (IsSameLength(str1, str2)) return MAX_LENGTH_CHECKER_POINT;
        if (IsDoubleLengthDiff(str1, str2)) return 0;

        return calcPartialPoint(str1, str2);
    }

private:
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