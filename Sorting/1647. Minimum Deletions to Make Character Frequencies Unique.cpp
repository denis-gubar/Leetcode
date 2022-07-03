class Solution {
public:
    int minDeletions(string s) {
        int result = 0;
        vector<int> M(26);
        for (char c : s)
            ++M[c - 'a'];
        sort(M.begin(), M.end());
        int i = 25;
        while (i > 0)
        {
            if (M[i] <= M[i - 1])
            {
                int delta = min(M[i - 1], M[i - 1] - M[i] + 1);
                M[i - 1] -= delta;
                result += delta;
            }
            --i;
        }
        return result;
    }
};
