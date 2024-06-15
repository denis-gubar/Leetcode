static const array dx{ 0, 1, 0, -1 };
static const array dy{ 1, 0, -1, 0 };
class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int result = 0;
        int N = room.size(), M = room[0].size();
        vector<vector<char>> visited(N, vector<char>(M));
        int x = 0, y = 0, dir = 0;        
        while (true)
        {
            if (visited[x][y] & (1 << dir))
                break;
            if (!visited[x][y])
                ++result;
            visited[x][y] |= 1 << dir;
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && room[nx][ny] == 0)
            {
                x = nx, y = ny;
                continue;
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};
