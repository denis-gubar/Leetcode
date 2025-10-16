class Solution {
public:
    int score(vector<string>& cards, char x) {
        int result = 0;
        int const N = cards.size();
        vector<int> A(26), B(26);
        int xx = 0, a = 0, b = 0;
        for (int i = 0; i < N; ++i)
            if (cards[i][0] == x && cards[i][1] == x)
                ++xx;
            else if (cards[i][0] == x)
                ++A[cards[i][1] - 'a'], ++a;
            else if (cards[i][1] == x)
                ++B[cards[i][0] - 'a'], ++b;
        int aa = a, bb = b;
        multiset<int> S1, S2;
        for (int i = 0; i < 26; ++i)
        {
            if (A[i] > 0)
                S1.insert(A[i]);
            if (B[i] > 0)
                S2.insert(B[i]);
        }
        if (xx >= a + b)
            xx = a + b;
        //result = min(xx, a + b);
        int current = 0;
        while (S1.size() > 1)
        {
            int x = *prev(S1.end());
            S1.erase(prev(S1.end()));
            int y = *prev(S1.end());
            S1.erase(prev(S1.end()));
            if (x > 1)
                S1.insert(x - 1);
            if (y > 1)
                S1.insert(y - 1);
            current += 1;
            a -= 2;
        }
        while (S2.size() > 1)
        {
            int x = *prev(S2.end());
            S2.erase(prev(S2.end()));
            int y = *prev(S2.end());
            S2.erase(prev(S2.end()));
            if (x > 1)
                S2.insert(x - 1);
            if (y > 1)
                S2.insert(y - 1);
            current += 1;
            b -= 2;
        }
        result = max(result, current);
        result += xx;
        result = min(result, (aa + bb + xx) / 2);
        return result;
    }
}; 
