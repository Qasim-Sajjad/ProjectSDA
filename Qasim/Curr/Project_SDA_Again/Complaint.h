#pragma once

#include<ctime>
#include<string>
#include "Department.h"
#include "Teacher.h"
#include<vector>
using namespace std;

enum State {
	New,
	Assigned,
	Completed,
	Resolved,
	Closed
};
class Department;
class Teacher;
class Complaint {
	tm date;
	State state;
	Teacher* t;
	Department* dep;
public:
	
	tm Local_Time;
	int id;
	string description;
	Complaint(int id,Teacher* t, Department* dep, string description);
	const vector<Complaint*>& getComplaints(Teacher* t);
	string Dept_mgr_name();
	void Complaint_Assigned_Emps();
	State currState();
	void changeState(State st);
	string GetteacherName();
	void generateReport();
	string getDescription();
	int getID();
	tm GetTime();

};
