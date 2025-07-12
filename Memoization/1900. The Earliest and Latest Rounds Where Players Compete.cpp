class Solution {
public:
    vector<int> earliestAndLatest(int N, int firstPlayer, int secondPlayer) {
        vector<int> result{ 10, 0 };
        unordered_set<unsigned int> S;
        --firstPlayer, --secondPlayer;
        unsigned int const goodMask = (1 << firstPlayer) | (1 << secondPlayer);
        S.insert((1 << N) - 1);
        vector<char> A;
        A.reserve(N);
        int round = 0;  
        while (!S.empty())
        {
            ++round;
            unordered_set<unsigned int> NS;
            for (int const mask : S)
            {
                A.clear();
                for (unsigned int k = 0; k < N; ++k)
                    if (mask & (1 << k))
                        A.push_back(k);
                unsigned int const M = A.size();
                bool flag = false;
                for (unsigned int z = 0; z < M / 2; ++z)
                {
                    if (A[z] == firstPlayer && A[M - 1 - z] == secondPlayer)
                    {
                        flag = true;
                        result[0] = min(result[0], round);
                        result[1] = max(result[1], round);
                    }
                }
                if (flag)
                    continue;
                for (unsigned curMask = 0, endMask = 1 << (M / 2); curMask < endMask; ++curMask)
                {
                    unsigned int new_mask = 0;
                    for (unsigned int z = 0; z < M / 2; ++z)
                        if (A[z] == firstPlayer || A[z] == secondPlayer || 
                            (curMask & (1 << z)) > 0 &&
                            A[M - 1 - z] != firstPlayer && 
                            A[M - 1 - z] != secondPlayer)
                            new_mask |= 1 << A[z];
                        else
                            new_mask |= 1 << A[M - 1 - z];
                    if (M % 2 > 0)
                        new_mask |= 1 << A[M / 2];
                    NS.insert(new_mask);
                }
            }
            S.swap(NS); NS.clear();
        }
        return result;
    }
};
