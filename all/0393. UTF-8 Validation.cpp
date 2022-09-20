class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<int> A{ 
            0b10000000,
            0b10000000,
            0b11100000,
            0b11110000,
            0b11111000
        };
        vector<int> B{
            0b10000000,
            0b00000000,
            0b11000000,
            0b11100000,
            0b11110000
        };
        auto check = [&A, &B](int X, int pos)
        {
            return (X & A[pos]) == B[pos];
        };
        int N = data.size();
        data.push_back(0);
        data.push_back(0);
        data.push_back(0);
        for (int i = 0; i < N; )
        {
            bool isOk = false;
            for(int k = 1; k <= 4; ++k)
                if (check(data[i], k))
                {
                    isOk = true;
                    ++i;
                    for (int j = 1; j < k; ++j)
                    {
                        isOk &= check(data[i], 0);
                        ++i;
                    }                    
                    break;
                }
            if (!isOk)
                return false;
        }
        return true;
    }
};
