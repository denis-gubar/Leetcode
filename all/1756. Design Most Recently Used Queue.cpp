static short F[2][2'000];
class MRUQueue {
public:
	short N;
    bool Q;
    MRUQueue(int n): N(n), Q(false) {
		memset(F, 0, sizeof(F));
		iota(&F[0][0], &F[0][0] + N, 1);
    }
    
    int fetch(int k) {
        --k;
        memcpy(&F[!Q][0], &F[Q][0], sizeof(F[0][0]) * k);
        int result = F[Q][k];
        memcpy(&F[!Q][k], &F[Q][k + 1], sizeof(F[0][0]) * (N - k - 1));
        F[!Q][N - 1] = result;
        Q = !Q;
        return result;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
