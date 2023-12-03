#include <ctime>
#include <iostream>
#include "Complaint.h"
#include "Teacher.h"


// Constructor
Complaint::Complaint(int id, Teacher* t, Department* dep, string description,State st)
{
    this->id = id;
    this->t = t;
    this->dep = dep;
    this->description = description;
    this->state = st;

    //Geting Current YYYY-MM-DD.
    if (state == New) {
        std::time_t cur_time = std::time(nullptr);
        localtime_s(&Local_Time, &cur_time);
        Local_Time.tm_year = Local_Time.tm_year + 1900;
        Local_Time.tm_mon = Local_Time.tm_mon + 1;
    }
}
string Complaint::getDescription()
{
    return this->description;
}
int Complaint::getID()
{
    return this->id;
}
const vector<Complaint*>& Complaint::getComplaints(Teacher* t)
{
    return t->getComplaints();
}
string Complaint::Dept_mgr_name()
{
    return dep->GetMgr();
}
void Complaint::Complaint_Assigned_Emps()
{
    dep->ABD_cmp_Employees();
}
State Complaint::currState() {
    return state;
}
void Complaint::changeState(State st) {
    state = st;
}
string Complaint::GetteacherName()
{
    return t->getName();
}
void Complaint::generateReport() {
   
        std::cout << "Complaint ID: " << id << endl;
        std::cout << "Description: " << description << endl;
        std::cout << "Assigned to Teacher: " << t->getName() << " (ID: " << t->getID() << ")" << endl;
        std::cout << "Assigned to Department: " << dep->getName() << endl;
        std::cout << "\nCurrent State: " << state << endl;
    
}
tm Complaint::GetTime()
{
    return Local_Time;
}

void Complaint::setTime(tm Time) {
    Local_Time = Time;
}