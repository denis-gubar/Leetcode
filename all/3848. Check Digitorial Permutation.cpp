static int F[10];
class Solution {
public:
    bool isDigitorialPermutation(int N) {
        F[0] = 1;
        for (int i = 1; i < 10; ++i)
            F[i] = i * F[i - 1];
        int x = N;
        int sum = 0;
        vector<int> A;
        while (x > 0)
        {
            A.push_back(x % 10);
            sum += F[x % 10];
            x /= 10;
        }
        sort(A.begin(), A.end());
        do
        {
            if (A[0] == 0)
                continue;
            int x = 0;
            for (int d : A)
                x = x * 10 + d;
            if (x == sum)
                return true;
        } while (next_permutation(A.begin(), A.end()));
        return false;
    }
};
