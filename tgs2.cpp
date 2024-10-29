#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readData(studentType* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Masukkan nama depan, nama belakang, dan nilai tes untuk siswa " << i + 1 << ":\n";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
    }
}

void assignGrades(studentType* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].testScore >= 85) students[i].grade = 'A';
        else if (students[i].testScore >= 70) students[i].grade = 'B';
        else if (students[i].testScore >= 55) students[i].grade = 'C';
        else if (students[i].testScore >= 20) students[i].grade = 'D';
        else students[i].grade = 'E';
    }
}

int findHighestScore(studentType* students, int numStudents) {
    int highestScore = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].testScore > highestScore)
            highestScore = students[i].testScore;
    }
    return highestScore;
}

void printStudents(studentType* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(20) << (students[i].studentLName + ", " + students[i].studentFName)
             << "Nilai: " << students[i].testScore << ", Grade: " << students[i].grade << endl;
    }
}

// Function to print names of students with the highest score in Indonesian
void printHighestScorers(studentType* students, int numStudents, int highestScore) {
    cout << "\nSiswa dengan nilai tertinggi (" << highestScore << "):\n";
    for (int i = 0; i < numStudents; i++) {
        if (students[i].testScore == highestScore) {
            cout << left << setw(20) << (students[i].studentLName + ", " + students[i].studentFName) 
                 << "Nilai: " << students[i].testScore << ", Grade: " << students[i].grade << endl;
        }
    }
}

int main() {
    int numStudents = 20;
    
    studentType* students = new studentType[numStudents];

    readData(students, numStudents);
    assignGrades(students, numStudents);
    int highestScore = findHighestScore(students, numStudents);
    printStudents(students, numStudents);
    printHighestScorers(students, numStudents, highestScore);Q

    return 0;
}
