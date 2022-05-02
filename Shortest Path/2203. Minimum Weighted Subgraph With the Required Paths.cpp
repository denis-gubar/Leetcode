class Solution {
public:
    long long minimumWeight(int N, vector<vector<int>>& edges, int src1, int src2, int dest) {
        long long constexpr INF = 1LL << 40;
        long long result = INF;
        vector<unordered_map<int, int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
			int const& from = e[0];
			int const& to = e[1];
			int const& weight = e[2];
            if (auto it = connectivity[from].find(to); it == connectivity[from].end() || it->second > weight)
                connectivity[from][to] = weight;
        }
        set<pair<long long, int>> S;
        vector<vector<long long>> visited(4, vector<long long>(N, INF));
        visited[1][src1] = visited[2][src2] = 0;
        S.insert({ 1L, src1 });
        S.insert({ 2L, src2 });
        while (!S.empty())
        {
            auto [x, V] = *S.begin();
            S.erase(S.begin());
            long long time = x / 10;
            if (time > result)
                break;
            int state = x % 10;
            if (state == 3 && V == dest)
                result = time;
            for (auto [U, weight] : connectivity[V])
            {
                long long ntime = time + weight;
                if (visited[state][U] > ntime)
                {
                    visited[state][U] = ntime;
                    S.insert({ ntime * 10 + state, U });
                }
                if (state != 3 && visited[3 - state][U] < INF && visited[3][U] > visited[3 - state][U] + ntime)
                {
                    visited[3][U] = ntime + visited[3 - state][U];
                    S.insert({ visited[3][U] * 10 + 3, U });
                }
            }
        }
        if (result >= INF)
            result = -1;
        return result;
    }
};
