static int F[1'003][3];
class Solution {
public:
    int numTilings(int N) {
        int const MOD = 1'000'000'007;
        memset(F, 0, sizeof(F));
        F[0][1] = 1;
        auto update = [MOD](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        //2: ***
        //   ****
        //1: ***
        //   ***
        //0: ****
        //   ***
        for (int i = 0; i < N; ++i)
        {
            update(F[i][2], F[i][0]);
           
            update(F[i + 1][1], F[i][1]);
            update(F[i + 2][1], F[i][1]);
            update(F[i + 2][0], F[i][1]);
            update(F[i + 1][2], F[i][1]);

            update(F[i + 2][0], F[i][2]);
            update(F[i + 2][1], F[i][2]);
            
            update(F[i + 1][1], F[i][0]);            
        }
        return F[N][1];
    }
};
