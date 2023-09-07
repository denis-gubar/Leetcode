class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int K) {
        long long result = 0;
        int N = items.size();
        unordered_map<int, vector<int>> M;
        unordered_map<int, int> counter;
        for (int i = 0; i < N; ++i)
        {
            int const& profit = items[i][0];
            int const& category = items[i][1];
            M[category].push_back(profit);
        }
        priority_queue<pair<int, int>> PQ;
        multiset<pair<int, int>> rest, selected;
        for (auto& [key, value] : M)
        {
            sort(value.begin(), value.end());
            PQ.push({ value.back(), key });            
        }
        int size = 0;
        for (int i = 0; !PQ.empty() && i < K; ++i)
        {
            pair<int, int> P = PQ.top(); PQ.pop();
            selected.insert(P);
            ++counter[P.second];
            vector<int> const& V = M[P.second];
            for (int j = 0, Z = V.size() - 1; j < Z; ++j)
                rest.insert({ V[j], P.second });
            ++size;
            result += P.first + 2 * size - 1;
        }
        for (int i = size; i < K; ++i)
        {
            ++counter[rest.rbegin()->second];
            result += rest.rbegin()->first;
            rest.erase(prev(rest.end()));
        }
        long long current = result;
        while (!rest.empty())
        {
            pair<int, int> P = *selected.begin(); selected.erase(selected.begin());
            if (--counter[P.second] == 0)
                current -= 2 * size - 1, --size;
            current -= P.first;
            ++counter[rest.rbegin()->second];
            selected.insert(*rest.rbegin());
            current += rest.rbegin()->first;
            rest.erase(prev(rest.end()));
            result = max(result, current);
        }
        return result;
    }
};
