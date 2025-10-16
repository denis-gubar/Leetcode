static int F[50'002][17];
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int K) {
        long long result = 0;
        int const N = nums.size();
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&nums](int a, int b)
            {
                return nums[a] < nums[b];
            });
        for (int i = 0; i < N; ++i)
            F[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
        auto rmq = [](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return max(F[L][j], F[R - (1 << j) + 1][j]);
            };
        set<int> S;
        S.insert(-1);
        S.insert(N);
        //-sum, count
        priority_queue<pair<int, int>> PQ;
        int count = 0;
        auto addPQ = [&PQ, &count, K](int sum, int delta) -> bool
            {
                if (sum == 0 || delta == 0)
                    return false;
                if (count < K || -PQ.top().first < sum)
                {
                    PQ.push({ -sum, delta }), count += delta;
                    while (count > K && count - PQ.top().second >= K)
                        count -= PQ.top().second, PQ.pop();
                    return true;
                }
                return false;
            };
        for (int i = 0; i < N; ++i)
        {
            int const& pos = I[i];
            int const& value = nums[pos];
            auto add = [&pos, &value, &addPQ, &rmq](int L, int R)
                {
                    while (true)
                    {
                        int leftMax = rmq(L, pos);
                        int rightMax = rmq(pos, R);
                        int a = L, b = pos;
                        while (a + 1 < b)
                        {
                            int m = (a + b) / 2;
                            if (rmq(m, pos) == leftMax)
                                a = m;
                            else
                                b = m;
                        }
                        int left = a;
                        a = R, b = pos;
                        while (a + 1 < b)
                        {
                            int m = (a + b) / 2;
                            if (rmq(pos, m) == rightMax)
                                a = m;
                            else
                                b = m;
                        }
                        int right = a;
                        bool flag = false;
                        if (leftMax < rightMax)
                            flag = addPQ(rightMax - value, (pos - L + 1) * (R - right + 1));
                        else if (leftMax > rightMax)
                            flag = addPQ(leftMax - value, (left - L + 1) * (R - pos + 1));
                        else
                            flag = addPQ(rightMax - value, (pos - L + 1) * (R - right + 1) + (left - L + 1) * (R - pos + 1));
                        if (!flag)
                            return;
                        if (leftMax < rightMax)
                            R = right - 1;
                        else if (leftMax > rightMax)
                            L = left + 1;
                        else
                            R = right - 1, L = left + 1;
                    }
                };
            auto it = S.lower_bound(pos);
            int L = *prev(it) + 1;
            int R = *it - 1;
            add(L, R);
            S.insert(pos);
        }
        while (!PQ.empty())
        {
            int const sum = -PQ.top().first, delta = PQ.top().second; PQ.pop();
            count -= delta;
            int realDelta = max(min(count + delta, K) - count, 0);
            result += 1LL * sum * realDelta;
        }
        return result;
    }
};
