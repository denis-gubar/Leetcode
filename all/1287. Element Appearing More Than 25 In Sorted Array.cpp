class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int N = arr.size();
        int M = N / 4;
        for(int i = 0; i + M < N; ++i)
            if (arr[i + M] == arr[i])
                return arr[i];
        return -1;
    }
};