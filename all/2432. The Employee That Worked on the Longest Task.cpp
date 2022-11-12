class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        logs.insert(logs.begin(), { -1, 0 });
        int result = 1;
        int N = logs.size();
        for (int i = 1; i < N; ++i)
        {
            int delta = logs[i][1] - logs[i - 1][1];
            if (delta > logs[result][1] - logs[result - 1][1] || delta == logs[result][1] - logs[result - 1][1] && logs[result][0] > logs[i][0])
                result = i;
        }        
        return logs[result][0];
    }
};
