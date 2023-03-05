class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int N = word.size();
        vector<int> result(N);
        long long x = 0;
        for (int i = 0; i < N; ++i)
        {
            x = x * 10 + (word[i] - '0');
            x %= m;
            if (x == 0)
                result[i] = 1;
        }
        return result;
    }
};
