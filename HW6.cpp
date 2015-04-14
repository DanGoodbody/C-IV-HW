#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>       

class IntegerSequence
{
public:
   IntegerSequence(int initialValue)
      : value_(initialValue) {}
   int operator() () { return ++value_; }
private: 
   int value_;
};

using namespace std;
int testDequeFunctionality()
{   
   const size_t SIZE = 10;
   IntegerSequence sequence(0);
   std::deque<int> demoDeque;   
   generate_n(back_inserter(demoDeque), SIZE, sequence);
   return  accumulate(demoDeque.begin(), demoDeque.end(), 0);
}

int main()
{
   cout << testDequeFunctionality();
}