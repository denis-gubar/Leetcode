class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       return remove(begin(nums), end(nums), val) - begin(nums);
    }
};