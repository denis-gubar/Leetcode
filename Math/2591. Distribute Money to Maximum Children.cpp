class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1;
        money -= children;
        int x = money / 7;
        int k = money - x * 7;
        if (x == children && k == 0)
            return children;
        if (x >= children)
            return children - 1;
        if (k == 3 && x + 1 == children)
            return x - 1;
        return x;
    }
};
