static int F[100'010];
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int const G = groups.size(), E = elements.size();
        vector<int> result(G);
        memset(F, -1, sizeof(F));
        unordered_set<int> S;
        for (int i = 0; i < E; ++i)
            if (S.insert(elements[i]).second)
                for (int delta = elements[i], x = delta; x <= 100'000; x += delta)
                    if (F[x] < 0)
                        F[x] = i;
        for (int i = 0; i < G; ++i)
            result[i] = F[groups[i]];
        return result;
    }
};
