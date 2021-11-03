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
    int userInputInt;
    return 0;
}
