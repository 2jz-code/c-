// takes in user input from console, input is put into phrase and keyword
// key is used to then encrypt phrase using the cipherGenerator function
// Nadir Mustafa, 10/30/2023, CSCI 1113, Programming assignment 4A

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cipherGenerator(string key, string phrase, char alpha[]);
string keyGenerator(string keyword, string phrase);
void make_alphabet(char array[], char letter);
void string_input(string& phrase, string& keyword);
void string_to_upper(string& word);

const int ARRAY_SIZE = 26;

int main(){
    char alpha[ARRAY_SIZE];
    char letter = 65;
    string phrase, keyword;


    make_alphabet(alpha, letter);

    string_input(phrase, keyword);
    
    string_to_upper(phrase);
    string_to_upper(keyword);


    string key = keyGenerator(keyword, phrase);
    string cipher = cipherGenerator(key, phrase, alpha);
    cout << "Encrypted Phrase: " << cipher << endl;
}

// capitalizes the input from the user
void string_to_upper(string& word){
    for(int i = 0; i < word.length(); i++){
        word[i] = toupper(word[i]);
    }
}

// gets input from the user
void string_input(string& phrase, string& keyword){
    cout << "Enter the phrase: ";
    cin >> phrase;
    
    cout << "Enter the keyword: ";
    cin >> keyword;
}

// makes a char array of the alphabet, uses ascii code for uppercase letters
void make_alphabet(char array[], char letter){
    for(int i = 0; i < ARRAY_SIZE; i++){
        array[i] = letter + i;
    }
}

// takes the keyword, and repeats it to the length of phrase
string keyGenerator(string keyword, string phrase){
    string keyword_repeated;
    int j = 0;
    int keyword_len = keyword.length();
    for(int i = 0; i < phrase.length(); i++){
        keyword_repeated += keyword[(i % keyword_len)];
    }
    return keyword_repeated;
}

// generates the cipher of the phrase, with key already made to the length of phrase
// uses the alpha array in order to find the letter that goes into the cipher string
// after doing arithmetic on the phrase and key indexes for each given index
string cipherGenerator(string key, string phrase, char alpha[]){
    string cipher;
    int key_index, phrase_index;
    for(int i = 0; i < phrase.length(); i++){
        key_index = key[i] - 'A';
        phrase_index = phrase[i] - 'A';
        cipher += alpha[((key_index + phrase_index) % 26)];
    }
    return cipher;
}