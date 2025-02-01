class Solution {
public:
    vector<vector<int>> connectivity;
    vector<pair<int, int>> E;
    int N;
    vector<int> result, nums;
    vector<int> A;
    unordered_map<int, vector<int>> visited;
    void calc(int V, int P, int L, int delta = 0)
    {
        if (!visited[nums[V]].empty() && visited[nums[V]].back() + 1 > L)
            L = visited[nums[V]].back() + 1;
        A.push_back(A.back() + delta);
        visited[nums[V]].push_back(A.size() - 1);
        int sum = A.back() - A[L];
        int const size = A.size() - L;
        if (sum > result[0])
            result[0] = sum, result[1] = size;
        else if (sum == result[0] && result[1] > size)
            result[1] = size;
        for (int e : connectivity[V])
        {
            int const U = E[e].first - V, length = E[e].second;
            if (U != P)
                calc(U, V, L, length);
        }
        A.pop_back();
        visited[nums[V]].pop_back();
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        result = { 0, 1 };
        this->nums = nums;
        N = nums.size();
        E.reserve(N);
        A.reserve(N + 1);
        A.push_back(0);
        connectivity = vector<vector<int>>(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            int const& Length = edges[i][2];
            connectivity[V].push_back(i);
            connectivity[U].push_back(i);
            E.emplace_back(V + U, Length);
        }
        calc(0, -1, 1);
        return result;
    }
};
