#include <iostream>
#include "Queue.h"
#include "TestHomeworkTwo.h"

using namespace std;
// Creates an instance of the TestHomeworkTwo class
// that will perform unit tests on the custom Queue class
int main()
{
   DanielGoodbody::TestHomeworkTwo tests;
   tests.testAll();
   cout << endl << "Press enter to continue...";
   cin.get();
}
