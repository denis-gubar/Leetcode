class Solution {
public:
    string majorityFrequencyGroup(string s) {
        string result;
        map<char, int> M;
        for (char c : s)
            ++M[c];
        map<int, string> K;
        for (auto [key, value] : M)
            K[value] += key;
        int best = 0;
        for (auto [key, value] : K)
            if (result.size() <= value.size())
                result = value;
        return result;
    }
};
