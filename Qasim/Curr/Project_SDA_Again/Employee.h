#pragma once
#include "Department.h"
#include "Task.h"
class Complaint;
class Department;
class Task;
class Employee {
public:
	Employee(int id, string name, Department* dept);
	void viewTask();
	void addTask(Task* tk);
	void CompleteTask();
	string getName();
	void printComplainStatus(Complaint* comp);
	//void doTask(Complaint * comp);
	//void notify();
private:
	int id;
	string name;
	Department* dept;
	Task* task;

};