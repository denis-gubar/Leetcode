using bit = bitset<1'001>;
class Solution {
public:
    vector<bit> F;
    int A, B, T;
    bool calc(int a, int b)
    {
        if (a == T || b == T || a + b == T)
            return true;
        auto go = [this](int a, int b)
            {
                if (!F[a][b])
                {
                    F[a][b] = 1;
                    return calc(a, b);
                }
                return false;
            };
        if (go(A, b) || go(a, B) || go(0, b) || go(a, 0))
            return true;
        if (a + b <= A && go(a + b, 0))
            return true;
        if (a + b <= B && go(0, a + b))
            return true;
        if (a + b > A && go(A, a + b - A))
            return true;
        if (a + b > B && go(a + b - B, B))
            return true;
        return false;
    }
    bool canMeasureWater(int a, int b, int target) {
        if (a > b)
            swap(a, b);
        A = a, B = b, T = target;
        F = vector<bit>(a + 1);
        F[0][0] = 1;
        return calc(0, 0);
    }
};
