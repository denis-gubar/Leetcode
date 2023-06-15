class Solution {
public:
    int minimizedStringLength(string s) {
        int N = s.size();
        int result = N;
        vector<int> M(26);
        for (char c : s)
            ++M[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (M[i] > 1)
                result += 1 - M[i];
        return result;
    }
};
