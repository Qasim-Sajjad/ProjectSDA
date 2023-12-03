#pragma once
// Manager.h

#pragma once
#include "Department.h"
#include "Employee.h"
#include <vector>
#include <map>
using namespace std;
class Task;
class Complaint;
class Department;
class Employee;


class Manager {
public:
    Manager(int id,string name, Department* dept);
    void reviewComplaints();
    void assignComplaintsAsTasks(Complaint* comp, vector<int>& emp_ids, string description);
    bool checkComplaint(Complaint* comp,vector<Complaint*> complaints);
    vector<Employee*> Get_Emps_of_IDs(vector<int> emps_ids);
    void displayRelevantEmployees();
    string GetName();
private:
    int id;
    string name;
    Department* dept;
   vector<Task*> tasks;
   map<Employee*, vector<Task*>> assignedTasks;
   map<Employee*, vector<Complaint*>> assignedComplaints;
  
};
