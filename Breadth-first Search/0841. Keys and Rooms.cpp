class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int const N = rooms.size();
        vector<bool> visited(N);
        function<void(int)> dfs = [&](int V) -> void
            {
                visited[V] = true;
                for (int U : rooms[V])
                    if (!visited[U])
                        dfs(U);
            };
        dfs(0);
        return accumulate(visited.begin(), visited.end(), 0) == N;
    }
};
