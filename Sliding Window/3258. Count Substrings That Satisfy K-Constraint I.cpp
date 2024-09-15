class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int const N = s.size();
        int result = 0;
        for (int i = 0; i < N; ++i)
        {
            vector<int> A{ 0, 0 };
            for (int j = i; j < N; ++j)
            {
                ++A[s[j] - '0'];
                if (A[0] <= k || A[1] <= k)
                    ++result;
                else
                    break;
            }
        }
        return result;
    }
};
