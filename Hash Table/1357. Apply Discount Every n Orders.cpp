class Cashier {
public:
	Cashier(int n, int discount, vector<int>& products, vector<int>& prices):
		n(n), x(0), discount(discount)
	{
		for (int i = 0; i < products.size(); ++i)
			M[products[i]] = prices[i];
	}

	double getBill(vector<int> product, vector<int> amount) {
		++x;
		int d = 0;
		if (x == n)
			x = 0, d = discount;
		double result = 0;
		for (int i = 0; i < product.size(); ++i)
			result += M[product[i]] * amount[i];
		result = result - (d * result) / 100.0;
		return result;
	}
	map<int, int> M;
	int n, x, discount;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */