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
vector<Employee*> Manager::Get_Emps_of_IDs(vector<int> emps_ids)
{
    vector<Employee*> cmp_specified_emps;
    vector<Employee*> emps_of_dept = dept->Get_Dept_Emps();
    
    for (int i = 0; i < emps_ids.size(); i++) {
        for (Employee* E : emps_of_dept) {
            if (emps_ids[i] == E->GetID())
                cmp_specified_emps.push_back(E);
        }
    }
    return cmp_specified_emps;
}
string Manager::GetName()
{
    return this->name;
}
void Manager::assignComplaintsAsTasks(Complaint* comp, vector<int>& emp_ids, string description)
{
    vector<Complaint*> complaints = dept->getComplaints();  //if that Complaint Exist in the Department.
    bool isFound = checkComplaint(comp, complaints);
    vector<Employee*> emp_of_ids = Get_Emps_of_IDs(emp_ids);

    if (isFound)
    {
        Task* task = new Task(this, emp_of_ids, comp, description);
        for (int i = 0; i < emp_of_ids.size(); i++)
        {
            emp_of_ids[i]->addTask(task);
            // Update Manager's tracking
            assignedTasks[emp_of_ids[i]].push_back(task);
            assignedComplaints[emp_of_ids[i]].push_back(comp);
        }
        tasks.push_back(task);
    }
    else
        cout << "There's no such complaint that you're referring to.\n";
}


void Manager::displayRelevantEmployees()
{
    //Won't it will Print Employee's for All Tasks related to that Manager?
    for (const auto& entry : assignedTasks)
    {
        Employee* employee = entry.first;
        if(employee != NULL)
            cout << "Employee: " << employee->getName() << "\n";
    
    }
}
