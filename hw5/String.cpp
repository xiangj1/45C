#include "String.h"

String::String( const char * s)
{
    head = ListNode::stringToList(s);
}
String::String( const String & s )
{
    head = ListNode::copy(s.head);
}
String String::operator = ( const String & s )
{
    head = new ListNode(s.head->info, s.head->next);
    ListNode * temp = head;
    ListNode * sTemp = s.head;

    while(sTemp != nullptr)
    {
        temp->info = sTemp->info;
        temp = temp->next;
        sTemp = sTemp->next;
    }
    return *this;
}
char & String::operator [] ( const int index )
{
    ListNode * temp = head;

    if(!inBounds(index))
    {
        while(temp->next != nullptr)
            temp=temp->next;
        return temp->info;
    }

    for(int i = 0; i <= index; i++)
        temp = temp->next;
    return temp->info;
}
int String::size() const
{
    return ListNode::length(head);
}
int String::indexOf( char c ) const
{
    int index = 0;
    ListNode * temp = head;
    while(temp->info != c)
    {
        temp = temp->next;
        index++;
    }
    return index;
}

bool String::operator== ( const String & s ) const
{
    return ListNode::equal(head,s.head);
}
bool String::operator < ( const String & s ) const
{
    return ListNode::compare(head,s.head)==-1;
}
/// concatenates this and s
String String::operator + ( const String & s ) const
{
    String result;
    char temp[size()+s.size()+1];
    int i = 0;
    for(ListNode* ptr = head; ptr!= nullptr; ptr=ptr->next)
    {
        temp[i] = ptr->info;
        i++;
    }
    for(ListNode* ptr = s.head; ptr!= nullptr; ptr=ptr->next)
    {
        temp[i] = ptr->info;
        i++;
    }
    temp[i] = '\0';
    ListNode::deleteList(head);
    result.head = ListNode::stringToList(temp);

    return result;
}
/// concatenates s onto end of this
String String::operator += ( const String & s )
{
    char temp[size()+s.size()+1];
    int i = 0;
    for(ListNode* ptr = head; ptr!= nullptr; ptr=ptr->next)
    {
        temp[i] = ptr->info;
        i++;
    }
    for(ListNode* ptr = s.head; ptr!= nullptr; ptr=ptr->next)
    {
        temp[i] = ptr->info;
        i++;
    }
    temp[i] = '\0';
    ListNode::deleteList(head);
    head = ListNode::stringToList(temp);

    return *this;
}
String String::reverse() // does not modify this String
{
    String temp(*this);
    for(ListNode * index = head; index != nullptr; index=index->next)
        temp.head = new ListNode(index->info, temp.head);
    return temp;

}


void String::print( std::ostream & out )
{
    ListNode * temp = head;
    while(temp != nullptr)
    {
        out << temp->info;
        temp = temp->next;
    }
}

void String::read( std::istream & in )
{
    ListNode::deleteList(head);
	char * temp = new char[100];
	in.getline(temp, 100);
    int index = 0;
    while(temp[index++]!='\0');
    char * new_temp = new char[index];
    for(int i =0; i < index; i++)
        new_temp[i] = temp[i];
	head = ListNode::stringToList(new_temp);
	delete [] temp;
	delete [] new_temp;
}


std::ostream & operator << ( std::ostream & out, String str )
{
    str.print(out);
    return out;
}

std::istream & operator >> ( std::istream & in, String & str )
{
    str.read(in);
    return in;
}


String::~String()
{
    ListNode::deleteList(head);
}
