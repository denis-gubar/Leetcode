class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int const T = tasks.size(), W = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        if (strength == 0)
            pills = 0;
        int a = 0, b = min(T, W) + 1;
        auto calc = [&tasks, &workers, T, W, pills, strength](int m) -> bool
            {
                deque<int> D;
                int P = pills;
                for (int j = m - 1, i = W - 1; j >= 0; --j)
                {
                    while (i >= W - m && workers[i] + strength >= tasks[j])
                    {
                        D.push_front(workers[i]);
                        --i;
                    }
                    if (D.empty())
                        return false;
                    if (D.back() >= tasks[j])
                        D.pop_back();
                    else
                    {
                        if (P == 0)
                            return false;
                        --P;
                        D.pop_front();
                    }
                }
                return true;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
