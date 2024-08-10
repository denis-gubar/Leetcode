class Solution {
public:
    string getSmallestString(string s) {
        string result = s;
        int const N = s.size();
        for(int i = 1; i < N; ++i)
            if (s[i] % 2 == s[i - 1] % 2)
            {
                string t(s);
                swap(t[i], t[i - 1]);
                result = min(result, t);
            }
        return result;
    }
};
