class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int result = 0;
        int a00 = -(arr1[0] + arr2[0]);
        int a01 = -(arr1[0] - arr2[0]);
        int a10 = -(-arr1[0] + arr2[0]);
        int a11 = -(-arr1[0] - arr2[0]);
        int const N = arr1.size();
        for (int j = 1; j < N; ++j)
        {
            result = max(result, j +
                max({ arr1[j] + arr2[j] + a00,
                      arr1[j] - arr2[j] + a01,
                     -arr1[j] + arr2[j] + a10,
                     -arr1[j] - arr2[j] + a11 }));
            a00 = max(a00, -(arr1[j] + arr2[j] + j));
            a01 = max(a01, -(arr1[j] - arr2[j] + j));
            a10 = max(a10, -(-arr1[j] + arr2[j] + j));
            a11 = max(a11, -(-arr1[j] - arr2[j] + j));
        }
        return result;
    }
};

