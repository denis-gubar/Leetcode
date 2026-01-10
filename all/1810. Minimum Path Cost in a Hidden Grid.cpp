static array const dx{ -1, 0, 1, 0 };
static array const dy{ 0, -1, 0, 1 };
static auto hash = [](int x, int y) -> int
    {
        return ((x + 1200) << 16) | (y + 1200);
    };
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
    template<typename Distance, typename NodeIndex>
    Distance dijkstra(unordered_map<int, int>& M, int const source, int const target)
    {
        Distance const MAX = numeric_limits<Distance>::max();
        unordered_map<NodeIndex, Distance> minDistance;
        minDistance[source] = 0;
        set<pair<Distance, NodeIndex>> activeVertices;
        activeVertices.insert({ 0, source });
        while (!activeVertices.empty())
        {
            int node = activeVertices.begin()->second;
            if (node == target)
                return activeVertices.begin()->first;
            int const y = (node & 0xFFFF) - 1200;
            int const x = (node >> 16) - 1200;
            activeVertices.erase(activeVertices.begin());
            for (int z = 0; z < 4; ++z)
            {
                int const nx = x + dx[z];
                int const ny = y + dy[z];
                int const h = ::hash(nx, ny);
                if (M.find(h) == M.end() || M[h] == 0)
                    continue;
                if (minDistance.find(h) == minDistance.end() || minDistance[h] > minDistance[node] + M[h])
                {
                    if (minDistance.find(h) != minDistance.end())
                        activeVertices.erase({ minDistance[h], h });
                    minDistance[h] = minDistance[node] + M[h];                    
                    activeVertices.insert({ minDistance[h], h });
                }
            }
        }
        return -1;
    }
    int findShortestPath(GridMaster& master) {
        unordered_map<int, int> M;
        string const directions = "URDL";        
        bool findTarget = false;
        int targetX = 0, targetY = 0;
        auto dfs = [&](this const auto& self, int x, int y) -> void
            {
                for (int z = 0; z < 4; ++z)
                {
                    int const nx = x + dx[z];
                    int const ny = y + dy[z];
                    int const h = ::hash(nx, ny);
                    if (M.find(h) == M.end())
                    {
                        if (!master.canMove(directions[z]))
                            continue;
                        M[h] = master.move(directions[z]);
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
        M[::hash(0, 0)] = 0;
        dfs(0, 0);
        if (!findTarget)
            return -1;        
        return dijkstra<int, int>(M, ::hash(0, 0), ::hash(targetX, targetY));
    }
};