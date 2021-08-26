class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> M;
        int cur = 0;
        M[0] = -1;
        int result = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            int shift = s[i] - '0';
            cur ^= 1 << shift;
            if (M.find(cur) == M.end())
                M[cur] = i;
            else
                result = max(result, i - M[cur]);
            for(int j = 0; j < 10; ++j)
            {
                int pre = cur ^ (1 << j);
                if (M.find(pre) != M.end())
                    result = max(result, i - M[pre]);
            }
        }
        return result;            
    }
};