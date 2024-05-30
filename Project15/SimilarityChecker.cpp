#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
    int checkCharCount(string str1, string str2) {
        for (const char& ch : str1) {
            if (ch < 'A' || ch > 'Z') throw invalid_argument("Input Only A~Z!!!");
        }
    }
};