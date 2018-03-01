//
//  SetList.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/28.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef SETLIST_H
#define SETLIST_H

#include <algorithm>
#include <iterator>
#include <initializer_list>
#include <iostream>

template <typename T>
class SetList
{
private:
    struct ListNode
    {
        T info;
        ListNode * next;
        ListNode(T newInfo, ListNode * newNext = nullptr)
        : info( newInfo ), next( newNext )
        {
            
        }
        static ListNode * ListToNode (std::initializer_list<T> s)
        {
            ListNode* head = nullptr;
            for (T x: s)
            {
                if (head == nullptr)
                {
                    head = new ListNode(x);
                }
                else
                {
                    head = new ListNode(x, head);
                }
            }
            return head;
        }
        static int length(ListNode * L)
        {
            return L == nullptr ? 0 : 1 + length(L->next);
            
        }
        static bool equal(ListNode * L1, ListNode * L2)
        {
            return L1 == nullptr || L2 == nullptr ? L1 == L2
            : L1->info == L2->info && equal( L1->next, L2->next );
        }
        static void deleteList(ListNode * L)
        {
            if ( L != NULL )
            {
                deleteList( L->next );
                delete L;
            }
        }
        
        static ListNode * copy(ListNode * L)
        {
            return L == nullptr ? nullptr: new ListNode( L->info, copy( L->next ) );
        }
        static void print(ListNode * L)
        {
            for (ListNode*temp = L; temp!=nullptr; temp = temp->next )
                std::cout << temp->info << " -> ";
            
        }
        
    };
    ListNode* head;
    
public:
    struct iterator
    {
        typedef std::forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef ListNode value_type;
        typedef ListNode& reference;
        typedef ListNode* pointer;

    private:
        pointer head;
    public:
        iterator(pointer ptr = 0) : head(ptr) { }
        self_type operator++() { head = head->next; return *this; }
        self_type operator++(int postfix) { self_type cpy = *this; head = head->next; return cpy; }
        reference  operator* () { return head->info; }
        pointer operator->() { return &head->info; }
        bool operator==(const self_type& rhs) const { return ListNode::equal(head, rhs.head); }
        bool operator!=(const self_type& rhs) const { return head != rhs.head; }
        
    };
    class const_iterator
    {
        typedef std::forward_iterator_tag iterator_category;
        typedef const_iterator self_type;
        typedef ListNode value_type;
        typedef ListNode& reference;
        typedef ListNode* pointer;

    private:
        pointer head;
    public:
        const_iterator(pointer ptr) : head(ptr) { }
        self_type operator++() { head = head->next; return *this; }
        self_type operator++(int postfix) { self_type cpy = *this; head = head->next; return cpy; }
        pointer operator*() { return head->info; }
        const pointer operator->() { return &head->info; }
        bool operator==(const self_type& rhs) const { return ListNode::equal(head, rhs.head); }
        bool operator!=(const self_type& rhs) const { return ListNode::equal(head, rhs.head); }
    };
    
    SetList(T newInfo = T())
    {
        head = new ListNode(newInfo);
    }
    
    SetList (std::initializer_list<T> s)
    {
        head = ListNode::ListToNode(s);
    }
    
    
    int size ()
    {
        return ListNode::length(head);
    }
    
    void insert(T ele)
    {
        for (ListNode * temp = head;temp!=nullptr; temp=temp->next)
        {
            if (ele == temp->info)
                return;
        }
        head = new ListNode(ele, head);
    }
    
    iterator begin()
    {
        return iterator(head);
        
    }
    iterator end()
    
    {
        return iterator();
    }
    
    iterator find(const T& ele)
    {
        ListNode * temp = head;
        for (int n =0; temp!=nullptr; n++, temp = temp->next)
        {
            if (temp->info == ele)
                return iterator(temp);
        }
        return iterator(temp);
    }
    const_iterator insert (T newInfo) const
    {
        ListNode::insert(head, newInfo);
        return iterator(head);
    }
    
    const_iterator begin() const
    {
        return const_iterator(head);
        
    }
    const_iterator end() const
    
    {
        ListNode * temp = head;
        for ( ; temp != nullptr ; temp = temp->next){}
        return const_iterator(temp);
    }
    
    const_iterator find(const T& ele) const
    {
        ListNode * temp = head;
        for (int n =0; temp!=nullptr; n++, temp = temp->next)
        {
            if (temp->info == ele)
                return const_iterator(temp);
        }
        return const_iterator(temp);
    }
    
    void print()
    {
        ListNode::print(head);
        
    }
    ~SetList()
    {
        ListNode::deleteList(head);
        
    }
    
};
#endif
