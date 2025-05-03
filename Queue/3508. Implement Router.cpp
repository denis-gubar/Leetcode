class Router {
public:
    struct Packet
    {
        int timestamp;
        int source;
        int destination;
    };
    struct PacketCmp
    {
        bool operator()(Packet const& a, Packet const& b) const
        {
            return tie(a.timestamp, a.source, a.destination) < tie(b.timestamp, b.source, b.destination);
        }
    };
    int N;
    queue<Packet> Q;
    set<Packet, PacketCmp> S;
    unordered_map<int, deque<pair<int, int>>> M;
    unordered_map<int, set<pair<int, int>>> MD;
    Router(int memoryLimit): N(memoryLimit) {

    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet P{ timestamp, source, destination };
        bool result = S.insert(P).second;
        if (result)
        {
            Q.push(P);
            M[destination].push_back({ timestamp, source });
        }
        if (Q.size() > N)
            forwardPacket();
        return result;
    }
    
    vector<int> forwardPacket() {
        if (Q.empty())
            return {};
        Packet P = Q.front(); Q.pop();
        S.erase(S.find(P));
        MD[P.destination].insert({ P.timestamp, P.source });
        while (!MD[P.destination].empty())
        {
            pair<int, int> DP = M[P.destination].front();
            if (auto it = MD[P.destination].find(DP); it != MD[P.destination].end())
            {
                MD[P.destination].erase(it);
                M[P.destination].pop_front();
            }
            else
                break;
        }
        return { P.source, P.destination, P.timestamp };
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (M[destination].empty())
            return 0;
        auto it = lower_bound(M[destination].begin(), M[destination].end(), pair<int, int>{ endTime + 1, 0 });
        if (!MD[destination].empty())
        {
            int time = MD[destination].begin()->first;
            if (startTime <= time && time <= endTime)
                return (it - M[destination].begin()) - MD[destination].size();
        }
        auto it2 = lower_bound(M[destination].begin(), M[destination].end(), pair<int, int>{ startTime, 0 });
        return it - it2;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
