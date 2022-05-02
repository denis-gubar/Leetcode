class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int W = workers.size(), B = bikes.size();
        vector<int> result(W);
        vector<int> D(W * B), A(W * B);
        iota(A.begin(), A.end(), 0);
        for (int i = 0, k = 0; i < W; ++i)
            for (int j = 0; j < B; ++j, ++k)
                D[k] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        sort(A.begin(), A.end(), [B, &D](int a, int b)
            {
                if (D[a] != D[b])
                    return D[a] < D[b];
                int workerA = a / B;
                int workerB = b / B;
                if (workerA != workerB)
                    return workerA < workerB;
                int bikeA = a % B;
                int bikeB = b % B;
                return bikeA < bikeB;
            });
        vector<bool> visitedWorkers(W), visitedBikes(B);
        for (int k = 0; k < B * W; ++k)
        {
            int i = A[k] / B; 
            if (visitedWorkers[i])
                continue;
            int j = A[k] % B;
            if (visitedBikes[j])
                continue;
            visitedWorkers[i] = visitedBikes[j] = true;
            result[i] = j;
        }
        return result;
    }
};
