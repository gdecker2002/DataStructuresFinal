#include <iostream>
using namespace std;

class Student {
  private:
    string fname;
    string lname;
    string grade;
    int pin; //should be a unique 4 digit number
    double costOfLunch; //student cost of lunch (useful for reduced/free lunch)
  public:
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
    int getPin() {
        return pin;
    }
    void setLunch(double input) {
        costOfLunch = input;
    }
    int getLunch() {
        return costOfLunch;
    }
};
int main()
{
    string userInputString = "";
    int userInputInt = -1;
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
        }
            //Function here for if PIN is real, loop through student array

        }
    else if(userInputString == "2") {
        cout << "\nLunch Attendance: \n--------------------------------------\n";

        //Loop through lunch attendance and display all needed info (fname, lname, pin, etc.)

    }
    else if(userInputString == "3") {
        cout << "\nLunch Help - Sides\n --------------------------------------\n";

        //Implement binary decision tree

    }
    else {
        cout << "\nLunch Help - Drink\n --------------------------------------\n";

        //Implement binary decision tree

    }
    cout << "\nenter 'stop' to end program\n\n";

    }
    return 0;
}
