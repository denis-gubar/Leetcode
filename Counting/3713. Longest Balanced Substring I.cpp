static short A[26];
class Solution {
public:
    int longestBalanced(string s) {
        int result = 0;
        int const N = s.size();
        memset(A, 0, sizeof(A));
        for (int first = 0; first < N; ++first)
        {
            unordered_map<short, short> M;
            for (int last = first; last < N; ++last)
            {
                ++M[s[last] - 'a'];
                if (last - first + 1 <= result)
                    continue;
                bool isOk = true;
                int v = M.begin()->second;
                for(auto [key, value]: M)
                    if (value != v)
                    {
                        isOk = false;
                        break;
                    }
                if (isOk)
                    result = last - first + 1;
            }
        }
        return result;
    }
};
