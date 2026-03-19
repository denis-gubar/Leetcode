class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int result = -1;
        int const N = capacity.size();
        for (int i = 0; i < N; ++i)
            if (capacity[i] >= itemSize && (result == -1 || capacity[result] > capacity[i]))
                result = i;
        return result;
    }
};
