class Solution {
public:
    int integerReplacement(size_t n) {
        queue<size_t> Q;
        Q.push(n); Q.push(0);
        unordered_set<int> S;
        S.insert(n);
        while(!Q.empty())
        {            
            size_t x = Q.front(); Q.pop();
            size_t t = Q.front(); Q.pop();
            if (x == 1)
                return t;
            if (x % 2 == 0)
            {
                if (S.insert(x / 2).second)
                {
                    Q.push(x / 2); Q.push(t + 1);
                }
            }
            else
            {
                if (S.insert(x - 1).second)
                {
                    Q.push(x - 1); Q.push(t + 1);
                }
                if (S.insert(x + 1).second)
                {
                    Q.push(x + 1); Q.push(t + 1);
                }
            }
        }
        return -1;
    }
};