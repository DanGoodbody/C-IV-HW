
#ifndef DANIELGOODBODY_QUEUE_H
#define DANIELGOODBODY_QUEUE_H

#include <new>
#include <string>

namespace DanielGoodbody
{
   // *********** Helper Functions for Queue Class *********************//
   template <typename T1, typename T2>
   void
      construct(T1 *p, const T2 &value)
   {
      new (p) T1(value);
   }

   // destroy() destroys an object (but does not deallocate the object's memory)
   template <typename T>
   void 
      destroy(T *p)
   {
      p->~T();
   }

   template <typename FwdIter>
   void 
   destroy(FwdIter first, FwdIter last)
   {
      while (first != last)
      {
         destroy(&*first); // &* converts iter into T *
         ++first;
      }
   }

   template <typename T>
   T *
      newCopy(const T *src, size_t srcsize, size_t destsize)
   {         
      T *dest = new T[destsize];
      try
      {
         copy(src, src + srcsize, dest);
      }
      catch (...)
      {
         delete[] dest; // This can't throw
         throw; // Rethrow original exception
      }
      return dest;
   }

   // swap() just exchanges two values 
   template <typename T>
   void 
      swap(T &a, T &b)
   {
      T temp(a);
      a = b;
      b = temp;
   }
   // ***************************************************************//

   template <typename T> class Queue
   {
   public:      
      Queue(size_t size = 0) // Construct empty queue
         : v_(static_cast<T *>( // Initialize with memory 1 to hold size T's
         size == 0
         ? 0
         : operator new(sizeof(T) * size))),
         vsize_(size),
         vused_(0)
      {
      }

      ~Queue() // Destructor
      {
         destroy(v_, v_ + vused_); // Run destructors on used T's
         operator delete(v_); // Deallocate memory for all T's
      }

      void
         Swap(Queue &other) throw()
      {
         DanielGoodbody::swap(v_, other.v_);
         DanielGoodbody::swap(vsize_, other.vsize_);
         DanielGoodbody::swap(vused_, other.vused_);
      }

      Queue(const Queue &other) // Copy constructor
         : v_(newCopy(other.v_,
         other.vsize_,
         other.vsize_)),
         vsize_(other.vsize_),
         vused_(other.vused_)
      {
      }

      Queue &operator=(const Queue &other) // Copy assignment operator
      {
         Queue temp(other); // Create temp copy of 1 other (can throw)
         Swap(temp); // Swap our guts with temp copy (can't throw)
         return *this;
      }

      void push(const T &other) // Add elem to back of queue
      {
         if (vused_ == vsize_) // Grow if necessary
         {
            Queue temp(vsize_ * 2 + 1); // Create temporary with more space
            while (temp.size() < vused_)
            {
               temp.push(v_[temp.size()]); // Push original values onto temp
            }
            temp.push(other); // Push new value onto temp
            Swap(temp); // Commit: Swap our guts with temp
         } // Temp's destructor destroys old guts
         else
         {
            construct(v_ + vused_, other); // Copy construct t in v_'s memory
            ++vused_;
         }
      }

      void pop() // Remove front elem from queue
      {
         if (vused_ == 0)
         {
            throw logic_error("pop from empty stack");
         }
         else
         {           
            --vused_;
             destroy(v_);
         }
      }

      T &top()
      {
         if (vused_ == 0)
         {
            throw logic_error("empty stack");
         }
         else
         {
            return *v_;
         }
      }

      T &front() { return *v_; } // Return ref to front elem in queue

      const T &front() const { return *v_; } // Return ref to front elem in queue

      bool empty() const // Return whether queue is empty
      {
         return vused_ == 0;
      }

      size_t size() const {return vsize_; } // Return # of elems in queue

      T *display()
      {
         return v_;
      }

   private:
      T *v_; // Elems in queue
      size_t vsize_;
      size_t vused_;
   };
}
#endif //DANIELGOODBODY_QUEUE_H
