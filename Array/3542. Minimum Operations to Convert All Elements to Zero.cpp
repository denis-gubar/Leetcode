class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        stack<int> S;
        S.push(0);
        S.push(0);
        for (int x : nums)
        {
            int prev = -1;
            while (S.top() > x)
            {
                if (S.top() != prev)
                {
                    ++result;
                    prev = S.top();
                }
                S.pop();
            }
            S.push(x);
        }
        while (S.top() > 0)
        {
            int a = S.top(); S.pop();
            int b = S.top();
            if (a != b)
                ++result;
        }
        return result;
    }
};
