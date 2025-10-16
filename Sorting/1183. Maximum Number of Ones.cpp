class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> A;
        for(int i = 1; i <= sideLength; ++i)
            for(int j = 1; j <= sideLength; ++j)
                A.push_back(((sideLength + width - i) / sideLength) * ((sideLength + height - j) / sideLength));
        sort(A.begin(), A.end());
        int N = A.size();
        return accumulate(A.begin() + N - maxOnes, A.end(), 0);
    }
};