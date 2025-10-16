static bool isInit = false;
static vector<bool> isPrime(1'000'001, true);
static void init()
{
    if (!isInit)
    {
        isInit = true;
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i <= 1'000'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k <= 1'000'000; k += i)
                    isPrime[k] = false;
    }
}
class Solution {
public:
    int minJumps(vector<int>& nums) {
        init();
        unordered_set<int> S;
        unordered_map<int, vector<int>> M;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int const& x = nums[i];
            if (!isPrime[x])
                continue;
            M[x].push_back(i);
            S.insert(x);
        }
        for (int i = 0; i < N; ++i)
        {
            int const& x = nums[i];
            if (isPrime[x])
                continue;
            int y = x;
            for (int d = 2; d * d <= y; ++d)
                if (y % d == 0)
                {
                    while (y % d == 0)
                        y /= d;
                    if (S.find(d) != S.end())
                        M[d].push_back(i);
                }
            if (y > 1 && S.find(y) != S.end())
                M[y].push_back(i);
        }
        queue<int> Q;
        Q.push(0); Q.push(0);
        vector<bool> visited(N);
        vector<bool> visitedPrimes(1'000'001);
        visited[0] = true;
        while (!Q.empty())
        {
            int const pos = Q.front(); Q.pop();
            int const t = Q.front(); Q.pop();
            if (pos == N - 1)
                return t;
            if (pos > 0 && !visited[pos - 1])
            {
                visited[pos - 1] = true;
                Q.push(pos - 1); Q.push(t + 1);
            }
            if (pos < N - 1 && !visited[pos + 1])
            {
                visited[pos + 1] = true;
                Q.push(pos + 1); Q.push(t + 1);
            }
            if (isPrime[nums[pos]] && !visitedPrimes[nums[pos]])
            {
                visitedPrimes[nums[pos]] = true;
                for (int nPos : M[nums[pos]])
                    if (!visited[nPos])
                    {
                        visited[nPos] = true;
                        Q.push(nPos); Q.push(t + 1);
                    }
            }
        }
        return -1;
    }
};
