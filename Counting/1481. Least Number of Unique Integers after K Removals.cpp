class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> M;
        for(int x : arr)
            ++M[x];            
        vector<int> A;
        int N = M.size(), result = N;
        A.reserve(N);
        for(auto [key, value] : M)
            A.push_back(value);
        sort(A.begin(), A.end());
        for(int i = 0; k > 0 && i < N; ++i)
            if (A[i] <= k)
                --result, k -= A[i];
        return result;
    }
};