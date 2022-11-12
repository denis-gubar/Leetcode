class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        int N = neededTime.size();
        char prev = '$';
        int current = 0;
        for (int i = 0; i < N; ++i)
        {
            if (colors[i] == prev)
            {
                if (current >= neededTime[i])
                    result += neededTime[i];
                else
                    result += current, current = neededTime[i];
            }
            else
                current = neededTime[i];
            prev = colors[i];
        }
        return result;
    }
};
