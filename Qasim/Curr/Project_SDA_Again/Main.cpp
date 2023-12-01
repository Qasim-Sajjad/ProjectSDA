#include "Main.h"
#include <algorithm>
#include <iostream>

Main::Main(const vector<Teacher*>& t, const vector<Department*>& dept)
{
	this->Dept = dept;
	this->teachers = t;
}

void Main::AddEmployee(Employee* emp, int dept_ID)
{
	if (dept_ID >= 0 && dept_ID < this->Dept.size()) {
		//Add Employee to its subsequent Department.
		Dept[dept_ID]->addEmployees(emp);
	}
	else DisplayInvalidError();
}

void Main::AddManager(Manager* mgr, int dept_ID)
{
	if (dept_ID >= 0 && dept_ID < Dept.size()) {
		//Check if the dept_ID is Valid then,Create new Manager Base on the ID.
		Dept[dept_ID]->setManager(mgr);
	}
	else DisplayInvalidError();
}

void Main::AddTeacher(Teacher* _teach)
{
	bool check = 0;
	//Check if Teacher Already Exists.
	for (Teacher* t : teachers) {
		if (t->getID() == _teach->getID()) check = 1;
	}
	if (check) {
		DisplayAlreadyExistError();
		delete _teach;
	}
	else
		teachers.push_back(_teach);
}

void Main::removeEmployee(int Dept_ID, Employee* emp)
{
	//Remove Employee Of the Given Department ID.
	if (Dept_ID >= 0 && Dept_ID < Dept.size()) {
		Dept[Dept_ID]->rmEmployee(emp);
	}
}

void Main::removeManager(int Dept_ID, Manager* mgr)
{
	//Remove Employee Of the Given Department ID.
	if (Dept_ID >= 0 && Dept_ID < Dept.size()) {
		Dept[Dept_ID]->rmManager(mgr);
	}

}

void Main::removeTeacher(Teacher* t) //Not Sure How it will work :(
{
	//Find That Specfic TeacherPTr In the List of Teacher Ptr.
	vector<Teacher*>::iterator tptr = std::find(teachers.begin(), teachers.end(), t);
	//If Found then Erase That Teacher By finding its Index or By its Itr.
	if (tptr != teachers.end()) {
		teachers.erase(tptr);
	}
	else {
		cout << "Teacher Does Not Exist!\n";
	}
}

void Main::view_cmp_details(vector<Complaint*> cmps_in_range, int ind)
{
	if (ind >= 0 && ind < cmps_in_range.size()) {
		cout << "\n------------COMPLAINT DETAILS--------------\n";
		cout << "Date :" << cmps_in_range[ind]->GetTime().tm_year << "-" << cmps_in_range[ind]->GetTime().tm_mon << "-" << cmps_in_range[ind]->GetTime().tm_mday
			<< " Status : " << cmps_in_range[ind]->currState()
			<< " Description: " << cmps_in_range[ind]->getDescription()
			<< " Teacher: " << cmps_in_range[ind]->GetteacherName()
			<< " Manager: " << cmps_in_range[ind]->Dept_mgr_name() // Have To Add Relavent Manager And Employees Assigned.
		<< endl;

		cout << "------------Employee's Assigned---------------\n";
		cmps_in_range[ind]->Complaint_Assigned_Emps();
	}
	else
		cout << "INDEX OUT OF RANGE!\n";
}

void Main::DisplayAlreadyExistError()
{
	std::cout << "Object of Same ID and Name Already Exists.Use Different ID";
}


vector<Complaint*> Main::cmps_in_range(tm start_time, tm end_time)
{

	int s_t = start_time.tm_year + start_time.tm_mon + start_time.tm_mday;
	int e_t = end_time.tm_year + end_time.tm_mon + end_time.tm_mday;
	vector<Complaint*> cmps_in_range;

	for (Department* D : Dept) {
		vector<tm> AllCmpTimes = D->GetAllCmpTime();
		for (int i = 0; i < AllCmpTimes.size(); i++) {
			int c_t = AllCmpTimes[i].tm_year * 10000 + AllCmpTimes[i].tm_mon * 100 + AllCmpTimes[i].tm_mday;
			//If Time Point WithIn Range Then Print.
			if (c_t >= s_t && c_t <= e_t) {
				D->PrintCmpDetails(i);
				cmps_in_range.push_back(D->GetCmp(i));
			}
		}
	}
	return cmps_in_range;
}

void Main::DisplayInvalidError()
{
	cout << "\nDept ID out Of Range!!\n";
}

Main::~Main()
{
	for (int i = 0; i < Dept.size(); i++)
		delete[] Dept[i];
	for (int i = 0; i < teachers.size(); i++)
		delete teachers[i];

}






