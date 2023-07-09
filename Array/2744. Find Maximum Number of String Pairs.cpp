class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        multiset<string> S;
        for (string const& x : words)
            S.insert(x);
        int result = 0;
        for (string const& x : S)
        {
            string t(x);
            reverse(t.begin(), t.end());
            if (S.find(t) != S.end() && x != t)
                ++result;
        }
        return result / 2;
    }
};