#pragma once
#include "Complaint.h"
#include "Employee.h"
#include "Manager.h"
#include<vector>
#include<string>
#include <ctime>
using namespace std;

class Employee;
class Manager;


class Department {
public:
    Department(int id, string name);

    void addComplaint(Complaint* comp);
    const vector<Complaint*>& getComplaints() const;
    void addEmployees(Employee* emp);
    vector<Employee*> Get_Dept_Emps();
    void setManager(Manager* mgr);
    string getName();
    void ABD_cmp_Employees();
    void printEmployees();
    void Print_Cmps();
    int GetID();
    string GetMgr();
    vector<tm> GetAllCmpTime();
    void changeState(Complaint* comp);
    void rmEmployee(Employee* emp);
    Complaint* GetCmp(int ind);
    void PrintCmpDetails(int ind);
    void rmManager(Manager* mgr);

private:
    int id;
    string name;
    vector<Employee*> employees;
    vector<Complaint*> complaints;
    Manager* mgr;
    int totalComplaints;
    vector<tm> AllCmptimes;


};

