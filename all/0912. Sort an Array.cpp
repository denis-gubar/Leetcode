class Solution {
public:
    void sortArray(vector<int>::iterator first, vector<int>::iterator last)
    {
        int N = last - first;
        if (N < 2)
            return;
        vector<int>::iterator middle = first + N / 2;
        vector<int> buffer;
        buffer.reserve(N);
        sortArray(first, middle);
        sortArray(middle, last);
        vector<int>::iterator left = first, right = middle;
        while (left != middle || right != last)
        {
            if (right == last || left != middle && *left <= *right)
                buffer.push_back(*left), ++left;
            else
                buffer.push_back(*right), ++right;
        }
        copy(buffer.begin(), buffer.end(), first);
    }
    vector<int> sortArray(vector<int>& nums) {
        sortArray(nums.begin(), nums.end());
        return nums;
    }
};
