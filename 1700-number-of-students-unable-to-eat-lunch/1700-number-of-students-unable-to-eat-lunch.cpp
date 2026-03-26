class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        while(!sandwiches.empty() && count < sandwiches.size()) {
                if (students[0] == sandwiches[0]) {
                    students.erase(students.begin());
                    sandwiches.erase(sandwiches.begin());
                    count = 0;
                } else {
                    students.push_back(students[0]);
                    students.erase(students.begin());
                    count++;
                }
        }
        return sandwiches.size();
    }
};