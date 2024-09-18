class SeatManager {
public:
	SeatManager(int n) {
		for (int x = 1; x <= n; ++x)
			U.insert(x);
	}

	int reserve() {
		int result = *U.begin();
		U.erase(U.begin());
		return result;
	}

	void unreserve(int seatNumber) {
		U.insert(seatNumber);
	}
	set<int> U;
};
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */