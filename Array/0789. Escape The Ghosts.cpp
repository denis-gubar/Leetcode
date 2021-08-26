class Solution {
public:
    bool escapeGhosts( vector<vector<int>>& ghosts, vector<int>& target ) {
        bool result = true;
        int time = abs(target[0]) + abs(target[1]);
        for (int i = 0; i < ghosts.size(); ++i)
            result &= time < (abs( target[0] - ghosts[i][0] ) + abs( target[1] - ghosts[i][1] ));
        return result;
    }
};