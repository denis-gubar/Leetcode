/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    int findShortestPath(GridMaster &master) {
        unordered_map<int, bool> M;
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        string const directions = "URDL";
        auto hash = [](int x, int y) -> int
            {
                return ((x + 1200) << 16) | (y + 1200);
            };
        bool findTarget = false;
        int targetX = 0, targetY = 0;
        auto dfs = [&](this const auto& self, int x, int y) -> void
            {
                for (int z = 0; z < 4; ++z)
                {
                    int const nx = x + dx[z];
                    int const ny = y + dy[z];
                    int const h = hash(nx, ny);
                    if (M.find(h) == M.end())
                    {
                        if (!(M[h] = master.canMove(directions[z])))
                            continue;
                        master.move(directions[z]);
                        if (!findTarget)
                        {
                            if (master.isTarget())
                                findTarget = true, targetX = nx, targetY = ny;
                        }
                        self(nx, ny);
                        master.move(directions[(z + 2) % 4]);
                    }
                }
            };
        M[hash(0, 0)] = true;
        dfs(0, 0);
        if (!findTarget)
            return -1;
        queue<int> Q;
        unordered_set<int> visited;
        Q.push(0), Q.push(0), Q.push(0), visited.insert(hash(0, 0));
        while (!Q.empty())
        {
            int const x = Q.front(); Q.pop();
            int const y = Q.front(); Q.pop();
            int const t = Q.front(); Q.pop();
            if (x == targetX && y == targetY)
                return t;
            for (int z = 0; z < 4; ++z)
            {
                int const nx = x + dx[z];
                int const ny = y + dy[z];
                int const h = hash(nx, ny);
                if (M.find(h) == M.end() || visited.find(h) != visited.end() || !M[h])
                    continue;
                Q.push(nx), Q.push(ny), Q.push(t + 1), visited.insert(hash(nx, ny));
            }
        };
        return -1;
    }
};
