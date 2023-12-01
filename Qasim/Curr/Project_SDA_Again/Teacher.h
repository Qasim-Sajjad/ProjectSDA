#pragma once

#include <string>
#include <vector>
#include "Complaint.h"
using namespace std;
class Complaint;
class Teacher {
public:
	Teacher(int id, string name);
	void addComplaint(Complaint* comp);
	void printComplaints();
	void reportFeedback();
	int getID();
	string getName();
	const vector<Complaint*>& getComplaints();
private:
	int id;
	string name;
	vector<Complaint*> complaints;

};