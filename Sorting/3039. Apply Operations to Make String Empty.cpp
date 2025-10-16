class Solution {
public:
    string lastNonEmptyString(string s) {
        string result;
        vector<int> M(26);
        for (char c : s)
            ++M[c - 'a'];
        int x = *max_element(M.begin(), M.end());
        reverse(s.begin(), s.end());
        for(char c : s)
            if (M[c - 'a'] == x)
            {
                M[c - 'a'] = 0;
                result += c;
            }
        reverse(result.begin(), result.end());
        return result;
    }
};
