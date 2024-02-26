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
        set<int> freeRooms;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            freeRooms.insert(i);
        priority_queue<Event> PQ;
        queue<int> Q;
        for(int i = 0, M = meetings.size(); i < M; ++i)
        {
            int const& start = meetings[i][0];
            PQ.push({ start, State::ADD, i });
        }
        while (!PQ.empty())
        {
            Event event = PQ.top(); PQ.pop();
            if (event.state == State::REMOVE)
                freeRooms.insert(event.index);
            else
                Q.push(meetings[event.index][1] - meetings[event.index][0]);
            while (!Q.empty() && !freeRooms.empty())
            {
                int room = *freeRooms.begin();
                freeRooms.erase(freeRooms.begin());
                ++A[room];
                int t = Q.front(); Q.pop();
                PQ.push({ event.time + t, State::REMOVE, room });
            }
        }
        return max_element(A.begin(), A.end()) - A.begin();
    }
};
