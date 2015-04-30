#ifndef DANIELGOODBODY_TESTHOMEWOEKTWO_H
#define DANIELGOODBODY_TESTHOMEWOEKTWO_H

using namespace std;
namespace DanielGoodbody
{
   //Test Class for custom Queue template class
   class TestHomeworkTwo
   {
   public:
      TestHomeworkTwo()
         : testsPassed_(0), totalTests_(0)
      {}
      void testConstructor();
      void testDestructor();
      void testCopyConstructor();
      void testAssignmentOperator();
      void testPush();
      void testPop();
      void testFront();
      void testConstFront();
      void testempty();
      void testUsed();
      void testAll();
      void displayTestResults();
   private:
      int totalTests_;
      int testsPassed_;
   };
}
#endif //DANIELGOODBODY_TESTHOMEWOEKTWO_H
