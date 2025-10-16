/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
	int getImportance(vector<Employee*>& employees, int id) {
		int result = 0;
		for (int i = 0; i < employees.size(); ++i)
			if (employees[i]->id == id)
			{
				result += employees[i]->importance;
				for (int s : employees[i]->subordinates)
					result += getImportance(employees, s);
			}
		return result;		
	}
};