//
//  MapArray.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/28.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef MAPARRAY_H
#define MAPARRAY_H

#include <utility>
#include <algorithm>
#include <iterator>
#include <initializer_list>

template < typename key, typename T>
class MapArray
{
    int sz;
    std::pair<key, T>* buf;
    
public:
    struct iterator
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef key key_type;
        typedef T mapped_type;
        typedef std::pair<key, T> value_type;
        typedef value_type& reference;
        typedef value_type* pointer;

    private:
        pointer buf;
    public:
        iterator(pointer ptr):buf(ptr) {}
        self_type operator++()
        {
            ++buf;
            return *this;
        }
        self_type operator++(int postfix)
        { self_type cpy = *this; buf++; return cpy; }
        self_type operator--()
        {
            --buf;
            return *this;
        }
        self_type operator--(int postfix)
        {
            self_type cpy = *this;
            buf--;
            return cpy;
        }
        
        reference operator*()
        { return *buf; }
        pointer operator->()
        { return buf; }
        bool operator==(const self_type& rhs) const
        { return buf == rhs.buf; }
        bool operator!=(const self_type& rhs) const
        { return buf != rhs.buf; }
        bool operator<(const self_type& rhs)const
        {
            return buf->first< rhs.buf->first;
        }
        bool operator>(const self_type& rhs) const
        {
            return buf->first> rhs.buf->first;;
        }
        bool operator<= (const self_type& rhs) const
        {
            return *this < rhs || *this == rhs;
        }
        bool operator>= (const self_type& rhs) const
        {
            return *this > rhs|| *this == rhs;
        }
        self_type operator+=(int i)
        {
            buf += i;
            return *this;
        }
        self_type operator+(int i)
        {
            self_type temp = *this;
            temp += i;
            return temp;
        }
        self_type operator-=(int i)
        {
            buf -= i;
            return *this;
        }
        self_type operator-(int i)
        {
            self_type temp = *this;
            temp -= i;
            return temp;
        }
        
    };
    class const_iterator
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef const_iterator self_type;
        typedef key key_type;
        typedef T mapped_type;
        typedef std::pair<key, T> value_type;
        typedef value_type& reference;
        typedef value_type* pointer;
        //typedef ptrdiff_t difference_type;
        //this one does not work in the openlab
    private:
        pointer buf;
        
    public:
        const_iterator(pointer ptr):buf(ptr) {}
        self_type operator++()
        {
            ++buf;
            return *this;
        }
        self_type operator++(int postfix)
        { self_type cpy = *this; buf++; return cpy; }
        self_type operator--()
        {
            --buf;
            return *this;
        }
        self_type operator--(int postfix)
        {
            self_type cpy = *this;
            buf--;
            return cpy;
        }
        
        
        reference operator*()
        { return *buf; }
        const pointer operator->()
        { return buf; }
        bool operator==(const self_type& rhs) const
        { return buf == rhs.buf; }
        bool operator!=(const self_type& rhs) const
        { return buf != rhs.buf; }
        bool operator<(const self_type& rhs)const
        {
            return buf->first< rhs.buf->first;
        }
        bool operator>(const self_type& rhs) const
        {
            return buf->first > rhs.buf->first;
        }
        bool operator<= (const self_type& rhs) const
        {
            return *this < rhs || *this == rhs;
        }
        bool operator>= (const self_type& rhs) const
        {
            return *this > rhs|| *this == rhs;
        }
        self_type operator+=(int i)
        {
            buf += i;
            return *this;
        }
        self_type operator+(int i)
        {
            self_type temp = *this;
            temp += i;
            return temp;
        }
        self_type operator-=(int i)
        {
            buf -= i;
            return *this;
        }
        self_type operator-(int i)
        {
            self_type temp = *this;
            temp -= i;
            return temp;
        };
        
    };
    
    
    MapArray():sz(0), buf(new std::pair<key, T>[sz])
    {
    }
    
    MapArray (std::initializer_list< std::pair<key, T> > s)
    :sz(s.size()),buf(new std::pair<key, T>[sz])
    {
        uninitialized_copy(s.begin(), s.end(), buf);
    }

    int size()const
    {
        return sz;
    }
    
    iterator begin()
    {
        return iterator(buf);
    }
    iterator end()
    {
        return iterator(buf)+ sz;
    }
    const_iterator begin() const
    {
        return const_iterator(buf);
    }
    const_iterator end() const
    {
        return const_iterator(buf) + sz;
    }
    
    T& insert ( std::pair<key, T> ele)
    {
        
        std::pair<key,T> *temp = new std::pair<key, T>[++sz];
        int stop = sz-1;
        for (int i = 0; i < stop; i++)
        {
            if (ele.first < buf[i].first)
            {
                
                stop = i;
            }
            else
            {
                temp[i].first = buf[i].first;
                temp[i].second = buf[i].second;
            }
        }
        temp[stop].first = ele.first;
        temp[stop].second = ele.second;
        
        for (int i = stop+1; i < sz; i++)
        {
            temp[i].first = buf[i-1].first;
            temp[i].second = buf[i-1].second;
            
        }
        delete[]buf;
        buf = temp;
        return buf[stop].second;
        
    }
    
    T& operator[](const key& k)
    {
        for (int i = 0; i<sz; i++)
        {
            if(buf[i].first == k)
            {
                return buf[i].second;
            }
        }
        return insert(std::make_pair(k, T()));
    }
    int size()
    {
        return sz;
        
    }
    ~MapArray()
    {
        delete[] buf;
    }
};
#endif
