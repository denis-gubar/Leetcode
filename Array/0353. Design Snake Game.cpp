class SnakeGame {
public:
    int score;
    int N, M;
    vector<vector<int>> food;
    int x, y;
    array<int, 4> const dx{ -1, 0, 1, 0 };
    array<int, 4> const dy{ 0, -1, 0, 1 };
    string const D{ "ULDR" };
    vector<vector<bool>> grid;
    deque<pair<int, int>> Q;
    SnakeGame(int width, int height, vector<vector<int>>& food):
        score(0), N(height), M(width), food(food.rbegin(), food.rend()),
        x(0), y(0), grid(vector<vector<bool>>(N, vector<bool>(M))) {
        grid[x][y] = true;
        Q.emplace_front(x, y);
    }
    
    int move(string direction) {
        int z = D.find(direction[0]);
        int nx = x + dx[z];
        int ny = y + dy[z];
        if (nx == N || nx == -1 || ny == -1 || ny == M)
            return -1;
        if (!food.empty() && nx == food.back()[0] && ny == food.back()[1])
        {
            ++score;
            Q.emplace_front(nx, ny);
            grid[nx][ny] = true;
            food.pop_back();
            x = nx, y = ny;
            return score;
        }
        grid[Q.back().first][Q.back().second] = false;
        Q.pop_back();
        if (grid[nx][ny])
            return -1;
        grid[nx][ny] = true;
        Q.emplace_front(nx, ny);
        x = nx, y = ny;
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
