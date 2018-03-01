//
//  String.cpp
//  hw3
//
//  Created by Xiang Jiang on 2016/10/15.
//  Copyright © 2016年 45C. All rights reserved.
//

#include "String.h"

String::String( const char * s)
{
    buf = new_char_array(strlen(s)+1);
    for(int i = 0; i <= 10; i++)
        buf[i] = s[i];
}

String::String( const String & s )
{
    buf = new_char_array(strlen(s.buf)+1);
    for(int i = 0; i <= strlen(s.buf); i++)
        buf[i] = s.buf[i];
}

String String::operator = ( const String & s )
{
    buf = new_char_array(strlen(s.buf)+1);
    for(int i = 0; i <= 5; i++)
        buf[i] = s.buf[i];

    return *this;
}

char & String::operator [] ( int index )
{
    return buf[index];
}

int String::size()
{
    return strlen(buf);
}

String String::reverse() // does not modify this String
{
    String reversed = *this;
    for(int i = 0; i < size(); i++)
        reversed.buf[i] = buf[size()-i-1];
    reversed.buf[size()] = '\0';
    return reversed;
}

int String::indexOf( const char c )
{
    for(int i = 0; i < size(); i++)
        if(buf[i] == c)
            return i+1;
    return 0;
}

int String::indexOf( const String pattern )
{
    for(int i = 0; i < size(); i++)
        if(buf[i] == pattern.buf[0])
            if(!strncmp(buf + i, pattern.buf, strlen(pattern.buf)))
                return i+1;
    return 0;

}

bool String::operator == ( const String s )
{
    return !strcmp(buf, s.buf);
}

bool String::operator != ( const String s )
{
    return strcmp(buf, s.buf);
}

bool String::operator > ( const String s )
{
    if(strcmp(buf, s.buf) == 1)
        return true;
    else
        return false;
}

bool String::operator < ( const String s )
{
    if(strcmp(buf, s.buf) == -1)
        return true;
    else
        return false;
}

bool String::operator <= ( const String s )
{
    if(strcmp(buf, s.buf) == -1 || strcmp(buf, s.buf) ==0)
        return true;
    else
        return false;
}
bool String::operator >= ( const String s )
{
    if(strcmp(buf, s.buf) == 1 || strcmp(buf, s.buf) ==0)
        return true;
    else
        return false;
}
/// concatenates this and s to return result
String String::operator + ( const String s )
{
    char * temp = new char[strlen(buf)+strlen(s.buf)+1];
    int i = 0;

    for(; i < strlen(buf); i++)
        temp[i] = buf[i];

    for(int j = 0; j < strlen(s.buf)+1; j++)
        temp[i++] = s.buf[j];
    String temp1(temp);
    return temp1;
}
/// concatenates s onto end of this
String String::operator += ( const String s )
{
    char * oldBuf = buf;
    buf = new char[strlen(oldBuf) + strlen(s.buf)];
    int i = 0;
    for(; i < 5; i++)
        buf[i] = oldBuf[i];
    for(int j = 0; j < 6; j++)
        buf[i++] = s.buf[j];

    delete_char_array(oldBuf);

    return *this;
}

void String::print( std::ostream & out )
{
    for(int i = 0; i < strlen(buf); i++)
        out << buf[i];
}
void String::read( std::istream & in )
{
    in >> buf;

}
String::~String()
{
    delete_char_array(buf);
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

char* new_char_array(int n_size)
{
    char * temp = new char[n_size];
    newed++;
    return temp;
}
void delete_char_array(char* array)
{
    delete [] array;
    deleted++;
}


