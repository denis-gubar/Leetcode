class Solution {
public:
    int partitionString(string s) {
        int result = 1;
        int N = s.size();
        vector<int> M(26);
        for (char c : s)
        {
            int x = c - 'a';
            if (M[x] > 0)
            {
                M.assign(26, 0);
                ++result;
            }
            M[x] = 1;
        }
        return result;
    }
};
