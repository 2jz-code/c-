// A program that takes in a filename and student name from user input
// if filename is valid, will traverse the file until student name is found
// and return their grade. Otherwise the program will output error statements
// Nadir Mustafa, 10/30/2023, CSCI 1113, Programming assignment 3

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream in;
    string file;
    string name;
    string name_in_file;
    string name_output;
    string grade;
    string junk;

    cout << "What file? ";
    cin >> file;
    cout << "Whose name? ";
    cin >> name;

    in.open(file);

    if(!in.is_open()){
        cout << "File does not exist." << endl;
        return -1;
    }

    in >> name_in_file;

    while(!in.eof()){
        if(name_in_file == name){
            name_output = name_in_file;
            getline(in, grade);
            in >> name_in_file;
        }
        else{
            getline(in, junk);
            in >> name_in_file;
        }
    }
    if(name_output != name){
        cout << "No student with that name." << endl;
    }
    else{
    grade = grade.substr(11, 2);
    cout << "Grade: " << grade << endl;
    }
}