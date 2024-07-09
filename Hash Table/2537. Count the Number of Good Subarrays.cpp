class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long result = 0;
        int const N = nums.size();
        long long balance = 0;
        int a = 0, b = 0;
        unordered_map<int, int> M;        
        while (true)
        {
            if (b == 0)
                while (b < N && balance < k)
                {
                    balance += M[nums[b]]++;
                    ++b;
                }
            if (balance < k)
                break;
            while (balance >= k && balance - (M[nums[a]] - 1) >= k)
                balance -= --M[nums[a]], ++a;
            result += a + 1;
            if (b == N)
                break;
            balance += M[nums[b]]++;
            ++b;
        }
        return result;
    }
};
