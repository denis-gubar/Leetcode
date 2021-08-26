/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dims = binaryMatrix.dimensions();
        int X = dims[0], Y = dims[1];
        int result = -1;
        for(int x = 0; x < X; ++x)
        {
            int a = 0, b = Y - 1, y = b;
            if (!binaryMatrix.get(x, y))
                continue;
            y = a;
            if (binaryMatrix.get(x, y))                
                return y;
            while(a + 1 < b)
            {
                int m = (a + b) / 2;
                y = m;
                if (binaryMatrix.get(x, y))
                    b = m;
                else
                    a = m;
            }
            if (result == -1 || result > b)
                result = b;
        }
        return result;
    }
};