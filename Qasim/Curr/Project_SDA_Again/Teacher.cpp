#include <iostream>
#include "Teacher.h"
#include <string>
Teacher::Teacher(int id,string name)
{
    this->id = id;
    this->name = name;
}
void Teacher::addComplaint(Complaint* comp)
{
    for (int i = 0; i < complaints.size(); i++)
    {
        if (comp->getID() == complaints[i]->getID())
        {
            cout << "Can't add Complaint with same ID\n";
            goto label;
        }

    }
    complaints.push_back(comp);
    label:
    return;
}
const vector<Complaint*>& Teacher::getComplaints()
{
    return this->complaints;
}
string Teacher::getName()
{
    return this->name;
}
int Teacher::getID()
{
    return this->id;
}
void Teacher::printComplaints() {
    std::cout << "Complaints for Teacher " << name << " (ID: " << id << "):" << std::endl;
    for (const auto& comp : complaints) {
        cout << comp->getDescription() << std::endl;
    }
}
void Teacher::reportFeedback() {
   
        cout << "Feedback reported by Teacher " << name << " (ID: " << id << "): Thank you for your feedback!" << endl;
    
}
