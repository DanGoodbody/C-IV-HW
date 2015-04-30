#include <iostream>
#include <string>
#include "Queue.h"
#include "TestHomeworkTwo.h"

using namespace std;
using namespace DanielGoodbody;

void 
   TestHomeworkTwo::testAll()
{
   TestHomeworkTwo tester;
   tester.testConstructor();
   tester.testPush();
   tester.testDestructor();
   tester.testCopyConstructor();
   tester.testAssignmentOperator();
   tester.testPop();   
   tester.testFront();
   tester.testConstFront();
   tester.testempty();
   tester.testUsed();

   tester.displayTestResults();
}

void
   TestHomeworkTwo::testConstructor()
{
   totalTests_++;
   Queue<string> testBufferSize(10);
   if (testBufferSize.size() == 10)
   {
      testsPassed_++;    
   }
}

void 
TestHomeworkTwo::testPush()
{
   totalTests_++;
   Queue<string> testString(10);
   testString.push("what");
   testString.push("the");
   testString.push("hell");
   testString.push("does");
   testString.push("this");
   testString.push("work");
   testString.push("if");
   testString.push("I");
   testString.push("Push");
   testString.push("more");
   testString.push("than");
   testString.push("10");
   testString.push("items");
   testString.push("!");
   string tester = "";

   string *what = testString.display();

   if (*what == "what")
   {
      testsPassed_++;
   }
}

void 
   TestHomeworkTwo::testDestructor()
{
   totalTests_++;
   Queue<double> testDouble(10);
   testDouble.push(25.0);
   double *what = testDouble.display();

   if (*what == 25.0)
   {
      testsPassed_++;
   }
}

void 
   TestHomeworkTwo::testCopyConstructor()
{
   totalTests_++;
   Queue<double> testDouble(10);
   testDouble.push(25.0);
   Queue<double> testTestDouble(testDouble);
   double *what = testTestDouble.display();

   if (*what == 25.0)
   {
      testsPassed_++;
   }
}

void
   TestHomeworkTwo::testAssignmentOperator()
{
   totalTests_++;
   Queue<double> testDouble(10);
   testDouble.push(25.0);
   testDouble.push(12.0);
   Queue<double> testTestDouble(10);
   testTestDouble = testDouble;
   double *what = testTestDouble.display();
   if (what[1] == 12.0)
   {
      testsPassed_++;
   }
}

//Push three ints then pop all three
void 
TestHomeworkTwo::testPop()
{
   totalTests_++;
   Queue<int> testInt(10);
   testInt.push(12);   //FIFO
   testInt.push(15);
   testInt.push(30);
   testInt.push(50);
   testInt.push(65);

   int what = testInt.top(); //12
   testInt.pop();

   what = testInt.top(); //15
   testInt.pop();

   what = testInt.top(); //30
   testInt.pop();
   if (what == 30)
   {
      testsPassed_++;
   }
}

//Push 3 chars and return the front of the queue
void 
TestHomeworkTwo::testFront()
{
   totalTests_++;
   Queue<char> testChar(10);
   testChar.push('a');
   testChar.push('h');
   testChar.push('g');

   char what = testChar.front();
   if (what == 'a')
   {
      testsPassed_++;
   }
}

void
TestHomeworkTwo::testConstFront()
{
   totalTests_++;
   Queue<char> testChar(10);
   testChar.push('a');
   testChar.push('h');
   testChar.push('g');
   Queue<char> constChar(testChar);

   char what = constChar.front();
   if (what == 'a')
   {
      testsPassed_++;
   }
}

//Test for empty queue
void 
TestHomeworkTwo::testempty()
{
   totalTests_++;
   Queue<char> testEmpty(10);
   if (testEmpty.empty())
   {
      testsPassed_++;
   }
}

//Return size of buffer
void 
TestHomeworkTwo::testUsed()
{
   totalTests_++;
   Queue<char> testChar(10);
   testChar.push('a');
   testChar.push('h');
   testChar.push('g');
   if (testChar.used() == 3)
   {
      testsPassed_++;
   }
}

void 
TestHomeworkTwo::displayTestResults()
{
   cout << testsPassed_ << " tests passed out of " << totalTests_ << "\n\n";
}
