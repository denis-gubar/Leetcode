
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int N = nums.size();
        vector<vector<vector<int>::iterator>> A(N);
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            int count = 0;
            for (auto last = it; last != nums.end(); ++last)
            {
                if (*last % p == 0)
                    ++count;
                if (count > k)
                    break;
                A[last - it].push_back(it);
            }
        }
        int result = 0;
        for (int i = 0; i < N; ++i)
        {
            sort(A[i].begin(), A[i].end(), [i](vector<int>::iterator a, vector<int>::iterator b)
                {
                    return lexicographical_compare(a, a + i + 1, b, b + i + 1);
                });
            A[i].resize(unique(A[i].begin(), A[i].end(), [i](vector<int>::iterator a, vector<int>::iterator b)
                {
                    return equal(a, a + i + 1, b, b + i + 1);
                }) - A[i].begin());
            result += A[i].size();
        }
        return result;
    }
};
