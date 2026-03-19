class Solution {
public:
    int maxSameLengthRuns(string s) {
        int result = 0;
        char prev = '^';
        s += '$';
        int count = 0;
        unordered_map<int, int> M;
        for (char c : s)
            if (c != prev)
            {
                if (prev != '^')
                    ++M[count];
                count = 1, prev = c;
            }
            else
                ++count;
        for (auto [key, value] : M)
            if (result < value)
                result = value;
        return result;
    }
};
