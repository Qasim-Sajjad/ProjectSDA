// Manager.cpp

#include "Manager.h"
#include "Department.h"
#include "Complaint.h"
//#include "Task.h"
#include<iostream>
using namespace std;

Manager::Manager(int id, string name, Department* dept)
{
    this->id = id;
    this ->name = name;
    this->dept = dept;
}
void Manager::reviewComplaints()
{
    const vector<Complaint*>& complaints = dept->getComplaints();
    cout << "Manager Reviewing Complaints of dept " << dept->getName()<<"\n";
    for (int i = 0; i < complaints.size(); ++i)
    {
        const Complaint* comp = complaints[i];
        cout << "\nComplaint ID: " << comp->id <<"  Complaint Description : "<<comp->description<<"\n";
    }
}
bool Manager::checkComplaint(Complaint* comp, vector<Complaint*> complaints)
{
    auto it = find(complaints.begin(), complaints.end(), comp);
    return it != complaints.end();
}
string Manager::GetName()
{
    return this->name;
}
void Manager::assignComplaintsAsTasks(Complaint* comp, vector<Employee*>& employees, string description)
{
    vector<Complaint*> complaints = dept->getComplaints();
    bool isFound = checkComplaint(comp, complaints);
    if (isFound)
    {
        Task* task = new Task(this, employees, comp, description);
        for (int i = 0; i < employees.size(); i++)
        {
            employees[i]->addTask(task);
            // Update Manager's tracking
            assignedTasks[employees[i]].push_back(task);
            assignedComplaints[employees[i]].push_back(comp);
        }
        tasks.push_back(task);
    }
    else
        cout << "There's no such complaint that you're referring to.\n";
}

void Manager::displayRelevantEmployees()
{
    
    for (const auto& entry : assignedTasks)
    {
        Employee* employee = entry.first;
        if(employee != NULL)
            cout << "Employee: " << employee->getName() << "\n";
    
    }
}
