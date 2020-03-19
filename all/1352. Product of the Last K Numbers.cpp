class ProductOfNumbers {
public:
	ProductOfNumbers() {
		data.push_back({ 1 });
	}

	void add(int num) {
		data.push_back({ num });
		for (int k = 2; k <= data.size(); k <<= 1)
		{
			int pos = data.size() - k;
			int p = data[data.size() - k / 2].back();
			p *= data[pos].back();
			data[pos].push_back(p);
		}
	}

	int getProduct(int k) {
		int result = 1;
		int n = 1;
		int power = 0;
        int x = 0;
		while (k)
		{
			if (k % 2 == 1)
            {
                x += n;
				result *= data[data.size() - x][power];
            }
			k >>= 1;
			n <<= 1;
			++power;
		}
        return result;
	}
	vector<vector<int>> data;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */