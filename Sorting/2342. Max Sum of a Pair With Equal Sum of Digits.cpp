class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int N = nums.size();
        vector<priority_queue<int>> A(91);
        for (int x : nums)
        {
            int a = -x;
            int total = 0;
            while (x)
            {
                total += x % 10;
                x /= 10;
            }
            A[total].push(a);
            if (A[total].size() > 2)
                A[total].pop();
        }
        int result = -1;
        for(auto& PQ: A)
            if (PQ.size() == 2)
            {
                int x = PQ.top(); PQ.pop();
                int y = PQ.top(); PQ.pop();
                result = max(result, -x - y);
            }
        return result;
    }
};
