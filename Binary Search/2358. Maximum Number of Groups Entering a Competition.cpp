class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int N = grades.size();
        sort(grades.begin(), grades.end());
        int result = 0;
        int size = 0, prev_size = 0, sum = 0, prev_sum = 0;
        for (int x : grades)
        {
            sum += x;
            ++size;
            if (sum > prev_sum && size > prev_size)
            {
                ++result;
                prev_sum = sum;
                sum = 0;
                prev_size = size;
                size = 0;
            }
        }
        return result;
    }
};
