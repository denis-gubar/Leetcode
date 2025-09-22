class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int const N = nums1.size();
        unordered_map<int, char> M;
        string target;
        for (int x : nums2)
        {
            if (M.find(x) == M.end())
                M[x] = 'a' + M.size();
            target += M[x];
        }
        string s, current, rest;
        for (int x : nums1)
            s += M[x];
        unordered_set<string> S;
        S.insert(s);
        queue<pair<string, int>> Q;
        Q.push({ s, 0 });
        while(!Q.empty())
        {
            s = Q.front().first;
            int t = Q.front().second; Q.pop();
            if (s == target)
                return t;
            for(int L = 0; L < N; ++L)
                for (int R = L; R < N; ++R)
                {
                    rest.clear();
                    for (int i = 0; i < L; ++i)
                        rest += s[i];
                    for (int i = R + 1; i < N; ++i)
                        rest += s[i];
                    int const K = rest.size();
                    for (int i = 0; i <= K; ++i)
                    {
                        current.clear();
                        current += rest.substr(0, i);
                        current += s.substr(L, R - L + 1);
                        current += rest.substr(i, K - i);
                        if (S.insert(current).second)
                            Q.push({ current, t + 1 });
                    }
                }
        }
        return -1;
    }
};
