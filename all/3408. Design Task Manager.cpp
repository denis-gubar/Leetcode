class TaskManager {
public:
    set<pair<int, int>> S;
    unordered_map<int, set<pair<int, int>>> M;
    unordered_map<int, pair<int, int>> T;
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> const& task : tasks)
        {
            int const& userId = task[0];
            int const& taskId = task[1];
            int const& priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        S.emplace(priority, taskId);
        M[userId].emplace(priority, taskId);
        T[taskId] = { priority, userId };
    }
    
    void edit(int taskId, int newPriority) {
        int const priority = T[taskId].first;
        int const userId = T[taskId].second;
        T[taskId] = { newPriority, userId };
        S.erase({ priority, taskId });
        S.emplace(newPriority, taskId);
        M[userId].erase({ priority, taskId });
        M[userId].emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        int const priority = T[taskId].first;
        int const userId = T[taskId].second;
        T.erase(taskId);
        S.erase({ priority, taskId });
        M[userId].erase({ priority, taskId });
    }
    
    int execTop() {
        if (S.empty())
            return -1;
        int const taskId = prev(S.end())->second;
        int const userId = T[taskId].second;
        rmv(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
