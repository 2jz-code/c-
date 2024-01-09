#include <iostream>
#include <string>
using namespace std;

int main(){
    int input1, input2;
    string color1, color2, color3, animal, state;

    cout << "Question 1: What is 5+7?" << endl;
    cin >> input1;
    cout << "Question 2: What is 5-7?" << endl;
    cin >> input2;
    cout << "Question 3: What animal goes \"woof\"?" << endl;
    cin >> animal;
    cout << "Question 4: What are the three primary pixel colors?" << endl;
    cin >> color1 >> color2 >> color3;
    cout << "Question 5: What state do we live in?" << endl;
    cin >> state;

    int score = 0;
    if(input1 == 12){
        score += 20;
    }
    if(input2 == -2){
        score += 20;
    }
    if(animal == "dog"){
        score += 20;
    }
    if(state == "minnesota"){
        score += 20;
    }
    if((color1 == "green" || color1 == "blue" || color1 == "red") && (color2 =="green" || color2 == "blue" || color2 == "green") && (color3 =="green" || color3 == "blue" || color3 == "green") && (color1 != color2 && color2 != color3)){
        score += 20;
    }
    cout << "Your percent correct: " << endl;
    cout << score << endl;
}