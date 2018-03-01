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
    for(int i =0; i < strlen(s); i++)
        buf[i] = s[i];
    buf[strlen(s)] = '\0';
}

String::String( const String & s )
{
    for(int i =0; i < strlen(s.buf); i++)
        buf[i] = s.buf[i];
}

String String::operator = ( const String & s )
{
    strcpy(buf, s.buf);
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
                return i;
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
    String result(*this);
    strcat(result.buf, s.buf);
    return result;
}
/// concatenates s onto end of this
String String::operator += ( const String s )
{
    strcat(buf, s.buf);
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
