class Solution {
public:
    bool scoreBalance(string s) {
        int const N = s.size();
        int right = accumulate(s.begin(), s.end(), 0) - N * 'a' + N;
        int left = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            left += s[i] - 'a' + 1;
            right -= s[i] - 'a' + 1;
            if (left == right)
                return true;
        }
        return false;
    }
};
