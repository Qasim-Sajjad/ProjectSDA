#pragma once
#pragma once
#include<string>
#include "Department.h"
using namespace std;

class Interface1 {
public:
    virtual void AddEmployee(Employee* emp, int dept_ID) = 0;
    virtual void AddManager(Manager* mgr, int dept_ID) = 0;
    virtual void AddTeacher(Teacher* _teach) = 0;
    virtual void removeEmployee(int Dept_ID, Employee* emp) = 0;
    virtual void removeManager(int Dept_ID, Manager* mgr) = 0;
    virtual void removeTeacher(Teacher* t) = 0;
};