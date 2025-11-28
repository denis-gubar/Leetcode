class Bank {
public:
    Bank(vector<long long>& balance): balance(balance), N(balance.size()) {
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > N || account2 > N || balance[account1 - 1] < money)
            return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > N)
            return false;
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > N || balance[account - 1] < money)
            return false;
        balance[account - 1] -= money;
        return true;
    }
    vector<long long> balance;
    int N;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */