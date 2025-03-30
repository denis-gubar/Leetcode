class Solution {
public:
    int maxContainers(int N, int W, int maxWeight) {
        int result = 0;
        while (result + 1 <= N * N && (result + 1) * W <= maxWeight)
            ++result;
        return result;
    }
};
