class MyCalendarTwo {
public:
	MyCalendarTwo() {

	}

	bool book(int start, int end) {
		auto it = M.upper_bound(start);
		if (it != M.begin() && prev(it)->second == 2)
			return false;
		while (it != M.end() && it->first < end)
		{
			int balance = it->second;
			if (balance == 2)
				return false;
			++it;
		}
		if (M.upper_bound(start) == M.begin())
			M[start] = 1;
		else
			M[start] = prev(M.upper_bound(start))->second + 1;
		for(it = M.upper_bound(start); it != M.end() && it->first < end; ++it)
			++it->second;
		if (M.find(end) == M.end())
			M[end] = prev(it)->second - 1;
		return true;
	}
	map<int, int> M;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */