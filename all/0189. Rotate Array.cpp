class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = (N - k % N) % N;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());        
    }
};