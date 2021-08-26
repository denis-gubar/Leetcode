class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int total = 0;
        for(int x : arr1)
            total ^= x;
        int result = 0;
        for(int x : arr2)
            result ^= total & x;
        return result;
    }
};