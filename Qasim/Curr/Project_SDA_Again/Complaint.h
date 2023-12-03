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
	Resolved,
	Completed,
	Closed
};
class Department;
class Teacher;


class Complaint {
	tm date;
	State state;
	Teacher* t;
	Department* dep;
	tm Local_Time;
public:
	
	int id;
	string description;
	Complaint(int id,Teacher* t, Department* dep, string description,State st = New);
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
	void setTime(tm Time);

};
