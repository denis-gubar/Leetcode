class Solution {
public:
    long long totalCost(vector<int>& costs, int K, int candidates) {
        long long result = 0;
        int const N = costs.size();
        auto comp = [](pair<int, int> a, pair<int, int> b) -> bool
            {
                return pair<int, int>{-a.first, -a.second} < pair<int, int>{-b.first, -b.second};
            };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> PQ(comp);
        int a = N - 1, b = 0;
        if (candidates * 2 >= N)
            for (int i = 0; i < N; ++i)
                PQ.push({ costs[i], i });
        else
        {
            for (int i = 0, j = N - 1; i < candidates; ++i, --j)
                PQ.push({ costs[i], i }), PQ.push({ costs[j], j });
            a = candidates, b = N - candidates - 1;
        }
        for (int i = 0; i < K; ++i)
        {
            pair<int, int> P = PQ.top(); PQ.pop();
            if (a <= b)
            {
                if (P.second < a)
                    PQ.push({ costs[a], a }), ++a;
                else
                    PQ.push({ costs[b], b}), --b;
            }
            result += P.first;
        }        
        return result;
    }
};
