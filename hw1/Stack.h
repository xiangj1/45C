#ifndef Stack_h
#define Stack_h
#define STACK_CAPACITY 1000

class Stack
{
private:
    int index;
    char array[STACK_CAPACITY];
public:
    Stack(); // constructor for a stack
    void push( char c ); // adds c to the top of the stack
    char pop(); // removes top element
    char top(); // returns the top element
    bool isEmpty(); // returns true iff the stack is empty
    bool isFull(); // returns true iff the stack is full
    ~Stack(); // destructor for a stack
};

Stack::Stack()
{
    index = 0;
    //char array[STACK_CAPACITY] = {'0'};
}

Stack::~Stack()
{
    
}

void Stack::push(char c)
{
    array[++index] = c;
}

char Stack::pop()
{
    return array[index--];
}

char Stack::top()
{
    return array[index];
}

bool Stack::isEmpty()
{
    return index?false:true;
}

bool Stack::isFull()
{
    return index==999;
}

#endif /* Stack_h */

