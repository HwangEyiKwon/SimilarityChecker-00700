#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
    int checkCharCount(string str1, string str2) {
        checkIllegalArgument(str1, str2);
        return 0;
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