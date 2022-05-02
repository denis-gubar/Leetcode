class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int result = 0;
        sort(begin(stones), end(stones));
        while(stones.size() > 1)
        {
            int x = stones.back();
            int y = stones[stones.size() - 2];
            stones.pop_back();
            if (x == y)
                stones.pop_back();
            else
            {
                stones.back() = x - y;
                sort(begin(stones), end(stones));
            }
        }
        if (!stones.empty())
            result = stones[0];
        return result;
    }
};