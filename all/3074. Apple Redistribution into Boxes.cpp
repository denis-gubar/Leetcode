class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int result = 1;
        sort(capacity.begin(), capacity.end());
        bool flag = false;
        for (int x : apple)
        {
            while (x > 0)
            {
                if (x > capacity.back())
                    x -= capacity.back(), capacity.pop_back(), flag = true, ++result;
                else
                    capacity.back() -= x, x = 0, flag = false;
            }
        }
        return result - flag;
    }
};
