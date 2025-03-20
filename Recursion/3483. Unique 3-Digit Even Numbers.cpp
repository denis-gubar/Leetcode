class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int const N = digits.size();
        unordered_set<int> S;
        for(int a = 0; a < N; ++a)
            for(int b = 0; b < N; ++b)
                for(int c = 0; c < N; ++c)
                    if (a != b && a != c && b != c)
                    {
                        int x = digits[a] * 100 + digits[b] * 10 + digits[c];
                        if (x % 2 == 0 && x >= 100)
                            S.insert(x);
                    }
        return S.size();
    }
};
