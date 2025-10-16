static int base[1'500];
static unsigned char shift[1'500];
static short F[32];
class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int K) {
        long long result = 0;
        int const N = nums.size();
        for(int i = 0; i < N; ++i)
        {
            base[i] = nums[i];
            shift[i] = 0;
            while ((base[i] & 1) == 0)
                ++shift[i], base[i] >>= 1;
        }
        for (int start = 0; start < N; ++start)
        {
            int HWM = shift[start] + 1;
            F[HWM] = 1;
            int g = base[start];
            for (int j = HWM - 1; j >= 0; --j)
                F[j] = 0;
            result = max<long long>(result, g << HWM);
            for (int length = 2, i = start + 1; start + length <= N; ++length, ++i)
            {
                int HWMi = shift[i] + 1;
                g = gcd(g, base[i]);
                HWM = min(HWM, HWMi);
                if (HWM == HWMi && ++F[HWM] > K)
                    --HWM;
                result = max(result, 1LL * length * g * (1LL << HWM));
            }
        }
        return result;        
    }
};
