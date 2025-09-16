class Solution {
public:
    int minSwaps(string s) {
        int const N = s.size();
        int result = N + 1;
        for (int t = 0; t < 2; ++t)
        {
            vector<int> current(2);
            for (int i = 0; i < N; ++i)
                current[(s[i] - '0')] += ((s[i] - '0') ^ (i % 2) ^ t);
            if (current[0] == current[1])
                result = min(result, current[0]);
        }
        if (result > N)
            result = -1;
        return result;
    }
};
