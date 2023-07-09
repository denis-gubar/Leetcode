class Solution {
public:
    int passThePillow(int n, int time) {
        int result = 1;
        int dir = 1;
        while (time > 0)
        {
            if (result + dir == 0)
                dir = -dir;
            else if (result + dir == n + 1)
                dir = -dir;
            result += dir;
            --time;
        }
        return result;
    }
};
