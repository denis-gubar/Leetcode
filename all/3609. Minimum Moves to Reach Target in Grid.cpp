class Solution {
public:
    pair<bool, int> check(int sx, int sy, int tx, int ty, int t = 0)
    {
        if (sx == tx && sy == ty)
            return { true, t };
        if (tx > ty)
            swap(tx, ty), swap(sx, sy);
        pair<bool, int> result{false, 0};
        if (ty % 2 == 0 && ty / 2 >= tx)
        {
            pair<bool, int> P = check(sx, sy, tx, ty / 2, t + 1);
            if (P.first)
            {
                if (!result.first)
                    result = P;
                else if (result.second > P.second)
                    result.second = P.second;
            }
        }
        if (ty - tx < tx)
        {
            pair<bool, int> P = check(sx, sy, tx, ty - tx, t + 1);
            if (P.first)
            {
                if (!result.first)
                    result = P;
                else if (result.second > P.second)
                    result.second = P.second;
            }
        }
        if (tx == ty)
        {
            pair<bool, int> P = check(sx, sy, 0, ty, t + 1);
            if (P.first)
            {
                if (!result.first)
                    result = P;
                else if (result.second > P.second)
                    result.second = P.second;
            }
        }        
        return result;
    }
    int minMoves(int sx, int sy, int tx, int ty) {
        pair<bool, int> P = check(sx, sy, tx, ty);
        if (!P.first)
            return -1;
        return P.second;
    }
};
