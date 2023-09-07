class Solution {
public:
    string finalString(string s) {
        string result;
        for (char c : s)
            if (c == 'i')
                reverse(result.begin(), result.end());
            else
                result += c;
        return result;
    }
};
