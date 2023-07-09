class Solution {
public:
    string convert(int x)
    {
        string result;
        if (x == 0)
            result.push_back('0');
        while (x > 0)
        {
            result.push_back((x & 1) + '0');
            x >>= 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int minimumBeautifulSubstrings(string s) {
        int N = s.size();
        set<string> S;
        for (int x = 1; x < (1 << N); x *= 5)
            S.insert(convert(x));
        int result = N + 1;
        vector<int> digits;
        digits.reserve(N + 2);
        for (int mask = 0; mask < (1 << (N - 1)); ++mask)
        {
            digits.clear();
            digits.push_back(-1);
            for(int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    digits.push_back(k);
            digits.push_back(N);
            int D = digits.size();
            if (D - 1 >= result)
                continue;
            bool flag = true;
            for(int i = 0; i < D - 1; ++i)
                if (S.find(s.substr(digits[i] + 1, digits[i + 1] - digits[i])) == S.end())
                {
                    flag = false;
                    break;
                }
            if (flag)
                result = D - 1;
        }
        if (result > N)
            result = -1;
        return result;
    }
};
