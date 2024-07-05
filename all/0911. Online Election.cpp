static int F[5'000];
static int L[5'000];
class TopVotedCandidate {
public:
    int N;
    set<pair<pair<int, int>, int>> S;
    vector<pair<int, int>> P;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        N = persons.size();        
        memset(F, 0, sizeof(F));
        memset(L, -1, sizeof(L));
        P.reserve(N + 1);
        for (int i = 0; i < N; ++i)
        {
            int const p = persons[i];
            int& f = F[p];
            int& l = L[p];
            if (f > 0)
                S.erase(S.find({ { f, l }, p }));
            ++f;
            l = times[i];
            S.insert({ { f, l }, p });
            P.push_back({ l, prev(S.end())->second });
        }
        P.push_back({ 1 << 30, -1 });
    }
    
    int q(int t) {
        auto it = upper_bound(P.begin(), P.end(), pair<int, int>{ t, 1 << 30 });
        if (it == P.begin())
            return -1;
        --it;
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
