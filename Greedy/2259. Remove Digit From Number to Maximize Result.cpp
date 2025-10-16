class Solution {
public:
    string removeDigit(string number, char digit) {
        string result = "0";
        int N = number.size();
        for (int i = 0; i < N; ++i)
            if (number[i] == digit)
            {
                string t = number;
                t.erase(t.begin() + i);
                result = max(result, t);
            }
        return result;
    }
};
