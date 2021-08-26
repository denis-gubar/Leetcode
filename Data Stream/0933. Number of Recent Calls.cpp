class RecentCounter {
public:
	RecentCounter() {
		pings.clear();
	}

	int ping(int t) {
		pings.push_back(t);
		int result = pings.end() - lower_bound(pings.begin(), pings.end(), t - 3000);
		return result;
	}
	vector<int> pings;
};