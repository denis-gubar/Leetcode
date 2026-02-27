class Solution {
public:
    string maximumXor(string s, string t) {
        int const N = s.size();
        vector<int> A{ 0, 0 };
        for (char c : t)
            ++A[c - '0'];
        string result(N, '0');
        for (int i = 0; i < N; ++i)
        {
            if (s[i] == '0')
            {
                if (A[1] > 0)
                    result[i] = '1', --A[1];
                else
                    result[i] = '0', --A[0];
            }
            else
            {
                if (A[0] > 0)
                    result[i] = '1', --A[0];
                else
                    result[i] = '0', --A[1];
            }
        }
        return result;
    }
};
