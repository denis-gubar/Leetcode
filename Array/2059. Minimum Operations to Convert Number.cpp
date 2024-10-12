static int F[1'001];
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int const N = nums.size();
        queue<int> Q;
        Q.push(start); Q.push(1);
        memset(F, -1, sizeof(F));
        F[start] = 0;
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int t = Q.front(); Q.pop();
            auto add = [t, goal, &Q](int x)
                {
                    if (x == goal)
                        return true;
                    if (x < 0 || x > 1000)
                        return false;
                    if (F[x] == -1)
                    {
                        F[x] = t;
                        Q.push(x); Q.push(t + 1);
                    }
                    return false;
                };
            for (int y : nums)
                if (add(x - y) || add(x + y) || add(x ^ y))
                    return t;
        }
        return -1;
    }
};
