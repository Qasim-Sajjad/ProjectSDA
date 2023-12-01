#pragma once
// Task.h
#pragma once
#include "Manager.h"
#include "Employee.h"
#include "Complaint.h"
#include <vector>
using namespace std;

class Complaint;
class Manager;
class Employee;

class Task {
public:
    string description;
    Task(Manager* mgr, const vector<Employee*>& emp, Complaint* comp, const string& description);
    Manager* getAssignedManager() const;
    vector<Employee*>& getAssignedEmployees();
    string getDescription();
    Complaint* getAssignedComplaint();
    void doTask();
private:

    Manager* assignedManager;
    vector<Employee*> assignedEmployees;
    Complaint* assignedComplaint;

};
