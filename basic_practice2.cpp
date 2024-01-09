#include <iostream>
#include <string>
using namespace std;

int main(){

    char letter;

    cout << "Enter a letter: " << endl;
    cin >> letter;
    
    if (static_cast<int>(letter) >= 65 && static_cast<int>(letter) <= 90){
        char lower_letter = letter + 32;
        cout << "The lowercase of " << letter << " is " << lower_letter << "." << endl;
    }
    else if (static_cast<int>(letter) >= 97 && static_cast<int>(letter) <= 122){
        char upper_letter = letter - 32;
        cout << "The uppercase of " << letter << " is " << upper_letter << "." << endl;
    }
    else{
        cout << letter << " is not a letter!" << endl;
    }
    return 0;
}