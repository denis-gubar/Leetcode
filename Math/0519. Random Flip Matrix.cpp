class Solution {
public:
    vector<pair<short, short>> P;
    short N, M;
    short count;
    Solution(short N, short M): N(N), M(M), count(0), gen(mt19937(rd())) {
        P.reserve(M * N);
        for (short i = 0; i < N; ++i)
            for (short j = 0; j < M; ++j)
                P.emplace_back(i, j);
    }
    
    vector<int> flip() {
        int randomPos = 0;
        if (count + 1 < N * M)
        {
            uniform_int_distribution<int> distribution(0, N * M - 1 - count);
            randomPos = distribution(gen);
        }
        vector<int> result{ P[randomPos].first, P[randomPos].second };
        ++count;
        if (randomPos != N * M - count)
            swap(P[randomPos], P[N * M - count]);
        return result;
    }
    
    void reset() {
        count = 0;
    }
    random_device rd;
    mt19937 gen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
