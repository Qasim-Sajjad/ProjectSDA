#pragma once
// Department.cpp

#include "Department.h"
#include<iostream>


Department::Department(int id, string name) {
    this->id = id;
    this->name = name;
    this->totalComplaints = 0;
    this->mgr = nullptr;

}
string Department::getName()
{
    return this->name;
}
void Department::ABD_cmp_Employees()
{
    mgr->displayRelevantEmployees();
}
void Department::printEmployees()
{
    cout << "\nEmployees in "<<this->name<<" Department \n";
    for (int i = 0; i < employees.size(); i++)
    {
        cout<<"Emp ID :" << employees[i]->GetID() << " Name : " << employees[i]->getName() << "\n";
    }
}
void Department::Print_Cmps()
{

    cout << "\n-------COMPLAINTS of "<<name<<" --------\n";
    for (Complaint* C : complaints) {
        cout << "Complaint ID :" << C->getID()
            << " Description :" << C->getDescription()
            << " Status :" << C->currState()
            << " Time :" << C->GetTime().tm_year << "-" << C->GetTime().tm_mon << "-" << C->GetTime().tm_mday << endl;
    }

}
void Department::addComplaint(Complaint* comp)
{
    complaints.push_back(comp);
    AllCmptimes.push_back(comp->GetTime());
    this->totalComplaints++;
}
const vector<Complaint*>& Department::getComplaints() const {
    return complaints;
}

void Department::addEmployees(Employee* emp) {
    employees.push_back(emp);
}
vector<Employee*> Department::Get_Dept_Emps()
{
    return employees;
}
void Department::setManager(Manager* manager) {
    mgr = manager;
}
int Department::GetID()
{
    return this->id;
}
string Department::GetMgr()
{
    if (mgr)
        return mgr->GetName();
    else
        return "No Assigned Manager.";
}
vector<tm> Department::GetAllCmpTime()
{
    return AllCmptimes;
}
//Changing State By manager to specific complaint in the list of complaints.
void Department::changeState(Complaint* comp)
{
}
void Department::rmEmployee(Employee* emp)
{
    //Find That Specific Employee And Erase it if Exists.
    auto emp_itr = std::find(employees.begin(), employees.end(), emp);
    if (emp_itr != employees.end())
        employees.erase(emp_itr);
    else cout << "Employee Does Not Exist!\n";
}
void Department::PrintCmpDetails(int ind)
{
    //If Such Complaint Exist, Print its Credentials.
    if (ind >= 0 && ind < complaints.size()) {
        cout << "Complaint Details for :" << name << " Department\n";
        cout << "Description : " << complaints[ind]->getDescription() 
            << "\t Status :" << complaints[ind]->currState() 
            << " Time :" << complaints[ind]->GetTime().tm_year << "-" << complaints[ind]->GetTime().tm_mon << "-" << complaints[ind]->GetTime().tm_mday << endl;
    }
}

Complaint* Department::GetCmp(int ind)
{
    if (ind >= 0 && ind < complaints.size())
        return complaints[ind];
    return nullptr;
}

void Department::rmManager(Manager* mgr)
{
    if (this->mgr != NULL) {
        delete mgr;
        cout << "Manager Removed Successfully!\n";
    }
}


