class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int result = 0;
        for(; target > 1; ++result)
        {
            if (target % 2 == 0)
            {
                if (maxDoubles > 0)
                    --maxDoubles, target >>= 1;
                else
                    break;
            }
            else
                --target;
        }
        return result + target - 1;
    }
};
