class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size(), min_dist = INT_MAX;
        string res = "impossible";
        vector<vector<pair<int, string>>> vis(m, vector<pair<int, string>>(n, make_pair(INT_MAX, "")));
        queue<tuple<int, int, int, string>> q; // {pos_x, pos_y, dist, instr}
        q.push( { ball[0], ball[1], 0, "" } );
        while (!q.empty()) {
            auto [i, j, dist, instr] = q.front();
            q.pop();
            if (vis[i][j] <= make_pair(dist, instr))
                continue;
            vis[i][j] = make_pair(dist, instr);
            if (i == hole[0] && j == hole[1]) {
                min_dist = dist;
                res = instr;
            }
            vector<tuple<int, int, char>> dirs = {{0, 1, 'r'}, {0, -1, 'l'},
                                                  {1, 0, 'd'}, {-1, 0, 'u'}};
            for (const auto [dx, dy, d] : dirs) {
                auto [x, y] = calc(maze, i, j, dx, dy, hole[0], hole[1]);
                int new_dist = dist + abs(x - i) + abs(y - j);
                string new_instr = instr + d;
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y] > make_pair(new_dist, new_instr))
                    q.push( { x, y, new_dist, new_instr } );
            }
        }
        return res;
    }

    pair<int, int> calc(vector<vector<int>>& maze, int ball_x, int ball_y, int dx, int dy, int hole_x, int hole_y) {
        while (true) {
            int new_x = ball_x + dx;
            int new_y = ball_y + dy;
            if (new_x < 0 || new_x >= maze.size() ||
                new_y < 0 || new_y >= maze[0].size() || maze[new_x][new_y] == 1)
                break;
            ball_x = new_x;
            ball_y = new_y;
            if (ball_x == hole_x && ball_y == hole_y)
                break;
        }
        return { ball_x, ball_y };
    }
};