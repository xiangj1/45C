#define MAXLEN 128
#include <iostream>

class String
{
private:
    bool inBounds( int i )
    {
        return i >= 0 && i < strlen(buf);
    }// HINT: some C string primitives you should define and use
    static int strlen( const char *s )
    {
        int count = 0;
        while(s[count]!= '\0')
            count++;
        return count;
    }
    
    static char * strcpy( char *dest, const char *src )
    {
        for(int i = 0; i < strlen(src)+1; i++)
            dest[i] = src[i];
        return dest;
    }
    
    static char * strcat(char *dest, const char *src)
    {
        int dest_len = strlen(dest);
        for(int i = 0; i < strlen(src)+1; i++)
            dest[dest_len+i] = src[i];
        return dest;
    }
    static int strcmp( const char *left, const char *right )
    {
        for(int i = 0; i < strlen(left); i++)
        {
            if(left[i] < right[i])
                return -1;
            else if(left[i] > right[i])
                return 1;
        }
        return 0;
    }
    static int strncmp( const char *left, const char *right, int n )
    {
        int lenth = 0;
        if(n >= strlen(left))
            lenth = strlen(left);
        else if (n < strlen(left) & n > 0)
            lenth = n;
        
        for(int i = 0; i < n; i++)
        {
            if(left[i] < right[i])
                return -1;
            else if(left[i] > right[i])
                return 1;
        }
        return 0;
    }
    static char * strchr( const char *str, int c )
    {
        for(int i = 0; i < strlen(str); i++)
            if (str[i] == (char)c)
                return (char*)str + i;
        return nullptr;
    }
    static char * strstr( const char *haystack, const char *needle )
    {
        
        for(int i = 0; i < strlen(haystack); i++)
            if(haystack[i] == needle[0])
                if(!strcmp((char*)haystack + i, needle))
                    return (char*)haystack + i;
        return nullptr;
    }
    char buf[MAXLEN]; // array for the characters in this string
    // DO NOT store the ‘logical’ length of this string
    // use the null ‘\0’ terminator to mark the end
    
public:
    /// Both constructors should construct
    /// this String from the parameter s
    String( const char * s = "");
    String( const String & s );
    String operator = ( const String & s );
    char & operator [] ( int index );
    int size();
    String reverse(); // does not modify this String
    int indexOf( const char c );
    int indexOf( const String pattern );
    bool operator == ( const String s );
    bool operator != ( const String s );
    bool operator > ( const String s );
    bool operator < ( const String s );
    bool operator <= ( const String s );
    bool operator >= ( const String s );
    /// concatenates this and s to return result
    String operator + ( const String s );
    /// concatenates s onto end of this
    String operator += ( const String s );
    void print( std::ostream & out );
    void read( std::istream & in );
    ~String();
    
};

std::ostream & operator << ( std::ostream & out, String str );
std::istream & operator >> ( std::istream & in, String & str );
