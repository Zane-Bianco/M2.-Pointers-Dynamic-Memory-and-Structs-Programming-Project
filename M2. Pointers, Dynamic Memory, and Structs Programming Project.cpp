// Reverse Array Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void getArraySize(int& size);
int sizeVerification(int size);
int* getArray(int size);
int* reverseArray(const int arr[], int size);
void printOriginalArray(const int arr[], int size);
void printReversedArray(const int reversedArr[], int size);

int main()
{
    int size;
    
    getArraySize(size);
    size = sizeVerification(size);

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
    cin >> size;
}

int sizeVerification(int size) {
    while (size <= 0) {
        cout << "Invalid size, please enter a nonzero positive integer: \n";
        cin >> size;
     }
    return size;
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

