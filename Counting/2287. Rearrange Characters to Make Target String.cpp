class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int result = 100;
        vector<int> T(26), M(26);
        for (char c : s)
            ++M[c - 'a'];
        for (char c : target)
            ++T[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (T[i] > 0)
                result = min( result, M[i] / T[i] );
        return result;
    }
};
