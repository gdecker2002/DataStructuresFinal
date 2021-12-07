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
#include <iomanip> //precision
#include "BinaryTree.h"
using namespace std;

class Student {
  private:
    string fname;
    string lname;
    string grade;
    string pin; //should be a unique 4 digit number
    string costOfLunch; //student cost of lunch (useful for reduced/free lunch)
  public:
    Student(string inputFirst, string inputLast, string inputGrade, string inputPin, string inputLunchCost) { // Constructor with parameters
          fname = inputFirst;
          lname = inputLast;
          grade = inputGrade;
          pin = inputPin;
          costOfLunch = inputLunchCost;
        }
    void setFirst(string input) { //Getters and Setters
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
    void setPin(string input) {
        int size = input.length();
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
    void setLunch(string input) {
        costOfLunch = input;
    }
    string getLunch() {
        return costOfLunch;
    }
}; //End of Student Class

void sideTreeDecisions() { //Calls functions for the sideTree
    BinaryTree sideTree;
    sideTree.createSideTree();
    sideTree.callGetUserDecisions();
}
void drinkTreeDecisions() { //Calls functions for the drinkTree
    BinaryTree drinkTree;
    drinkTree.createDrinkTree();
    drinkTree.callGetUserDecisions();
}
bool checkPin(Student array[], string pin, int size) { //Checks if PIN is valid
    for(int i = 0; i < size; i++) {
        if(pin == array[i].getPin()) {
            return true;
        }
    }
    return false;
}
bool checkDupePin(list<Student> list, string pin) { //Checks if pin has been entered already
    std::list<Student>::iterator it;
    for (it = list.begin(); it != list.end(); ++it){
        if(pin == it->getPin()) {
            return true; //Tells that pin is already entered
        }
    }
    return false; //Pin not already entered
}
Student getStudentByPin(Student array[], string pin, int size) { //returns student object based on PIN
    for(int i = 0; i < size; i++) {
        if(pin == array[i].getPin()) {
            return array[i];
        }
    }
}

string getStudentInfoByPin(Student array[], string pin, int size) { //Displays student info based on PIN
    string returnString;
    for(int i = 0; i < size; i++) {
        if(pin == array[i].getPin()) {
            returnString = "First: " + array[i].getFirst() + "  Last: " + array[i].getLast() + "  Pin: " + array[i].getPin() + "  Cost Of Lunch: $" + array[i].getLunch() + "\n";
            return returnString;
        }
    }
}

class LinkedList {
  // attributes
public:
    int position;
    string pin; //Will be used to get Student and for sorting
    string *list=new string[15]; //List array
    int size = 0;
    int maxSize = 15;
    int head = 0;
  // Constructors
  LinkedList() {

  };
  // Methods
  int find_string(string item) //Used to find value within List
  {
  int i;
  for(i = 0; i < maxSize; i++) { //Loops through List
  if(list[i] == item) //If value found returns true
      return 1;
  }
      return 0;
  }
  void createList(int inputSize, Student array[])
  {
      maxSize = inputSize;
      size = 0;
      int i = 0;
      while(i < maxSize){
          list[i] = array[i].getPin();
          i++;
      }
  }

  void removeAt(int position){
      if(position < 0 || position >= size){
          cout << "There is nothing at index " << position << endl;
      }
      else {
          string remove;
          remove = list[position]; //removing
          for(int i = position;i < size; i++)
          {
              list[i]=list[i+1]; //Shifts array
          }
      size--; //Decrement size
      }
  }
  void insert(string input) { //inserts value
      list[size] = input;
      size += 1;
  }
  bool isEmpty() const //Checks if empty
  {
      if(size == 0) {
          return true;
      }
      else {
          return false;
      }
  }
  bool isFull() const
  {
      return size == maxSize; //Returns true or false if array is full
  }
  string get(int position) {
          return list[position]; //Returns value at array position
  }
  void insertionSort()
  {
      int i, j;
      string pin;
      for (i = 1; i < size; i++)
      {
          pin = list[i]; //key will be used to compare array values
          j = i - 1;
          while (j >= 0 && list[j] > pin) // Moves elements that are "key" to one position ahead of their current position
          {
              list[j + 1] = list[j];
              j = j - 1;
          }
          list[j + 1] = pin;
      }
  }

  void display() {
      while(!isEmpty()) {
          cout << get(0) << " ";
          removeAt(0);
      }
  }
};

int main()
{
    int const SIZE = 10;
    list<Student> lunchList; //List Creation
    LinkedList studentLinkedList; //Linked List Creation
    Student Jessica("Jessica", "Jones", "10", "2000", "5.99"); //Initial Student Objects
    Student Scoob("Scooby", "Doo", "12", "2001", "1.99");
    Student Scott("Scott", "Lang", "11", "2002", "0.99");
    Student Robert("Robert", "Downey Jr.", "9", "2003", "4.99");
    Student ChrisP("Chris", "Pratt", "9", "2004", "0");
    Student ChrisE("Chris", "Evans", "9", "2005", "0.99");
    Student Gage("Gage", "Decker", "8", "2006", "5.99");
    Student Bob("Bob", "Barker", "11", "2007", "0.99");
    Student Polly("Polly", "Wanna Cracker", "10", "2008", "1.99");
    Student Peggy("Peggy", "Hill", "12", "2009", "3.99");
    Student Dummy("", "", "", "", "0");
    Student studentArray[SIZE] = { Jessica, Scoob, Scott, Robert, ChrisP, ChrisE, Gage, Bob, Polly, Peggy}; //Student Array

    string userInputString = "";
    while(userInputString != "stop") { //Program runs while input != 'stop'
    cout << "Please Select an Option\n --------------------------------------\n";
    cout << "1. Take Lunch Attendance\n2. Display Lunch Attendance \n3. Lunch Help - Sides \n4. Lunch Help - Drinks \n\n'stop' to end program\n";
    cin >> userInputString;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //Used to avoid multiple input with spaces
    while(userInputString != "1" && userInputString != "2" && userInputString != "3" && userInputString != "4" && userInputString != "stop") {
        cout << "Invalid Choice (1-4): ";
        cin >> userInputString;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //Used to avoid multiple input with spaces
    }
    if(userInputString == "1") {
        cout << "\nEnter '0' at any point to return to the main menu\n--------------------------------------\n";
        while(userInputString != "0") {
            cout << "Enter lunch number: "; //Need to loop through students Pin numbers and make sure its a real pin
            cin >> userInputString;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //Used to avoid multiple input with spaces

            if(userInputString == "0") { //breaks out of if statement back to menu if 0
                break;
            }

            while(!checkPin(studentArray, userInputString, SIZE)) {//Function here for if PIN is real, loop through student array
                cout << "Invalid Lunch Number: "; //Need to loop through students Pin numbers and make sure its a real pin
                cin >> userInputString;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //Used to avoid multiple input with spaces
                if(userInputString == "0") { //breaks while loop
                    break;
                }
            }
            if(userInputString == "0") { //breaks out of if statement back to menu if 0
                break;
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
        string inputPin = "";
        int listSize = lunchList.size();
        std::list<Student>::iterator it;
        for (it = lunchList.begin(); it != lunchList.end(); ++it){ //iterates through list
            studentLinkedList.insert(it->getPin()); //inserts pins from list into linkedlist
        }

        studentLinkedList.insertionSort(); //sorts by pin
        for(int i = 0; i < listSize; i++){ //loops through linked list
            inputPin = studentLinkedList.get(i); //gets pin from studentLinkedList which will be used to retrieve student info
            cout << getStudentInfoByPin(studentArray, inputPin, SIZE) << "\n"; //retrieves and displays student info based on pin
    }
        while(!studentLinkedList.isEmpty()) { //Removes Items until linked list is empty
            studentLinkedList.removeAt(0);
        }

    }
    else if(userInputString == "3") {
        cout << "\nLunch Help - Sides\n --------------------------------------\n";
        sideTreeDecisions(); //Creates Tree and calls for the decision tree to be traversed
        cout << "\nenter any key to return\n"; //Prevents flood of info and final decision result from being buried
        cin >> userInputString;
    }
    else if(userInputString == "4"){
        cout << "\nLunch Help - Drinks\n --------------------------------------\n";
        drinkTreeDecisions(); //Creates Tree and calls for the decision tree to be traversed
        cout << "\nenter any key to return\n"; //Prevents flood of info and final decision result from being buried
        cin >> userInputString;
    }
    }
    return 0;
}
