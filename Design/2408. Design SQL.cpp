class SQL {
public:
    unordered_map<string, int> M;
    map<string, unordered_map<int, vector<string>>> table_data;
    SQL(vector<string>& names, vector<int>& columns) {
        
    }
    
    void insertRow(string name, vector<string> row) {
        int const rowId = ++M[name];
        table_data[name][rowId] = row;
    }
    
    void deleteRow(string name, int rowId) {
        table_data[name][rowId].clear();
    }
    
    string selectCell(string name, int rowId, int columnId) {
        auto const table_row = table_data[name][rowId];
        if (table_row.empty())
            return {};
        return table_row[columnId - 1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */
