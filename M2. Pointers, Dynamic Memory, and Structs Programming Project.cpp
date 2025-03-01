// Reverse Array Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Creates an array that sizes varies on input then populates the array from input
//Then creates another array that stores the original array but in reverse
//Then outputs the orginial and reversed array
//Then clears the allocated memory 

#include <iostream>

using namespace std;

//Input: Memory Address for variable "size"
//Preconditions:None
//Postconditions: Returns integer variable "size" used to dynamically allocate an array of said 
void getArraySize(int& size);

//Input: "Size" variable
//Preconditions: "size" must be an > 0 integer
//Postconditions: populates array with "size" integers from input and returns to arr pointer variable
int* getArray(int size);

//Input:"arr" array and "size" variable
//Precondtions: "arr" array must be populated and "size" variable must be valid
//Postconditions: iterates through "arr" array and assigns them to "reversedArr" in reverse using a loop
int* reverseArray(const int arr[], int size);

//Input: the "arr" array and "size" variable
//Preconditions: "arr" array must be populated and "size" variable must be valid
//Postconditions: prints out "Originial Array: " then the elements within "arr" array
void printOriginalArray(const int arr[], int size);

//Input: the "reversedArr" array and "size" variable
//Preconditions: "reversedArr" array must be populated and "size" variable must be valid
//Postconditions: prints out "Reversed Array: " then the elements within "reversed" array
void printReversedArray(const int reversedArr[], int size);

int main()
{
    int size;
    
    getArraySize(size);

    int* arr = getArray(size);

    printOriginalArray(arr, size);

    int* reversedArr = reverseArray(arr,size);
    
    printReversedArray(reversedArr, size);

    delete[] arr;
    delete[] reversedArr;
    reversedArr = nullptr;
    arr = nullptr;
    return 0;
}

void getArraySize(int& size) {
    cout << "What is the array size:";
    while (!(cin >> size) || size <= 0) {
        cout << "Invalid input. Please enter a nonzero positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int* getArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "What integer for index " << i << "?" << endl;
        cin >> arr[i];   
    }
    return arr;
}

int* reverseArray(const int arr[], int size) {
    int* reversedArr = new int[size];
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i];
    }
    return reversedArr;
}

void printOriginalArray(const int arr[], int size) {
    cout << "Original Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
    }   
}
void printReversedArray(const int reversedArr[], int size) {
    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++) {
        cout << reversedArr[i] << " ";
    }
}

