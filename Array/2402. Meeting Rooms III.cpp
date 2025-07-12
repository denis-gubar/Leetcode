static unsigned long long freeRooms[2];
static int const BIT_COUNT = sizeof(freeRooms[0]) * 8;
class Solution {
public:
    enum State
    {
        ADD,
        REMOVE
    };
    struct Event
    {
        long long time;
        State state;
        int index;
        friend bool operator< (Event L, Event R)
        {
            return tie(R.time, L.state, R.index) < tie(L.time, R.state, L.index);
        }
    };
    int mostBooked(int N, vector<vector<int>>& meetings) {
        memset(freeRooms, -1, sizeof(freeRooms));
        auto first_bit = [N]() -> int
            {
                int offset = N;
                for(int i = 0; offset > 0; ++i, offset -= BIT_COUNT)
                    if (freeRooms[i])
                    {
                        unsigned long long const x = freeRooms[i] ^ (freeRooms[i] & (freeRooms[i] - 1));
                        if (offset >= BIT_COUNT || x < (1LL << offset))
                            return bit_width(x) - 1 + i * BIT_COUNT;
                    }
                return -1;
            };
        vector<int> A(N);
        priority_queue<Event> PQ;
        queue<int> Q;
        for (int i = 0, M = meetings.size(); i < M; ++i)
        {
            int const& start = meetings[i][0];
            PQ.push({ start, State::ADD, i });
        }
        while (!PQ.empty())
        {
            Event event = PQ.top(); PQ.pop();
            if (event.state == State::REMOVE)
                freeRooms[event.index / BIT_COUNT] |= 1LL << event.index % BIT_COUNT;
            else
                Q.push(meetings[event.index][1] - meetings[event.index][0]);
            while (!Q.empty() && first_bit() >= 0)
            {
                int room = first_bit();
                freeRooms[room / BIT_COUNT] ^= 1LL << (room % BIT_COUNT);
                ++A[room];
                int t = Q.front(); Q.pop();
                PQ.push({ event.time + t, State::REMOVE, room });
            }
        }
        return max_element(A.begin(), A.end()) - A.begin();
    }
}; 
