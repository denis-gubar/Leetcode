class Bitset {
public:
    Bitset(int size): N(size), data(vector<bool>(N)), flipCount(0), zeroCount(N) {
        
    }
    
    void fix(int idx) {
        if (flipCount == 0 && !data[idx])
        {
            data[idx] = true;
            --zeroCount;
        }
		else if (flipCount == 1 && data[idx])
		{
			data[idx] = false;
			++zeroCount;
		}
    }
    
    void unfix(int idx) {
        if (flipCount == 0 && data[idx])
        {
            data[idx] = false;
            ++zeroCount;
        }
		else if (flipCount == 1 && !data[idx])
		{
			data[idx] = true;
			--zeroCount;
		}
    }
    
    void flip() {
        flipCount = 1 - flipCount;
    }
    
    bool all() {
        if (flipCount == 0)
            return zeroCount == 0;
        return zeroCount == N;
    }
    
    bool one() {
        if (flipCount == 0)
            return zeroCount < N;
        return zeroCount > 0;
    }
    
    int count() {
        if (flipCount == 0)
            return N - zeroCount;
        return zeroCount;
    }
    
    string toString() {
        string result;
        result.reserve(N);
        if (flipCount == 0)
            for (int i = 0; i < N; ++i)
                result.push_back('0' + data[i]);
        else
			for (int i = 0; i < N; ++i)
				result.push_back('0' + (!data[i]));
        return result;
    }
    int N;
    vector<bool> data;
    int flipCount;
    int zeroCount;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
