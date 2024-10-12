class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int result = 0;
        int const B = buses.size();
        passengers.push_back(1 << 30);
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int pos = 0;
        for (int i = 0; i < B; ++i)
        {
            int emptySeats = capacity;
            while (emptySeats > 0 && passengers[pos] <= buses[i])
                result = passengers[pos], --emptySeats, ++pos;
            if (emptySeats > 0)
                result = buses[i];
        }
        auto it = lower_bound(passengers.begin(), passengers.end(), result);
        while (*it == result)
        {
            --result;
            if (it == passengers.begin())
                break;
            --it;
        }
        return result;
    }
};
