//#include "souce.cpp"
#include<iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include "Manager.h"

using namespace std;

template<class T>
void Populate_from_file(string filename,vector<T*> &vec_to_populate) {
	ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }
    int id;
    string name;

    while (file >> id) {
        getline(file >> ws, name);

        T* data_pointer = new T(id, name);
        vec_to_populate.push_back(data_pointer);
    }
    file.close();
}

template<class D,class S>
void Populate_from_file_Part2(string filename,vector<S*> & vec_to_populate, D*& data_pointer = nullptr, int user_dept_Id = 0,string user_name = "\0") {
    ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }
    int id, dept_Id;
    string name;
    bool check = false;

    if (is_same<D,Manager>::value) { //If Manager Calls the Function.
        while (file >> id && !check) {
            getline(file >> ws, name, '\t');
            file >> dept_Id;

            if (dept_Id == user_dept_Id) {
                check = true;
                data_pointer = new D(id, name, vec_to_populate[dept_Id]); // dept_vec[0]
                vec_to_populate[dept_Id]->setManager((Manager*)data_pointer);
            }
        }
        if(!check)
            cout << "Manager of this Department Not Exist.\n";
    }
    else if (is_same<D, Employee>::value) { // if Employee Calls the Function.
        while (file >> id && !check) {
            getline(file >> ws, name, '\t');
            file >> dept_Id;

            if (dept_Id == user_dept_Id && user_name == name) {
                check = true;
                data_pointer = new D(id, name, vec_to_populate[dept_Id]);
              //  vec_to_populate[dept_Id]->addEmployees((Employee*)data_pointer);
            }
        }
        if (!check)
            cout << "Employee with this id or Dept not found!\n";
    }

    file.close();

}

template<class C,class T,class D>
void Populate_Complaints(string filename,vector<C*> &cmps_vec,vector<T*> &tech_vec,vector<D*> &dept_vec) {
    ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }
    int id = 0, dept_Id = 0, tech_id = 0,status_int = 0,year = 0,mon = 0,day = 0;
    string descrption;
    std::tm Time = {};
    C* cmp = nullptr;

    while (file >> id) {
        getline(file >> ws, descrption, '\t');
        file >> tech_id;
        file >> dept_Id;
        file >> status_int; 
        file >> year;
        file >> mon; 
        file >> day;

        Time.tm_year = year;
        Time.tm_mon = mon;
        Time.tm_mday = day;


        switch (status_int)
        {
        case 0:
            cmp = new C(id, tech_vec[tech_id], dept_vec[dept_Id],descrption,State::New);
            break;
        case 1:
            cmp = new C(id, tech_vec[tech_id], dept_vec[dept_Id], descrption,State::Assigned);
            break;
        case 2:
            cmp = new C(id, tech_vec[tech_id], dept_vec[dept_Id], descrption,State::Resolved);
            break;
        case 3:
            cmp = new C(id, tech_vec[tech_id], dept_vec[dept_Id], descrption,State::Completed);
            break;
        case 4:
            cmp = new C(id, tech_vec[tech_id], dept_vec[dept_Id], descrption,State::Closed);
            break;
        default:
            break;
        }
        cmp->setTime(Time);
        tech_vec[tech_id]->addComplaint((Complaint*)cmp);
        dept_vec[dept_Id]->addComplaint((Complaint*)cmp);
        cmps_vec.push_back((Complaint*)cmp);
    }
    file.close();
}

template<class E,class D>
void Populate_All_Emps(string filename,vector<E*> &emps_vec,vector<D*> & dept_vec) {
    ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }

    int id = 0, dept_id = 0;
    string name;

    while (file >> id) {
        getline(file >> ws, name, '\t');
        file >> dept_id;

        E* Emp_pointer = new E(id, name, dept_vec[dept_id]);
        dept_vec[dept_id]->addEmployees((Employee*)Emp_pointer);
        emps_vec.push_back((Employee*)Emp_pointer);
        
    }
    file.close();
}