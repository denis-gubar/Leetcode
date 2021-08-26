class FooBar {
private:
    int n;
    int state;
	mutex m;
	condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        state = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this, i] {return state == i * 2; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++state;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this, i] {return state == i * 2 + 1; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ++state;
            cv.notify_all();
        }
    }
};