class MyCircularDeque {
public:
	vector<int> data;
	int begin, end, n, size;
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k): data(vector<int>(k + 1)), n(k), begin(0), end(0), size(0) {

	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (size == n)
			return false;
		if (size == 0)
			begin = n, end = 1;
		else
			begin = (begin + n) % (n + 1);
		++size;
		data[(begin + 1) % (n + 1)] = value;
		return true;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (size == n)
			return false;
		if (size == 0)
			begin = n, end = 1;
		else
			end = (end + 1) % (n + 1);
		++size;
		data[(end + n) % (n + 1)] = value;
		return true;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (size == 0)
			return false;
		--size;
		begin = (begin + 1) % (n + 1);
		return true;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (size == 0)
			return false;
		--size;
		end = (end + n) % (n + 1);
		return true;
	}

	/** Get the front item from the deque. */
	int getFront() {
        if (size == 0) return -1;
		return data[(begin + 1) % (n + 1)];
	}

	/** Get the last item from the deque. */
	int getRear() {
        if (size == 0) return -1;
		return data[(end + n) % (n + 1)];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return size == n;
	}
};