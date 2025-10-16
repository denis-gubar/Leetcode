class Solution {
public:
    int maxPalindromes(string const& s, int k) {
        int result = 0;
        int N = s.size();
        string t;
        t += '#';
        for (char c : s)
        {
            t += c;
            t += '#';
        }
        vector<int> A(2 * N + 1);
        for (int j = 1; j < 2 * N; ++j)
        {
            int& R = A[j];
            while (j - R > 0 && R + j < 2 * N && t[j - R - 1] == t[j + R + 1])
                ++R;
        }
        int last = -1;
        for (int j = 1; j < 2 * N; ++j)
            if (A[j] >= k)
            {
                if (A[j] % 2 == k % 2)
                {
                    if (last + k <= j)
                    {
                        last = k + j;
                        ++result;
                    }
                }
                else
                {
                    if (last + k <= j)
                    {
                        last = k + j + 1;
                        ++result;
                    }
                }
            }
        return result;
    }
};
