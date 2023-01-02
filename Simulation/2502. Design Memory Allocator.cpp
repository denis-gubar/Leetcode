class Allocator {
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
        set<pair<T, bool>> points;
    };
    Allocator(int n) {
        N = n;
        Free.add(0, n);
    }
    
    int allocate(int size, int mID) {
        for (auto it = Free.points.begin(); it != Free.points.end(); ++it, ++it)
        {
            auto nit = next(it);
            if (nit->first - it->first >= size)
            {
                int result = it->first;
                Free.remove(result, result + size);
                M[mID].push_back({ result, result + size });
                return result;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int result = 0;
        for (pair<int, int> P : M[mID])
        {
            Free.add(P.first, P.second);
            result += P.second - P.first;
        }
        M[mID].clear();
        return result;
    }
    int N;
    IntervalTree<int> Free;
    unordered_map<int, vector<pair<int, int>>> M;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
