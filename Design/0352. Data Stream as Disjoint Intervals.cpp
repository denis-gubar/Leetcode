class SummaryRanges {
public:
    template<typename T>
    struct IntervalTree
    {
        void update(T first, T last, bool isAdd)
        {
            auto it = points.lower_bound({ first, false });
            if (it != points.end() && it->first == first)
            {
                if (it->second == isAdd)
                    it = points.erase(it);
                else
                    ++it;
            }
            else
            {
                if (it == points.begin() || prev(it)->second == isAdd)
                {
                    it = points.insert({ first, !isAdd }).first;
                    ++it;
                }
            }
            while (true)
            {
                if (it == points.end() || it->first > last)
                {
                    if ((it == points.end() || !it->second) == isAdd)
                        it = points.insert({ last, isAdd }).first;
                    break;
                }
                if (it->first < last)
                    it = points.erase(it);
                else
                {
                    if (it->second != isAdd)
                        it = points.erase(it);
                    else
                        ++it;
                }
            }
        }
        void add(T first, T last)
        {
            update(first, last, true);
        }
        void remove(T first, T last)
        {
            update(first, last, false);
        }
        void print()
        {
            for (pair<T, bool> x : points)
                if (!x.second)
                    cout << x.first << ' ';
                else
                    cout << "- " << x.first << '
';
            cout << string(40, '-') << '
';
        }
        set<pair<T, bool>> points;
    };
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        IT.add(val, val + 1);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto it = IT.points.begin(); it != IT.points.end(); ++it)
        {
            result.push_back({ it->first, it->first });
            ++it;
            result.back().back() = it->first - 1;
        }
        return result;
    }
    IntervalTree<int> IT;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
