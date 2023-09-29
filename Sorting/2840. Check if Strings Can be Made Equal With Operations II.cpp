class Solution {
public:
    string calc(string s)
    {
        string result, left, right;
        int N = s.size();
        for (int i = 0; i < N; ++i)
            if (i % 2 == 0)
                left += s[i];
            else
                right += s[i];
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        return left + right;
    }
    bool checkStrings(string s1, string s2) {
        return calc(s1) == calc(s2);
    }
};
