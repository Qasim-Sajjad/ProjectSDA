#pragma once
#include "Interface1.h"
#include "Interface2.h"
#include <vector>
#include <ctime>
#include <iomanip>


using namespace std;



class Main :public Interface1, public Interface2 {
public:
    Main(const vector<Teacher*>& t, const vector<Department*>& dept);
    void AddEmployee(Employee* emp, int dept_ID);
    void AddManager(Manager* mgr, int dept_ID);
    void AddTeacher(Teacher* _teach);
    void removeEmployee(int Dept_ID, Employee* emp);
    void removeManager(int Dept_ID, Manager* mgr);
    void removeTeacher(Teacher* t);
    void view_cmp_details(vector<Complaint*> cmps_in_range, int ind);
    vector<Complaint*> cmps_in_range(tm start_time, tm end_time);
    ~Main();
private:
    void DisplayInvalidError();
    void DisplayAlreadyExistError();
    vector<Department*> Dept;
    vector<Teacher*> teachers;
};
