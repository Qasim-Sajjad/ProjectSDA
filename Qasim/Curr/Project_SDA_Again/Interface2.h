#pragma once
#include<vector>
#include "Department.h"
#include "Complaint.h"

class Interface2 {
public:
	virtual void view_cmp_details(vector<Complaint*> cmps_in_range, int ind) = 0;
	virtual vector<Complaint*> cmps_in_range(tm start_time, tm end_time) = 0;
};