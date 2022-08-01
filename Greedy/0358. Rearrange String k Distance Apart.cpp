class Solution {
public:
    string rearrangeString(string s, int k) {
        string result;
        vector<int> M(26), P(26, -k);
        int N = s.size();
        result.reserve(N);
        for (char c : s)
            ++M[c - 'a'];
        for (int i = 0; i < N; ++i)
        {
            int best = -1;
            for(int j = 0; j < 26; ++j)
                if (i - P[j] >= k && M[j] > 0)
                {
                    if (best == -1 || M[best] < M[j])
                        best = j;
                }
            if (best == -1)
                return {};
            result += best + 'a';
            --M[best];
            P[best] = i;
        }
        return result;
    }
};
