class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int K) {
        vector<int>& result = heights;
        int const N = heights.size();
        for (int i = 0; i < volume; ++i)
        {
            int x = K, y = heights[K];
            for (int pos = K - 1; pos >= 0; --pos)
                if (heights[pos] > y)
                    break;
                else if (heights[pos] < y)
                    x = pos, y = heights[pos];
            if (x < K)
            {
                ++heights[x];
                continue;
            }
            for (int pos = K + 1; pos < N; ++pos)
                if (heights[pos] > y)
                    break;
                else if (heights[pos] < y)
                    x = pos, y = heights[pos];
            ++heights[x];
        }
        return result;
    }
};
