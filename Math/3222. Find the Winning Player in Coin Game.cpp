class Solution {
public:
    string losingPlayer(int x, int y) {
        vector<string> results{ "Alice", "Bob" };
        bool result = true;
        while (x >= 1 && y >= 4)
        {
            x -= 1, y -= 4;
            result = !result;
        }
        return results[result];
    }
};
