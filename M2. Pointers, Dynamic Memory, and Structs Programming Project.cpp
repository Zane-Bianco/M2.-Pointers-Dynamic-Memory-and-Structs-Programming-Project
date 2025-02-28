// Course Grade Program.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Program first verifies that it can open text file in the same directory named "StudentGrades.txt". 

// It then reads through the data within the text file, starting with the header being the number of students and then the number of tests.

// It then skips to  the next line and then iterates line by line to extract student data, putting them into a pointer variable and sending it into the struct for each student.

// Program returns from getData function and then if "students" is not null proceeds into the other functions.

// Program first calculates the average of each students grades and then stores them back in the struct for later.

// It then enters the letterGrade function and figures out what letter grade the student would have using their average from struct and stores it there aswell.

// It then goes into the createReport function and generates a formatted report using the students information and outputs it in a easily readable format.

// After these processes have been completed it then goes to cleanUp to deallocate the memory for the dynamically allocated arrays to track the student's information.

#include <iostream>
#include <fstream> // for file reading 
#include <string> // for string data type
#include <iomanip> // for report formatting


using namespace std;

struct student { 
    string name;
    int id = 0; 
    int* grades = 0;
    double average = 0;
    string letterGrade;
};

//Input: Memory address for "file" Preconditions: Memory Addresses for file must be made
//Postcondition: Either the "file" is opened,confirmation is outputted and "file" is returned to main() or an error that it failed to open said "file"
void openFile(ifstream& file);

//Input: Memory addresses for "file", "studentCnt", "testsCnt" 
//Preconditions: "file" must be opened in the openFile function. 
//Postconditions: Will return "Students" variable that points to the "student" struct, 
student* getData(ifstream& file, int& studentCnt, int& testsCnt);

//Input: student struct, studentCnt, testsCnt 
//Preconditions: "students" must not be null 
//Postcondition: calculates the grade average using "grades" from the "student" stuct and the "testsCnt" variable for each student in the struct 
//and assigns it to "average" and then returns it to the struct
void calcAverage(student students[], int studentCnt, int testsCnt);

//Input: "student" struct and "studentCnt" 
//Preconditions: "Average" must not be null and there must be atleast one student in the struct
//Postcondition: Uses the "student" struct to get the "Average" for each student and calculates their lettergrade,
//Then returns "letterGrade" to student struct for later use.
void calcLetter(student students[], int studentCnt);

//Input: "student" struct, studentCnt, and testCnt variables 
//Preconditions:"students" must not be null, studentCnt and testsCnt must be > 0 
//Postconditions: outputs a formatted report of each student with their name,id, average, and letter grade pulled from "student" struct
void createReport(student students[], int studentCnt, int testsCnt);

//Input: student struct, studentCnt 
//Preconditions: student "grades" array and "student" struct must exist and be populated 
//Postconditions: cleanUp sets both the student struct and "grades" array to null. Deallocating memory that was allocated for these data structures
void cleanUp(student* students, int studentCnt);

int main() {
    int studentCnt, testsCnt;
    ifstream file;
    
    openFile(file);
    
    student* students = getData(file,studentCnt,testsCnt);
    
    if (students) {
        calcAverage(students, studentCnt, testsCnt);
        calcLetter(students, studentCnt);
        createReport(students, studentCnt,testsCnt);
        cleanUp(students, studentCnt);
    }
    return 0;
}

void openFile(ifstream& file) {
    file.open("StudentGrades.txt");
    if (file.is_open()){
        cout << "File opened sucesssfully!" << endl;
        cout << endl;
    }
    else {
        cerr << "Unable to open file, make sure it's in the same directory." << endl;
        exit(1);
    }
}

student* getData(ifstream& file, int& studentCnt, int& testsCnt){
  
    file >> studentCnt >> testsCnt; // Reads header to find the number of students and the number of tests and assigns them each to a variable.

    student* students = new student[studentCnt];
    
    for (int i = 0; i < studentCnt; i++) {
        file >> students[i].name >> students[i].id;

        students[i].grades = new int[testsCnt];
        
        for (int j = 0; j < testsCnt; j++) {
            if (!(file >> students[i].grades[j])) {
                students[i].grades[j] = 0;
            }
        }
    }  
    file.close();
    return students;
}

void calcAverage(student students[], int studentCnt, int testsCnt) {
    for (int i = 0; i < studentCnt; i++) {
        double total = 0;
        for (int j = 0; j < testsCnt; j++) {
            total += students[i].grades[j];
        }
        students[i].average = total / testsCnt;
    }
}

void calcLetter(student students[], int studentCnt) {
    for (int i = 0; i < studentCnt; i++) {
        if (students[i].average >= 90) {
            students[i].letterGrade = "A";
         }
        else if (students[i].average >= 80) {
             students[i].letterGrade = "B";
             }
        else if (students[i].average >= 70) {
            students[i].letterGrade = "C";
             }
        else if (students[i].average >= 60) {
        students[i].letterGrade = "D";
             }
        else {
             students[i].letterGrade = "F";
             }
        }
    }
    
void createReport(student students[], int studentCnt, int testsCnt) {
    size_t columnWidth = 0;
    for (int i = 0; i < studentCnt; i++) {
        if (students[i].name.length() > columnWidth) {
            columnWidth = students[i].name.length() + 1;
        }
    }
    
    cout << left << setw(columnWidth) << "Student"
        << setw(8) << "ID"
        << setw(10) << "Average"
        << "Letter Grade" << endl;

    cout << string(42, '-') << endl;

    for (int i = 0; i < studentCnt; i++) {
        cout << left << setw(columnWidth) << students[i].name
            << setw(8) << students[i].id
            << setw(1) << ""
            << fixed << setprecision(1) << setw(10) << students[i].average
            << setw(4) << ""
            << students[i].letterGrade 
            << setw(4) << ""
            << endl;
    }
}

void cleanUp(student* students, int studentCnt) {
    for (int i = 0; i < studentCnt; i++) {
        delete[] students[i].grades;
   }
    delete[] students;
}