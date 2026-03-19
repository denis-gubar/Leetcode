class Solution {
public:
    string mergeCharacters(string s, int K) {
        string result;
        for (char c : s)
        {
            if (result.empty())
            {
                result += c;
                continue;
            }
            int const N = result.size();
            bool flag = false;
            for (int i = max(0, N - K); !flag && i < N; ++i)
                flag = result[i] == c;
            if (!flag)
                result += c;
        }
        return result;
    }
};
