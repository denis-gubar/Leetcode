class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int N = regular.size();
        vector<long long> result(N);
        long long R = 0, E = expressCost;
        for(int i = 0; i < N; ++i)
        {
            long long NR = min(R + regular[i], E + regular[i]);
            long long NE = min(R + express[i] + expressCost, E + express[i]);
            R = NR, E = NE;
            result[i] = min(R, E);
        }
        return result;
    }
};