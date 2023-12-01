/* The campus director for example, can view a summary of the complaints
filed within a given period of time. For each department, the system shall show
the number of complaints received, along with their status (closed, open, etc).
The director then can ask for details about a specific complaint, including
complaint date, status and description, the teacher who initiated the request,
the relevant manager and employees, and the date of job assignment.*/
#pragma once
#include "Interface2.h"
#include "Complaint.h"
#include <vector>
#include <ctime>
using namespace std;

class Director {
public:
	Director(Interface2* inter2);
	//Wrapper
	vector<Complaint*> cmps_in_range(tm starttime, tm endtime);
	void cmp_details(vector<Complaint*> cmps_in_range, int ind);
private:
	Interface2* inter2;
};