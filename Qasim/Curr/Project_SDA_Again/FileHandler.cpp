//#include "souce.cpp"
#include<iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

template<class T>
void Populate_from_file(string filename,vector<T*> &vec_to_populate ) {
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
void Populate_from_file_Part2(string filename,D* &data_pointer,vector<S*> & vec_to_populate,int user_dept_Id) {
    ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }
    int id, dept_Id;
    string name;
     bool check = false;
    while (file >> id && !check) {
        getline(file >> ws, name, '\t');
        file >> dept_Id;

        if (dept_Id == user_dept_Id) {
            check = true;
            data_pointer = new D(id, name, vec_to_populate[dept_Id]); // dept_vec[0]
            vec_to_populate[dept_Id]->setManager(data_pointer);
        }
    }
   
    if(!check)
        cout << "Manager of this Department Not Exist.";

    file.close();

}
