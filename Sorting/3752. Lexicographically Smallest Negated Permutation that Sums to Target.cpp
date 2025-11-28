class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int N, long long target) {
        if (N < 8)
        {            
            vector<int> result;
            for (int mask = 0; mask < (1 << N); ++mask)
            {
                vector<int> A(N);
                iota(A.begin(), A.end(), 1);
                vector<int> B;
                do
                {
                    int sum = 0;
                    for (int k = 0; k < N; ++k)
                        if (mask & (1 << k))
                            sum += A[k];
                        else
                            sum -= A[k];
                    B = A;
                    if (sum == target)
                    {
                        for (int k = 0; k < N; ++k)
                            if ((mask & (1 << k)) == 0)
                                B[k] = -B[k];
                        if (result.empty() || result > B)
                            result = B;
                    }
                } while (next_permutation(A.begin(), A.end()));                
            }
            return result;
        }
        else
        {
            bool flag = false;
            int t = abs(target) % 4;
            int n = N % 4 + 4;
            for (int mask = 0; mask < (1 << n); ++mask)
            {
                vector<int> A(n);
                iota(A.begin(), A.end(), 1);
                do
                {
                    int sum = 0;
                    for (int k = 0; k < n; ++k)
                        if (mask & (1 << k))
                            sum += A[k];
                        else
                            sum -= A[k];
                    if (sum == t)
                    {
                        flag = true;
                        break;
                    }
                } while (next_permutation(A.begin(), A.end()));
                if (flag)
                    break;
            }
            if (!flag)
                return {};
        }        
        long long total = 1LL * N * (N + 1) / 2;
        if (abs(total) < abs(target))
            return {};
        vector<int> result;
        result.reserve(N);
        long long left = 0;
        int HWM = N;
        while (left + total > target)
        {
            if (target < 0)
            {
                if (left - total <= target)
                    if (left + total - 2 * HWM >= target)
                        left -= HWM, total -= HWM, result.push_back(-HWM), --HWM;
                    else
                    {
                        int x = (left + total - target) / 2;
                        result.push_back(-x);
                        for (int k = 1; k <= HWM; ++k)
                            if (k != x)
                                result.push_back(k);
                        return result;
                    }
                else
                    break;
                continue;
            }
            if (left + total - 2 * HWM >= target)
                left -= HWM, total -= HWM, result.push_back(-HWM), --HWM;
            else
            {
                int x = (left + total - target) / 2;
                result.push_back(-x);
                for (int k = 1; k <= HWM; ++k)
                    if (k != x)
                        result.push_back(k);
                return result;
            }
        }
        for (int k = 1; k <= HWM; ++k)
            result.push_back(k);
        return result;
    }
};
