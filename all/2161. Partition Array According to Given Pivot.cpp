class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int N = nums.size();
        vector<int> result(N);
        vector<int> A(N);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [pivot, &nums](int a, int b)
            {
                if (nums[a] == pivot || nums[b] == pivot)
                    return nums[a] < nums[b];
                if (nums[a] < pivot && pivot < nums[b])
                    return true;
                if (nums[a] < pivot && nums[b] < pivot)
                    return a < b;
				if (nums[a] > pivot && nums[b] > pivot)
					return a < b;
                return false;
            });
        for (int i = 0; i < N; ++i)
            result[i] = nums[A[i]];
        return result;
    }
};
