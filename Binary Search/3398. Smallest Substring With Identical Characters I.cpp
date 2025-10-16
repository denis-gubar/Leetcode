class Solution {
public:
    int minLength(string s, int numOps) {
        int const N = s.size();
        for (int j = 0; j < 2; ++j)
        {
            int count = 0;
            for (int i = 0; i < N; ++i)
                count += (s[i] - j + i) % 2;
            if (count <= numOps)
                return 1;
        }
        vector<int> A;
        A.reserve(N);
        for (int i = 0; i < N; )
        {
            int j = i;
            while (j < N - 1 && s[i] == s[j + 1])
                ++j;
            A.push_back(j - i + 1);
            i = j + 1;
        }
        int a = 1, b = N;
        int const M = A.size();
        auto calc = [&A, numOps](int m)
            {
                int result = 0;
                for (int x : A)
                    result += x / (m + 1);
                return result <= numOps;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
