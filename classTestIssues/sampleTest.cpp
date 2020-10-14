//from https://www.w3schools.com/cpp/cpp_class_methods.asp
//1fileClassTest.exe is an earlier iteration of this same example, before I split the class definition
//into a separate header file
//I don't know why VS Code is finding errors in the previous comment....

#include <iostream>
#include <string>
#include "myclass.h"
using namespace std;

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  // Print attribute values
  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
}