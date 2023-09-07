class Solution {
public:
    template<typename T>
    vector<int> topological_sort(T const& connectivity, vector<int>& degree, int N)
    {
        vector<int> result;
        result.reserve(N);
        queue<int> Q;
        for (int V = 0; V < N; ++V)
            if (degree[V] == 0)
                Q.push(V);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            result.push_back(V);
            for (int U : connectivity[V])
                if (--degree[U] == 0)
                    Q.push(U);
        }
        for (int V = 0; V < N; ++V)
            if (degree[V] > 0)
                return {};
        return result;
    }
    vector<int> sortItems(int N, int M, vector<int>& group, vector<vector<int>>& beforeItems) {        
        for (int& g : group)
            if (g == -1)
                g = M, ++M;
        vector<vector<int>> connectivity_items(N);
        vector<int> group_degree(M), item_degree(N);
        vector<unordered_set<int>> connectivity_groups(M);
        for (int V = 0; V < N; ++V)
        {
            for (int U : beforeItems[V])
            {
                if (group[V] != group[U] && connectivity_groups[group[U]].insert(group[V]).second)
                    ++group_degree[group[V]];
                connectivity_items[U].push_back(V);
                ++item_degree[V];
            }
        }
        vector<int> sorted_groups = topological_sort(connectivity_groups, group_degree, M);
        if (sorted_groups.empty())
            return {};
        vector<int> sorted_items = topological_sort(connectivity_items, item_degree, N);
        if (sorted_items.empty())
            return {};
        vector<int> result;
        result.reserve(N);
        vector<vector<int>> item_groups(M);
        for (int i : sorted_items)
            item_groups[group[i]].push_back(i);
        for (int g : sorted_groups)
            copy(item_groups[g].begin(), item_groups[g].end(), back_inserter(result));
        return result;
    }
};
