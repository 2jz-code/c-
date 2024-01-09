// A program that takes in a file as input. The file should contain valid commands
// That will allow the virtual laser cutter to actually "cut"
// Nadir Mustafa, 11/29/2023, CSCI 1113, Programming assignment 5.

// ************************************* NOTE ******************************************
// I utilized references much more in the program because we are graded on efficiency
// Using references reduces function overhead by not having to make copies of parameters
// That are passed in. This probably makes the program more efficient

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// max dimensions of 2d array
const int ROWS = 10;
const int COLS = 50;

void makeCNC(int array[ROWS][COLS]);
void printCNC(int array[ROWS][COLS]);
void mark(int& x, int& y, int array[ROWS][COLS]);
void commands(string& filename, int array[ROWS][COLS]);
void moveLaser(int& x, int& y, int& direction, int& distance, int array[ROWS][COLS], bool status);

int main(){
    int cnc[ROWS][COLS];
    string filename;

    cin >> filename;

    makeCNC(cnc);
    commands(filename, cnc);

    printCNC(cnc);
}

// initializes all indicies to 0
void makeCNC(int array[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            array[i][j] = 0;
        }
    }
}

// parses through the array and reads the inputs. Will exit() and stop the program if an error is encountered
void commands(string& filename, int array[ROWS][COLS]){
    ifstream inFile;
    string command;
    int distance = 0;
    bool laserStatus = false;

    inFile.open(filename);

    if (!inFile.is_open()) {
        cout << "Error, cannot open file." << endl;
        exit(1);
    }

    int x = 0, y = 0; 
    int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up

    while (inFile >> command) {
        if (command == "I"){
            mark(x, y, array);
            laserStatus = true;
        }
        else if (command == "O"){
            if(laserStatus == true){
                laserStatus = false;
            }
        }
        else if (command == "R"){
            direction = (direction + 1) % 4; // mod 4 makes sure that direction is always in between 0 and 3
        }
        else if (command == "L") {
            direction = (direction + 3) % 4;
        }
        else if (command == "A"){ // if A is encounter, will read the number associated with the command and call moveLaser function
            inFile >> distance;
            moveLaser(x, y, direction, distance, array, laserStatus);
        }
        else{
            cout << "Encountered an Invalid command. Terminating." << endl;
            exit(1);
        }
    }

    inFile.close();
}

// takes in coordinates, the current direction of the laser, and distance to travel to move the laser accordingly
// will only mark coordinates if the status of the laser is on, otherwise it will won't
void moveLaser(int& x, int& y, int& direction, int& distance, int array[ROWS][COLS], bool status){
    if (direction == 0) {
        for (int i = 0; i < distance; i++) {
            x += 1;
            if(status == true){
                mark(x, y, array);
            }
        }
    } else if (direction == 1) {
        for (int i = 0; i < distance; i++) {
            y += 1;
            if(status == true){
                mark(x, y, array);
            }
        }
    } else if (direction == 2) {
        for (int i = 0; i < distance; i++) {
            x -= 1;
            if(status == true){
                mark(x, y, array);
            }
        }
    } else if (direction == 3) {
        for (int i = 0; i < distance; i++) {
            y -= 1;
            if(status == true){
                mark(x, y, array);
            }
        }
    }
}

// will print a '*' only if a coordinate is marked, aka the value is 1
void printCNC(int array[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// marks (sets index = 1) a given coordinate. checks bounds of the laser to make sure it doesn't go off the edge
void mark(int& x, int& y, int array[ROWS][COLS]) {
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
        array[y][x] = 1;
    }
}