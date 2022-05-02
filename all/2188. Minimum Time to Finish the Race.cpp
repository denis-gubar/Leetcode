class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int N = tires.size();
        vector<int> F(21, 1 << 30);
        for (int i = 0; i < N; ++i)
        {
			int const& f = tires[i][0];
			int const& r = tires[i][1];
            long long t = 0;
            int x = 0;
            long long k = 1;
            while (true)
            {
                ++x;
                t += 1LL * f * k;
                k *= r;
                if (t >= (1 << 20))
                    break;
                F[x] = min<int>(t, F[x]);
            }            
        }
        vector<int> M(numLaps + 1, 1 << 28);
        M[0] = -changeTime;
        for (int i = 0; i < numLaps; ++i)
            for (int k = 1; k < 20 && i + k <= numLaps; ++k)
                M[i + k] = min(M[i + k], M[i] + F[k] + changeTime);
        return M[numLaps];
    }
};
