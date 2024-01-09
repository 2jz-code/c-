// A program that takes in a filename from user input
// if filename is valid, will get each line and convert roman numerals to decimal numbers
// if there are any rule violations, it will output an error message in the middle of computation
// and then grab the next line and start on computing the next roman numeral
// Nadir Mustafa, 10/30/2023, CSCI 1113, Programming assignment 3


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int toDecimal(char);

int main(){
    ifstream in;
    string filename, line;
    char numeral;
    int oldest = 0,
    prev = 0,
    cur = 0,
    total = 0,
    i = 0,
    next = 0,
    len = 0;
    bool error = false;

    cout << "What file? ";
    cin >> filename;
    in.open(filename);
    if(!in.is_open()){
        cout << "File does not exist." << endl;
        return -1;
    }

    while(getline(in, line)){
        prev = 0;
        cur = 0;
        oldest = 0;
        i = 0;
        len = line.length();
        while(i < len){
            if(line[i] == '\n' || line[i] == '\r'){
                break;
            }
            numeral = toupper(line[i]);
            cur = toDecimal(numeral);

            if(cur == -1){
                error = true;
                cout << "*** Invalid character in input file ***" << endl;
                break;
            }
            if(cur > prev){
                if(prev == 0){
                    total += cur;
                }
                else if(cur <= oldest || oldest == 0){
                    total += cur - 2 * prev;
                }
                else{
                    error = true;
                    cout << "*** Two subtractions in a row ***" << endl;
                    break;
                }
                i += 1;
                cout << numeral;
            }
            else{
                    cout << numeral;
                    numeral = toupper(line[i + 1]);
                    next = toDecimal(numeral);
                    if(next != -1 && cur == prev){
                        if(next > cur){
                            error = true;
                            cout << "*** 2 the same and the next bigger ***" << endl;
                            break;
                        }
                    }
                    total += cur;
                    i += 1;
            }
            oldest = prev;
            prev = cur;

        }
        if(error == false){
            cout << " = " << total << endl;     // will only print if error is false
        }
        total = 0;
        error = false;
    }
    in.close();

    
}


// function that maps the roman numerals to their values
// will default to -1 if char that is passed in is not in the map

int toDecimal(char numeral){
    int decimal = 0;
    switch(numeral){
        case 'M':
            decimal = 1000;
            break;
        case 'D':
            decimal = 500;
            break;
        case 'C':
            decimal = 100;
            break;
        case 'L':
            decimal = 50;
            break;
        case 'X':
            decimal = 10;
            break;
        case 'V':
            decimal = 5;
            break;
        case 'I':
            decimal = 1;
            break;
        default:
            decimal = -1;   // invalid char
            break;
    }
    return decimal;
}