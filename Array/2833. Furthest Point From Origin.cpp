class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int result = 0;
        for (int dx = -1; dx <= 1; dx += 2)
        {
            int balance = 0;
            for (char c : moves)
                if (c == 'L')
                    --balance;
                else if (c == 'R')
                    ++balance;
                else
                    balance += dx;
            result = max(result, abs(balance));
        }
        return result;
    }
};
