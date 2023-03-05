class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long result = 0;
        unordered_map<int, int> M;
        for (int x : basket1)
            ++M[x];
        for (int x : basket2)
            --M[x];
        vector<int> A, B;
        for (auto [key, value] : M)
        {
            if (value % 2 != 0)
                return -1;
            if (value < 0)
                for (int i = 0; i < -value; i += 2)
                    A.push_back(key);
            else
                for (int i = 0; i < value; i += 2)
                    B.push_back(key);
        }
        int x = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
        int N = A.size();
        for (int i = N - 1; i >= 0; --i)            
            result += min(2 * x, min(A[i], B[i]));
        return result;
    }
};
