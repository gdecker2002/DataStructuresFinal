/**************************************************************
* Name        : Data Structures Final
* Author      : Gage Decker
* Created     : 11/1/2021
* Course      : CIS 152 - Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : Data Structures final, Student class with taking down student
*               lunch admission and two decision trees for picking a drink and a side dish.
*               Input:  Menu Traversal, lunch number input, decision making for tree decisions.
*               Output: GUI, Student Info (who has gotten lunch), decision trees
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/
#include <iostream>
#include <list>
#include <array>
#include <iterator>
#include "BinaryTree.h"
using namespace std;

class Student {
  private:
    string fname;
    string lname;
    string grade;
    string pin; //should be a unique 4 digit number
    double costOfLunch; //student cost of lunch (useful for reduced/free lunch)
  public:
    Student(string inputFirst, string inputLast, string inputGrade, string inputPin, double inputLunchCost) { // Constructor with parameters
          fname = inputFirst;
          lname = inputLast;
          grade = inputGrade;
          pin = inputPin;
          costOfLunch = inputLunchCost;
        }
    void setFirst(string input) {
        fname = input;
    }
    string getFirst() {
        return fname;
    }
    void setLast(string input) {
        lname = input;
    }
    string getLast() {
        return lname;
    }
    void setGrade(string input) {
        grade = input;
    }
    string getGrade() {
        return grade;
    }
    void setPin(int input) {
        int size = to_string(input).length();
        if(size == 4) {
            pin = input;
        }
        else {
            cout << "Pin should be 4 digits long." << endl;
        }
    }
    string getPin() {
        return pin;
    }
    void setLunch(double input) {
        costOfLunch = input;
    }
    int getLunch() {
        return costOfLunch;
    }
}; //End of Student Class

void sideTreeDecisions() {
    BinaryTree sideTree;
    sideTree.createSideTree();
    sideTree.callGetUserDecisions();
}
void drinkTreeDecisions() {
    BinaryTree drinkTree;
    drinkTree.createDrinkTree();
    drinkTree.callGetUserDecisions();
}
bool checkPin(Student array[], string pin, int size) {
    for(int i = 0; i < size; i++) {
        if(pin == array[i].getPin()) {
            return true;
        }
    }
    return false;
}
bool checkDupePin(list<Student> list, string pin) {
    std::list<Student>::iterator it;
    for (it = list.begin(); it != list.end(); ++it){
        if(pin == it->getPin()) {
            return true; //Tells that pin is already entered
        }
    }
    return false; //Pin not already entered
}
Student getStudentByPin(Student array[], string pin, int size) {
    for(int i = 0; i < size; i++) {
        if(pin == array[i].getPin()) {
            return array[i];
        }
    }
}

int main()
{
    int const SIZE = 10;
    list<Student> lunchList;
    Student Jessica("Jessica", "Jones", "10", "2000", 5.99);
    Student Scoob("Scooby", "Doo", "12", "2001", 1.99);
    Student Scott("Scott", "Lang", "11", "2002", 0.99);
    Student Robert("Robert", "Downey Jr.", "9", "2003", 4.99);
    Student ChrisP("Chris", "Pratt", "9", "2004", 0);
    Student ChrisE("Chris", "Evans", "9", "2005", 0.99);
    Student Gage("Gage", "Decker", "8", "2006", 5.99);
    Student Bob("Bob", "Barker", "11", "2007", 0.99);
    Student Polly("Polly", "Wanna Cracker", "10", "2008", 1.99);
    Student Peggy("Peggy", "Hill", "12", "2009", 3.99);
    Student studentArray[SIZE] = { Jessica, Scoob, Scott, Robert, ChrisP, ChrisE, Gage, Bob, Polly, Peggy}; //Student Array

    string userInputString = "";
    while(userInputString != "stop") {
    cout << "Please Select an Option\n --------------------------------------\n";
    cout << "1. Take Lunch Attendance\n2. Display Lunch Attendance \n3. Lunch Help - Sides \n4. Lunch Help - Drinks \n";
    cin >> userInputString;
    while(userInputString != "1" && userInputString != "2" && userInputString != "3" && userInputString != "4") {
        cout << "Invalid Choice (1-4): ";
        cin >> userInputString;
    }
    if(userInputString == "1") {
        cout << "\nEnter '0' at any point to return to the main menu\n--------------------------------------\n";
        while(userInputString != "0") {
            cout << "Enter lunch number: "; //Need to loop through students Pin numbers and make sure its a real pin
            cin >> userInputString;

            while(!checkPin(studentArray, userInputString, SIZE)) {//Function here for if PIN is real, loop through student array
                cout << "Invalid Lunch Number: "; //Need to loop through students Pin numbers and make sure its a real pin
                cin >> userInputString;
            }
            if(!checkDupePin(lunchList, userInputString)) {
                lunchList.push_back(getStudentByPin(studentArray, userInputString, SIZE));
                cout << userInputString << " has been added to Lunch Attendance\n";
            }
            else {
                cout << "That Pin has already been entered for Lunch\n";
            }
        }
    }
    else if(userInputString == "2") {
        cout << "\nLunch Attendance: \n--------------------------------------\n";
        //Sort
        //Loop through lunch attendance and display all needed info (fname, lname, pin, etc.)

    }
    else if(userInputString == "3") {
        cout << "\nLunch Help - Sides\n --------------------------------------\n";
        sideTreeDecisions(); //Creates Tree and calls for the decision tree to be traversed
        cout << "\nenter any key to return\n"; //Prevents flood of info and final decision result from being buried
        cin >> userInputString;
    }
    else {
        cout << "\nLunch Help - Drink\n --------------------------------------\n";
        sideTreeDecisions(); //Creates Tree and calls for the decision tree to be traversed
        cout << "\nenter any key to return\n"; //Prevents flood of info and final decision result from being buried
        cin >> userInputString;
    }
    cout << "\nenter 'stop' to end program\n\n";

    }
    return 0;
}
