
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Employee {
    string name;
    int salary;

    bool operator<(const Employee& other) const {
        if (salary == other.salary) {
            return name < other.name;
        }
        return salary > other.salary;
    }
};

int main() {
    int x, N;
    cin >> x;
    cin >> N;

    vector<Employee> employees;

    for (int i = 0; i < N; i++) {
        Employee employee;
        cin >> employee.name >> employee.salary;
        employees.push_back(employee);
    }

    sort(employees.begin(), employees.end());

    for (const Employee& employee : employees) {
        if (employee.salary >= x) {
            cout << employee.name << " " << employee.salary << endl;
        }
    }

    return 0;
}
