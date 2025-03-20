class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result = 0;
        int const N = fruits.size();
        int const B = sqrt(N);
        list<pair<multiset<int>, list<int>>> L;
        for (int i = 0; i < N; ++i)
        {
            if (i % B == 0)
                L.push_back({});
            L.back().first.insert(baskets[i]);
            L.back().second.push_back(baskets[i]);
        }
        for (int i = 0; i < N; ++i)
        {
            bool flag = false;            
            for (auto it = L.begin(); it != L.end(); ++it)
                if (*prev(it->first.end()) >= fruits[i])
                {
                    flag = true;                    
                    for (auto itA = it->second.begin(); ; ++itA)
                        if (*itA >= fruits[i])
                        {
                            it->first.erase(it->first.find(*itA));
                            it->second.erase(itA);
                            break;
                        }
                    if (it->first.empty())
                        L.erase(it);
                    break;
                }
            result += 1 - flag;
        }
        return result;
    }
};
