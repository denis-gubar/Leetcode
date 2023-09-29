class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string result;
        int zeroCount = count(s.begin(), s.end(), '0');
        int oneCount = count(s.begin(), s.end(), '1');
        for (int i = 1; i < oneCount; ++i)
            result += '1';
        for (int i = 0; i < zeroCount; ++i)
            result += '0';
        result += '1';
        return result;
    }
};
