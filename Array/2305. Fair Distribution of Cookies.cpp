class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int N = cookies.size();
        int a = 0, b = N * 100'000;
        auto calc = [&cookies, k, N](int m)
        {
            for (int x : cookies)
                if (x > m)
                    return false;
            vector<int> A(N);
            iota(A.begin(), A.end(), 0);            
            do 
            {
                int sum = 0, z = 1;
                for (int i = 0; i < N; ++i)
                    if (sum + cookies[A[i]] <= m)
                        sum += cookies[A[i]];
                    else
                        sum = cookies[A[i]], ++z;
                if (z <= k)
                    return true;
            } while (next_permutation(A.begin(), A.end()));
            return false;
        };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
