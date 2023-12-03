#include "Task.h"
#include<iostream>
using namespace std;

Task::Task(Manager* mgr, const vector<Employee*>& emp,Complaint* comp, const string& description)
{
    this ->description = description;
    this->assignedEmployees = emp;
    this->assignedManager = mgr;
    this->assignedComplaint = comp;
    assignedComplaint->changeState(State::Assigned);

}
Manager* Task::getAssignedManager() const {
    return assignedManager;
}
vector<Employee*>& Task:: getAssignedEmployees()
{
    return assignedEmployees;
}

string Task::getDescription()
{
    return this->description;
}
Complaint* Task::getAssignedComplaint()
{
    return this->assignedComplaint;
}
void Task::doTask()
{
    this->assignedComplaint->changeState(State::Completed);
    cout << this->assignedComplaint->getDescription() << " is Completed\n " << endl;
}
