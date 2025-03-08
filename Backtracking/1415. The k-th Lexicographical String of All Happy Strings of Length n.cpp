class Solution {
public:
    string getHappyString(int N, int K) {
        --K;
        if ((3 << (N - 1)) <= K)
            return {};
        string result(N, 'a');
        vector<vector<int>> const dx{ {1, 2}, {0, 2}, {0, 1} };
        int delta = 1 << (N - 1);
        int last = K / delta;
        result[0] += last;
        for (int i = 1; i < N; ++i)
        {
            K %= delta;
            delta >>= 1;
            int current = K / delta;
            result[i] += dx[last][current];
            last = dx[last][current];
        }
        return result;
    }
};
