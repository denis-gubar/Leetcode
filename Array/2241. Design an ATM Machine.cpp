class ATM {
public:
    ATM() : money(vector<long long>(5)), nominals({ 20, 50, 100, 200, 500 }) {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
            money[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(long long amount) {
        vector<int> result(5);
        for (int i = 4; i >= 0; --i)
        {
            result[i] = min(money[i], amount / nominals[i]);
            amount -= result[i] * nominals[i];
        }
        if (amount > 0)
            return { -1 };
        for (int i = 0; i < 5; ++i)
            money[i] -= result[i];
        return result;
    }
    vector<long long> money;
    vector<int> nominals;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
