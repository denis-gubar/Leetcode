class BrowserHistory {
public:
	BrowserHistory(string homepage) {
		data.push_back(homepage);
		pos = 0;
	}

	void visit(string url) {
      data.resize(pos + 2);
			++pos;
			data[pos] = url;
	}

	string back(int steps) {        
				pos = max(0, pos - steps);
        return data[pos];
	}

	string forward(int steps) {
			pos = min(static_cast<int>(data.size()) - 1, pos + steps);
      return data[pos];
	}
	vector<string> data;
	int pos;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */