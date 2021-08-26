class UndergroundSystem {
public:
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		running[id] = { stationName, t };
	}

	void checkOut(int id, string stationName, int t) {
		auto it = running.find(id);
		string startStation = it->second.first;
		int startTime = it->second.second;
		pair<int, int>& x = M[{startStation, stationName}];
		x.first += t - startTime;
		++x.second;
		running.erase(it);
	}

	double getAverageTime(string startStation, string endStation) {
		pair<int, int> const& x = M[{startStation, endStation}];
		return 1.0 * x.first / x.second;
	}
	unordered_map<int, pair<string, int>> running;
	map<pair<string, string>, pair<int, int>> M;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */