// Course Grade Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct student { //// looks like [{id},{name},{scores}] 
    string name;
    int id; 
    int* grades;
    double average;
    string letterGrade;
};


void openFile(ifstream& file);
student* getData(ifstream& file, int& studentCnt, int& testsCnt);
void calcAverage(student students[], int studentCnt, int testsCnt);
void cleanUp(student* students, int studentCnt);
void createReport(student students[], int studentCnt, int testCnt);
void calcLetter(student students[], int studentCnt);


int main() {
    int studentCnt, testsCnt;
    ifstream file;
    
    openFile(file);
    
    student* students = getData(file,studentCnt,testsCnt); //students is the size of the array 
    
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
  
    file >> studentCnt >> testsCnt;
    file.ignore();
    
    student* students = new student[studentCnt];
    
    for (int i = 0; i < studentCnt; i++) {
        file >> students[i].name >> students[i].id;

        students[i].grades = new int[testsCnt];
        
        for (int j = 0; j < testsCnt; j++) {
            file >> students[i].grades[j];
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
    cout << "Student    " << "ID    " << "Average   " << "Letter Grade" << endl;
    for (int i = 0; i < studentCnt; i++) {
        while (students[i].name.length() < 9) {
            students[i].name += " ";
        }
        cout << students[i].name << "  " << students[i].id << "     " << students[i].average << "          " << students[i].letterGrade;
        cout << endl;
    }

}
void cleanUp(student* students, int studentCnt) {
    for (int i = 0; i < studentCnt; i++) {
        delete[] students[i].grades;
   }
    delete[] students;
}