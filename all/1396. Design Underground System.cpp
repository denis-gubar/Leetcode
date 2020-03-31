class UndergroundSystem {
public:
	struct Visit
	{
		string stationName;
		int time;
	};
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		M[id] = { stationName, t };
	}

	void checkOut(int id, string stationName, int t) {
		string inName = M[id].first;
		int inT = M[id].second;
		V[{inName, stationName}].first += t - inT;
		++V[{inName, stationName}].second;
	}

	double getAverageTime(string startStation, string endStation) {
		return 1.0 * V[{startStation, endStation}].first / V[{startStation, endStation}].second;
	}
	map<int, pair<string, int>> M;
	map<pair<string, string>, pair<int, int>> V;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */