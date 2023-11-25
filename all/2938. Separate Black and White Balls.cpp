class Solution {
public:
    long long minimumSteps(string s) {
        long long result = 0;
        int N = s.size();
        vector<int> A;
        for (int i = 0; i < N; ++i)
            if (s[i] == '0')
                A.push_back(i);
        int M = A.size();
        for (int i = 0; i < M; ++i)
            result += A[i] - i;
        return result;
    }
};
