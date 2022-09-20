class Solution {
public:
    bool isPalindrome(vector<int> const& x)
    {
        int a = 0, b = x.size() - 1;
        while (a < b)
        {
            if (x[a] != x[b])
                return false;
            else
                ++a, --b;
        }
        return true;
    }
    bool isStrictlyPalindromic(int N) {
        for (int base = 2; base < N; ++base)
        {
            vector<int> A;
            int a = N;
            while (a > 0)
            {
                A.push_back(a % base);
                a /= base;
            }
            if (!isPalindrome(A))
                return false;
        }
        return true;
    }
};
