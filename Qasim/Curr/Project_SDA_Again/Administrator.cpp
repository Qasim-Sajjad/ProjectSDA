#include "Administrator.h"

Administrator::Administrator() {
	//this->inter1 = new Main()
}

Administrator::Administrator(Interface1* inter1)
{
	this->inter1 = inter1;
}

void Administrator::AddEmp(Employee* emp, int dept_ID)
{
	inter1->AddEmployee(emp, dept_ID);
}

void Administrator::AddMgr(Manager* mgr, int dept_ID)
{
	inter1->AddManager(mgr, dept_ID);
}

void Administrator::AddTech(Teacher* _teach)
{
	inter1->AddTeacher(_teach);
}

void Administrator::removeEmp(int Dept_ID, Employee* emp)
{
	inter1->removeEmployee(Dept_ID, emp);
}

void Administrator::removeMgr(int Dept_ID, Manager* mgr)
{
	inter1->removeManager(Dept_ID, mgr);
}

void Administrator::removeTech(Teacher* t)
{
	inter1->removeTeacher(t);
}
