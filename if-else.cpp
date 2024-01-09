#include <iostream>
#include <string>
using namespace std;

int main(){

    float distance;
    string unit;
    string convert;
    float converted_distance = 0.0;
    
    cout << "Enter distance with units: " << endl;
    cin >> distance;
    cin >> unit;

    cout << "What do you want to convert this to?" << endl;
    cin >> convert;

    // cout << distance << endl;
    // cout << unit << endl;
    // cout << convert << endl;

    if(unit == "feet" || unit == "ft"){
        if(convert == "m" || convert == "meters"){
            converted_distance = distance * 0.3048;
            cout << converted_distance << endl;
        }
        else if(convert == "cm" || convert == "centimeter"){
            converted_distance = distance * 30.48;
            cout << converted_distance << endl;
        }
        else if(convert == "inches" || convert == "in"){
            converted_distance = distance * 12;
            cout << converted_distance << endl;
        }
        else if(unit == "feet" || unit == "ft"){
            cout << distance << endl;
        }
        else{
            cout << "Not a valid unit" << endl;
        }
    }
    if (unit == "m" || unit == "meters"){
        if(convert == "cm" || convert == "centimeters"){
            converted_distance = distance * 100;
            cout << converted_distance << endl;
        }
        else if(convert == "ft" || convert == "feet"){
            converted_distance = distance * 3.28084;
            cout << converted_distance << endl;
        }
        else if(convert == "in" || convert == "inches"){
            converted_distance = distance * 39.3701;
            cout << converted_distance << endl;
        }
        else if (unit == "m" || unit == "meters"){
            cout << distance << endl;
        }
        else{
            cout << "Not a valid unit" << endl;
        }
    }
    if(unit == "cm" || unit == "centimeters"){
        if(convert == "m" || convert == "meters"){
            converted_distance = distance / 100;
            cout << converted_distance << endl; 
        }
        else if(convert == "in" || convert == "inches"){
            converted_distance = distance * 0.393701;
            cout << converted_distance << endl;
        }
        else if(convert == "ft" || convert == "feet"){
            converted_distance = distance * 0.0328084;
            cout << converted_distance << endl;
        }
        else if(unit == "cm" || unit == "centimeters"){
            cout << distance << endl;
        }
        else{
            cout << "Not a valid unit" << endl;
        }
     }
    if(unit == "in" || unit == "inches"){
        if(convert == "ft" || convert == "feet"){
            converted_distance = distance / 12;
            cout << converted_distance << endl;
        }
        else if(convert == "m" || convert == "meters"){
            converted_distance = distance * 0.0254;
            cout << converted_distance << endl;
        }
        else if(convert == "cm" || convert == "centimeters"){
            converted_distance = distance * 2.54;
            cout << converted_distance << endl;
        }
        else if(convert == "in" || convert == "inches"){
            cout << distance << endl;
        }
        else{
            cout << "Not a valid unit" << endl;
        }
     }
}
