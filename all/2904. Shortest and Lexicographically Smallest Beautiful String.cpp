class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string result;
        int N = s.size();
        vector<int> A;
        for (int i = 0; i < N; ++i)
            if (s[i] == '1')
                A.push_back(i);
        int M = A.size();
        A.push_back(N);
        for (int i = 0; i + k <= M; ++i)
        {
            string t = s.substr(A[i], A[i + k - 1] - A[i] + 1);
            if (result.empty() || result.size() > t.size() || result.size() == t.size() && t < result)
                result = t;
        }
        return result;
    }
};
