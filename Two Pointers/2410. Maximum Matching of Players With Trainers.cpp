class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int result = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while (!players.empty() && !trainers.empty())
        {
            if (players.back() > trainers.back())
            {
                players.pop_back();
                continue;
            }
            ++result;
            players.pop_back();
            trainers.pop_back();
        }
        return result;
    }
};
