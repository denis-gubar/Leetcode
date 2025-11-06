class Solution {
public:
    string lexSmallest(string s) {
        string result(s);
        int const N = s.size();
        string t(s);
        for (int i = 0; i < N; ++i)
        {
            reverse(t.begin(), t.begin() + i + 1);
            if (result > t)
                result = t;
            reverse(t.begin(), t.begin() + i + 1);
            reverse(t.rbegin(), t.rbegin() + i + 1);
            if (result > t)
                result = t;
            reverse(t.rbegin(), t.rbegin() + i + 1);
        }
        return result;
    }
};
