class Solution {
public:
    int largestVariance(string s) {
        int N = s.size();
        int result = 0;
        vector<int> M(26);
        for (char c : s)
            ++M[c - 'a'];
        for (int a = 0; a < 26; ++a)
            if (M[a] > 0)
                for (int b = 0; b < 26; ++b)
                    if (a != b && M[b] > 0)
                    {
                        int A = 0, B = 0;
                        int left = M[b];
                        for (char c : s)
                        {
                            int k = c - 'a';
                            if (k != a && k != b)
                                continue;
                            if (k == a)
                                ++A;
                            if (k == b)
                                ++B, --left;
                            if (B > 0)
                                result = max(result, A - B);
                            if (A < B && left > 0)
                                A = 0, B = 0;
                        }
                    }
        return result;
    }
};

