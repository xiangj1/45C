#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
  public:
    /// Both constructors should construct
    /// from the parameter s
    String( const char * s = "");
    String( const String & s );
    String operator = ( const String & s );
    char & operator [] ( const int index );
    int size() const;
    int indexOf( char c ) const;
    bool operator== ( const String & s ) const;
    bool operator < ( const String & s ) const;
    /// concatenates this and s
    String operator + ( const String & s ) const;
    /// concatenates s onto end of this
    String operator += ( const String & s );
    String reverse(); // does not modify this String
    void print( std::ostream & out );
    void read( std::istream & in );
    ~String();
  private:
    bool inBounds( int i )
    {
      return i >= 0 && i < size();
    }
    struct ListNode
    {
      char info;
      ListNode * next;
      ListNode(char newInfo, ListNode * newNext)
        : info( newInfo ), next( newNext )
      {
      }// Below: primitives you *must* write and use (try recursion)
      static ListNode * stringToList(const char *s)
      {
          return *s == '\0' ? nullptr : new ListNode(*s, stringToList(s+1));
      }
      static ListNode * copy(ListNode * L)
      {
          return L == nullptr ? nullptr : new ListNode(L->info, copy(L->next));
      }
      static bool equal(ListNode * L1, ListNode * L2)
      {
          return compare(L1,L2)==0;
          //return L1 == nullptr || L2 == nullptr ? L1 == L2 : L1->info == L2->info && equal( L1->next, L2->next );
      }
      static ListNode * concat(ListNode * L1, ListNode * L2)
      {
          return L1 == nullptr ? copy(L2): new ListNode(L1->info, concat(L1->next, L2));
      }
      static int compare(ListNode * L1, ListNode * L2)//like strcmp
      {
          if(L1==nullptr && L2==nullptr)
            return 0;
          else if(L1==nullptr)
            return -1;
          else if(L2==nullptr)
            return 1;

          if(L1->info==L2->info)
              return compare(L1->next, L2->next);
          else if(L1->info > L2->info)
            return 1;
          else if(L1->info < L2->info)
            return -1;
        return 7;//warning cases
      }
      static void deleteList(ListNode * L)
      {
          if(L!=nullptr)
            deleteList(L->next);
          delete [] L;
      }
      static int length(ListNode * L)
      {
          if(L->next == nullptr)
            return 0;
          else
            return 1 + length(L->next);
      } // O(N) so call rarely
    };
    ListNode * head; // no other data members!! - especially no len!
};

std::ostream & operator << ( std::ostream & out, String str );
std::istream & operator >> ( std::istream & in, String & str );

#endif // STRING_H
