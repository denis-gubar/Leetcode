class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> result;
        int const N = height.size();
        for (int i = 1; i < N; ++i)
            if (height[i - 1] > threshold)
                result.push_back(i);
        return result;
    }
};
