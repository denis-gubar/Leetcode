static long long A[100'001];
static int T[100'001];
class ExamTracker {
public:
    int N;
    ExamTracker() {
        A[0] = 0; N = 0;
    }
    
    void record(int time, int score) {
        T[N] = time;
        A[N + 1] = A[N] + score;
        ++N;
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it = lower_bound(&T[0], &T[0] + N, startTime);
        auto it2 = upper_bound(&T[0], &T[0] + N, endTime);
        if (it2 == &T[0])
            return 0LL;
        return A[it2 - &T[0]] - A[it - &T[0]];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
