class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size() / 3;
        multiset<int> left, middle, right;
        long long L = 0, R = 0;
        vector<int> A(nums.begin() + N, nums.end());        
        sort(A.begin(), A.end());
        for (int i = 0; i < N; ++i)
        {
            left.insert(nums[i]);
            L += nums[i];            
            middle.insert(A[i]);
            right.insert(A[N + i]);
            R += A[N + i];
        }
        long long result = L - R;
        for (int pivot = N; pivot < 2 * N; ++pivot)
        {
            int next = nums[pivot];
            long long delta = *left.rbegin() - next;
            if (delta > 0)
            {
                left.erase(prev(left.end()));
                left.insert(next);
                L -= delta;
            }
            if (auto it = right.find(next); it != right.end())
            {
                right.erase(it);
                R -= next;
                int x = *middle.rbegin();
                R += x;
                middle.erase(prev(middle.end()));
                right.insert(x);
            }
            else
                middle.erase(middle.find(next));
            result = min(result, L - R);
        }
        return result;
    }
};
