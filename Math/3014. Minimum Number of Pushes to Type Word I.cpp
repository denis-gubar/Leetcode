class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;
        vector<int> A(26), M(26);
        for (char c : word)
            ++A[c - 'a'];
        vector<pair<int, int>> P;
        for (int i = 0; i < 26; ++i)
            if (A[i] > 0)
                P.emplace_back(A[i], i);
        sort(P.begin(), P.end());
        int last = 0;
        int times = 0;
        while (!P.empty())
        {
            auto [size, letter] = P.back();
            P.pop_back();
            if (last == 0)
                ++times;
            M[letter] = times;
            last = (last + 1) % 8;
        }
        for (char c : word)
            result += M[c - 'a'];
        return result;
    }
};
