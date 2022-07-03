class Solution {
public:
    int minimumKeypresses(string s) {
        int result = 0;
        vector<int> M(26);
        for (char c : s)
            ++M[c - 'a'];
        sort(M.begin(), M.end());
        int i = 0, weight = 0;
        while (!M.empty() && M.back() > 0)
        {
            if (i % 9 == 0)
                ++weight;
            ++i;
            result += M.back() * weight;
            M.pop_back();
        }
        return result;
    }
};
