#include <iostream>
#include<string>
#include "FileHandler.cpp"
#include "Department.h"
#include "Teacher.h"
#include "Administrator.h"
#include "Director.h"
using namespace std;

bool isValid(int year, int month, int day) {
    // Check if the date is valid
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Check for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;

}
int main() {
    // Create a department
    vector<Teacher*> tech_vec;
    vector<Department*> dept_vec;
    Manager* mgr = nullptr;
    Employee* employee1 = nullptr;

    Populate_from_file("Teacher.txt", tech_vec);
    Populate_from_file("Department.txt", dept_vec);
   // Populate_from_file_Part2("Manager.txt", mgr, dept_vec,0);
   // Populate_from_file_Part2("employee.txt", employee1, dept_vec, 0,"Coder");

    ifstream f2("dummy.txt");
    if (!f2.is_open())
        cout << "ERROR\n";


    // Create a complaint
    Complaint* complaint = new Complaint(1, tech_vec[0], dept_vec[0], "t1 complaint 1.");

    //Complaint* complaint2 = new Complaint(2, teacher, IT, "t1 complaint 2");
    //Complaint* complaint3 = new Complaint(3, teacher, IT, "t1 complaint 3.");
    //Complaint* complaint4 = new Complaint(4, teacher, Accounts, "t1 complaint 4.");
    //Complaint* complaint5 = new Complaint(5, teacher, Accounts, "t1 complaint 5.");

    // Add the complaint to the teacher's list
    tech_vec[0]->addComplaint(complaint);
    dept_vec[0]->addComplaint(complaint);

    /*
    teacher->addComplaint(complaint2);
    IT->addComplaint(complaint2);
    teacher->addComplaint(complaint3);
    IT->addComplaint(complaint3);
    teacher->addComplaint(complaint4);
    Accounts->addComplaint(complaint4);
    teacher->addComplaint(complaint5);
    Accounts->addComplaint(complaint5);
    */


   // Manager* mgr = new Manager(1, "Abdullah", dept_vec[0]);
    if(mgr != NULL)
        mgr->reviewComplaints();


    //Adding Employees  

  //  Employee* employee1 = new Employee(1, "John", dept_vec[0]);
    Employee* employee2 = new Employee(2, "Jane", dept_vec[0]);
    Employee* employee3 = new Employee(3, "Bob", dept_vec[0]);


    dept_vec[0]->addEmployees(employee1);
    dept_vec[0]->addEmployees(employee2);
    dept_vec[0]->addEmployees(employee3);
    dept_vec[0]->printEmployees();

    vector<Employee*> employees = { employee1, employee2, employee3 };

    if(mgr != NULL)
        mgr->assignComplaintsAsTasks(complaint, employees, "Fix the issue");
    

    for (Employee* emp : employees)
    {
        cout << emp->getName() << "'s tasks:\n";
    //    emp->viewTask();
        cout << "-----------------------\n";
    }
    //employee1->CompleteTask();
    //cout << employee1->getName() << " did this Task.\n";

    // dept_vec[0]->PrintCmpDetails(1);

    //------------------------------------------------
    // DIRECTORS PANEL
    Interface2* inter2 = new Main(tech_vec, dept_vec);
    Director* dir = new Director(inter2);

    int startYear, startMonth, startDay;
    //Ask Start Time And End Time For Summary.
    cout << "Enter start date (YYYY MM DD): ";
    cin >> startYear >> startMonth >> startDay;

    int endYear, endMonth, endDay;
    cout << "Enter end date (YYYY MM DD): ";
    cin >> endYear >> endMonth >> endDay;

    if (isValid(startYear, startMonth, startDay) && isValid(endYear, endMonth, endDay)) {
        std::tm start_tm = {};
        start_tm.tm_year = startYear * 10000;
        start_tm.tm_mon = startMonth * 100;
        start_tm.tm_mday = startDay;

        std::tm end_tm = {};
        end_tm.tm_year = endYear * 10000;
        end_tm.tm_mon = endMonth * 100;
        end_tm.tm_mday = endDay;

        vector<Complaint*> cmps_in_rge = dir->cmps_in_range(start_tm, end_tm);
       dir->cmp_details(cmps_in_rge, 0);
    }
    else
        cout << "Invalid Range!\n";

    //---------------------------------------------
    return 0;
}



