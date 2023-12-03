// Employee.cpp
#include<iostream>
using namespace std;
#include "Employee.h"
#include "Department.h"
#include "Task.h"

Employee::Employee(int id, string name, Department* dept)
{
    this->id = id;
    this->name = name;
    this->dept = dept;
    this->task = nullptr;
}
void Employee::viewTask() {
    if (task != nullptr) {

       cout << "Task Description: " << task->getDescription() << "\n";
    }
    else {
        cout << "No task assigned.\n";
    }
}
void Employee::addTask(Task* tk) {
    task = tk;

}
void Employee::CompleteTask()
{
    task->doTask();
}
string Employee::getName()
{
    return this->name;
}
void Employee::printComplainStatus(Complaint* comp)
{
    cout << "Status of that complaint is" << comp->currState();

}

int Employee::GetID()
{
    return id;
}
    

