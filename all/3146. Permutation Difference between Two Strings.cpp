class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int result = 0;
        int N = s.size();
        for (int i = 0; i < N; ++i)
            result += abs(static_cast<int>(t.find(s[i])) - i);
        return result;
    }
};
