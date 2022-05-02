class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> result(2);
        vector<int> lost(100'001);
        vector<bool> visited(100'001);
        for (int i = 0; i < matches.size(); ++i)
        {
            int const& winner = matches[i][0];
            int const& loser = matches[i][1];
            visited[winner] = visited[loser] = true;
            ++lost[loser];
        }
        for(int i = 0; i < 100'001; ++i)
            if (visited[i])
            {
                if (lost[i] < 2)
                    result[lost[i]].push_back(i);
            }
        return result;
    }
};
