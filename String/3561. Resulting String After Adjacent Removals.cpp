class Solution {
public:
    string resultingString(string s) {
        int const N = s.size();
        string result;
        result.reserve(N);
        for (char c : s)
        {
            if (!result.empty())
            {
                if (abs(result.back() - c) == 1 || abs(result.back() - c) == 25)
                {
                    result.pop_back();
                    continue;
                }
            }
            result += c;
        }
        return result;
    }
};
