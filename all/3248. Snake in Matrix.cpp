class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<string> strings{ "UP", "RIGHT", "DOWN", "LEFT" };
        array dx{ -1, 0, 1, 0 };
        array dy{ 0, 1, 0, -1 };
        int pos = 0;
        for (string const& s : commands)
        {
            int z = find(strings.begin(), strings.end(), s) - strings.begin();
            pos += n * dx[z] + dy[z];
        }
        return pos;
    }
};
