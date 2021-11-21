class Bank {
public:
	Bank(vector<long long>& balance): balance(balance), N(balance.size()) {
		
	}

	bool transfer(int account1, int account2, long long money) {
		if (account1 < 1 || account1 > N || account2 < 1 || account2 > N)
			return false;
		--account1, --account2;

		if (balance[account1] >= money)
		{
			balance[account1] -= money;
			balance[account2] += money;
			return true;
		}
		return false;
	}

	bool deposit(int account, long long money) {
		if (account < 1 || account > N)
			return false;
		--account;
		balance[account] += money;
		return true;
	}

	bool withdraw(int account, long long money) {
		if (account < 1 || account > N)
			return false;
		--account;
		if (balance[account] < money)
			return false;
		balance[account] -= money;
		return true;
	}
	int N;
	vector<long long> balance;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */