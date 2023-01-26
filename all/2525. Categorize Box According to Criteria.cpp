class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = 1LL * length * width * height;
        bool isBulky = length >= 10'000 || width >= 10'000 || height >= 10'000 || volume >= 1'000'000'000LL;
        bool isHeavy = mass >= 100;
        if (isBulky && isHeavy)
            return "Both";
        if (isBulky)
            return "Bulky";
        if (isHeavy)
            return "Heavy";
        return "Neither";
    }
};
