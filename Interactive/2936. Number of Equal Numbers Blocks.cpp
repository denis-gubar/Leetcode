/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int countBlocks(BigArray* nums) {
        int result = 0;
        long long const N = nums->size();
        long long idx = 0;
        while (idx < N)
        {
            ++result;
            long long a = idx, b = N;
            long long value = nums->at(a);
            while (a + 1 < b)
            {
                long long m = (a + b) / 2;
                if (nums->at(m) == value)
                    a = m;
                else
                    b = m;
            }
            idx = b;
        }
        return result;
    }
};
