class Solution {
public:
    vector<int> nums;
    int m;
    int N;
    vector<int> A;
    vector<vector<char>> F;
    bool calc(char first, char last)
    {
        char& result = F[first][last];
        if (result < 0)
        {
            if (first + 1 >= last)
                result = true;
            else
            {
                result = false;
                for (char middle = first; middle < last; ++middle)
                    if ((first == middle || A[middle + 1] - A[first] >= m) &&
                        (middle + 1 == last || A[last + 1] - A[middle + 1] >= m))
                        result |= calc(first, middle) && calc(middle + 1, last);
            }
        }
        return result;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        N = nums.size();
        this->nums = nums;
        this->m = m;
        A.clear();
        A.push_back(0);
        partial_sum(nums.begin(), nums.end(), back_inserter(A));
        F = vector<vector<char>>(N, vector<char>(N, -1));
        return calc(0, N - 1);
    }
};
