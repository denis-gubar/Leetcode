class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int result = 0;
        while (mainTank >= 5)
        {
            mainTank -= 5;
            result += 50;
            if (additionalTank > 0)
                --additionalTank, ++mainTank;
        }
        result += mainTank * 10;
        return result;
    }
};
