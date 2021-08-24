int F[100][100][100];

class Solution {
public:
    int calc(vector<int> const& boxes, int left, int right, int k)
    {
        if (left > right)
            return 0;
        while(left < right && boxes[right] == boxes[right - 1])
        {
            --right;
            ++k;
        }
        if (F[left][right][k] == 0)
        {
            F[left][right][k] = calc(boxes, left, right - 1, 0) + (k + 1) * (k + 1);
            for(int middle = left; middle < right; ++middle)
                if (boxes[middle] == boxes[right])
                    F[left][right][k] = max(F[left][right][k], 
                                            calc(boxes, left, middle, k + 1) +
                                            calc(boxes, middle + 1, right - 1, 0)
                                           );
        }
        return F[left][right][k];
    }
    int removeBoxes(vector<int>& boxes) {
        memset(F, 0, sizeof(F));
        int N = boxes.size();
        return calc(boxes, 0, N - 1, 0);
    }
};