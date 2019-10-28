class SnapshotArray {
public:
	SnapshotArray(int length) {
		history = vector<vector<pair<int, int>>>(length + 1);
		snap_id = 0;
	}

	void set(int index, int val) {
		if (history[index].empty() || history[index].back().first != snap_id)
			history[index].push_back({ snap_id, val });
		else
			history[index].back().second = val;
	}

	int snap() {
		++snap_id;
		return snap_id - 1;
	}

	int get(int index, int snap_id) {
		auto it = lower_bound(history[index].begin(), history[index].end(), pair<int, int>{ snap_id + 1, 0 });
		if (it == history[index].begin()) return 0;
		--it;
		return it->second;
	}
	vector<vector<pair<int, int>>> history;
	int snap_id;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */