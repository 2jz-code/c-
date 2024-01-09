// A program that takes in user input from console, up to 300 digits
// if anymore than 300 are entered, and overflow warning will be returned
// the program incorporates 4 functions, swap, sum, array_ouput, and input_nums
// Nadir Mustafa, 10/30/2023, CSCI 1113, Programming assignment 4B

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void input_nums(int array[], int &count);
void array_output(int array[], int count);
void sum(int array1[], int array2[], int sum[], int& count);
void swap(int array[], int count);

const int ARRAY_SIZE = 101;

int main(){
    int num_arr1[ARRAY_SIZE] = {0};
    int num_arr2[ARRAY_SIZE] = {0};
    int sum_array[ARRAY_SIZE]= {0};
    int arr1_count = 0;
    int arr2_count = 0;
    int sum_count = 0;

    input_nums(num_arr1, arr1_count);
    input_nums(num_arr2, arr2_count);


    if(arr1_count > arr2_count){
        sum_count = arr1_count;
    }
    else{
        sum_count = arr2_count;
    }

    swap(num_arr1, arr1_count);
    swap(num_arr2, arr2_count);

    sum(num_arr1, num_arr2, sum_array, sum_count);
    swap(sum_array, sum_count);

    if(sum_count < 101){
        cout << endl;
        cout << "Addition Result: ";
        array_output(sum_array, sum_count);
    }
    else{
        cout << endl;
        cout << "OVERFLOW WARNING" << endl;
        cout << "Addition Result: ";
        sum_array[0] = 0;
        sum_count--;
        array_output(sum_array, sum_count);
    }




}

// input_nums() prompts the user for input, puts each group of digits before the comma
// into its own array index
void input_nums(int array[], int& count){
    char ch = '0';
    cout << "Enter the number using this format(###,###,###) up to 300 digits: ";

    while(ch != '\n'){
        cin >> array[count];
        count += 1;
        cin.get(ch);
    }
}

// array_output() outputs the array, takes in a count variable which is the number
// of digits inputted into the array
void array_output(int array[], int count){
    cout << array[0];
    for(int i = 1; i < count; i++){
        cout << "," << setw(3) << setfill('0') << array[i];
    }
    cout << endl;
}


// sum() sums the elements between array1 and array2, stores into sum[]
void sum(int array1[], int array2[], int sum[], int &count){

    for(int i = 0; i < count; i++){
        sum[i] += array1[i] + array2[i];
        if(sum[i] >= 1000){
            sum[i] -= 1000;
            sum[i + 1] += 1;
        }
    }
    if(sum[count] == 1){
        count++;
    }
}

// swap() swaps the array elements to make arithmetic easier
void swap(int array[], int count){
    int left = 0;
    int right = count - 1;
    int temp = 0;

    while(left < right){
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
}