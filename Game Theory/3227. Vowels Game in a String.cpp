static string const vowels{ "aeiou" };
class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for (char c : s)
            count += vowels.find(c) != string::npos;
        if (count == 0)
            return false;
        return true;
    }
};
