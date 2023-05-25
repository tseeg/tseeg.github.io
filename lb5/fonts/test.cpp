#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Employee {
private:
    int id;
    char* name;
    char* position;
    float hours;

public:
    Employee() {
            id = 0;
            name = new char[5];
            position = new char[5];
            strcpy(name,"test");
            strcpy(position,"test");
            hours = 0.0;
        }
    Employee(int a, char *b, char *c, float d) {
            id = a;
            name=new char[strlen(b)+1];
            strcpy(name,b);
            position=new char[strlen(c)+1];
            strcpy(position,c);
            hours=d;
    }

    ~Employee() {
        delete name;
        delete position;
    }

    void showData() {
        cout << "Employee number " << id << "\n"
                  << "Employee name " << name << "\n"
                  << "Employee position " << position << "\n"
                  << "Employee's hours of work " << hours << endl;
    }

    void getData() {
        cout << "\nEnter employee number: ";
        cin >> id;
        cout << "\nEnter employee name: ";
        char t_name[20];
        cin >> t_name;
        name = new char[strlen(t_name)+1];
        strcpy(name, t_name);
        cout << "\nEnter employee position: ";
        char t_position[20];
        cin >> t_position;
        position = new char[strlen(t_position)+1];
        strcpy(position,t_position);
        cout << "\nEnter employee hours of work: ";
        cin >> hours;
    }

    float addHours(float f) {
        if (f > 0 && f <= 24) {
            hours += f;
            return hours;
        }
        return -1.0;
    }

    void setId(int a) {
        id = a;
    }

    void setName(const char* a) {
        delete[] name;
        int length = std::strlen(a);
        name = new char[length + 1];
        strcpy(name, a);
    }

    void setPosition(const char* a) {
        delete[] position;
        int length = std::strlen(a);
        position = new char[length + 1];
        strcpy(position, a);
    }

    void setHours(float a) {
        hours = a;
    }

    int getId() const {
        return id;
    }

    const char* getName() const {
        return name;
    }

    const char* getPosition() const {
        return position;
    }

    float getHours() const {
        return hours;
    }

    float getSalary() const {
        float salary = hours * 6000;
        if (strcmp(position, "zahiral") == 0) {
            salary = hours * 10000;
        }
        return salary;
    }
    bool ByName(Employee& e1, Employee& e2) {
        return strcmp(e1.getName(), e2.getName()) < 0;
    }
};


int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee* empArr = new Employee[n];
    for (int i = 0; i < n; i++) {
        empArr[i].getData();
    }
    sort(empArr, empArr + n, Employee::ByName);
    for (int i = 0; i < n; i++) {
        empArray[i].showData();
        cout << endl;
    }
    delete empArray;
}
