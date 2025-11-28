class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int x = left; x <= right; ++x)
        {
            int z = x;
            while(z > 0)
            {
                int d = z % 10;
                if (d == 0 || x % d != 0)
                    break;
                z /= 10;
            }
            if (z == 0)
                result.push_back(x);
        }
        return result;
    }
};