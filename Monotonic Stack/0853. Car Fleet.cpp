class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result = 0;
        int const N = position.size();
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&position](int a, int b)
            {
                return position[a] < position[b];
            });
        for (int i = N - 1; i >= 0; )
        {
            int const si = target - position[I[i]];
            int const vi = speed[I[i]];
            int j = i - 1;
            for (; j >= 0; --j)
            {
                int const sj = target - position[I[j]];
                int const vj = speed[I[j]];
                if (1LL * si * vj < 1LL * sj * vi)
                    break;                    
            }
            i = j;
            ++result;
        }
        return result;
    }
};
