/*
File: LinkedList.cpp
Project: CMSC 202 Project 3, Fall 2016
Author: Ujjwal Rehani
Date: 10/31/2016
Email: urehani1@umbc.edu

This file contains LinkedList program for Project 3.
This program creates a linked list in order to decode
messages.
*/
#include "LinkedList.h"

//Default constructor
LinkedList::LinkedList()
{
    m_head = NULL;
    m_tail = NULL;
}

LinkedList::~LinkedList()
{
  //Destructor deallocates memory so no memory leaks occur 
    Node* p;
    while (m_head != NULL) {
       p = m_head;
       m_head = m_head->m_next;
       delete p;
    }
    m_tail = NULL;
}

//Creates a new node in the list that contains an int and string
//The node also has a pointer that points to the next node
Node* LinkedList::CreateNode(int newInt, string newPayload)
{
    Node* p = new Node();
    p->m_int = newInt;
    p->m_payload = newPayload;
    p->m_next = NULL;
    return p;
}

//Adds a new node to the end of the list
void LinkedList::InsertEnd(int newInt, string newPayload)
{
    Node* p = new Node();
    p->m_int = newInt;
    p->m_payload = newPayload;
    p->m_next = NULL;
    if (m_tail == NULL)
        m_head = m_tail = p;
    else {
        m_tail->m_next = p;
        m_tail = p;
    }
}

void LinkedList::Display()
{
    Node* p = m_head;
    //Displays the raw or encrypted linked list
    cout << "Payload of list are:" << endl;
    while (p != NULL) {
       cout << p->m_payload << "->";
       p = p->m_next;
    }
    cout << "END" << endl;
}

//Sorts the list using four pointers that keep track of the nodes
void LinkedList::Sort()
{
    Node *phead, *pcur, *pprev, *q;
    
    if (m_head == NULL) return;
    phead = m_head->m_next;
    m_head->m_next = NULL;
    m_tail = m_head;
    while (phead != NULL) {
       q = phead;
       phead = phead->m_next;
       q->m_next = NULL;
       pcur = m_head;
       while (pcur != NULL) {
          if (q->m_int < pcur->m_int) {
             q->m_next = pcur;
             if (pcur == m_head)
                m_head = q;
             else
                pprev->m_next = q;
             break;
          } else {
             pprev = pcur;
             pcur = pcur->m_next;
          }
       }
       if (pcur == NULL) {
          pprev->m_next = q;
          m_tail = q;
       }
    }
}

//If the list has no ints that are perfect cubes/square, an empty list is
//returned
bool LinkedList::IsEmpty()
{
    return m_head == NULL;
}

LinkedList LinkedList::Decrypt()
{
    LinkedList list2;
    Node* p = m_head;
    int n;
    //Determines if the num is a perfect cube or square and adds into list
    //if true
    while (p != NULL) {
       n = p->m_int;
       if (IsPerfectSquare(n)) {
         n = static_cast<int>(sqrt(n));
         list2.InsertEnd(n, p->m_payload);
       } else if (IsPerfectCube(n)) {
         n = static_cast<int>(cbrt(n));
         list2.InsertEnd(n, p->m_payload);
       }
       p = p->m_next;
    }
    return list2;
}

bool LinkedList::IsPerfectSquare(int n)
{
  //Determines if number is perfect square
    int sr = static_cast<int>(sqrt(n));
    return (sr * sr == n);
}

bool LinkedList::IsPerfectCube(int n)
{
  //determines if number is a perfect cube
    int cr = static_cast<int>(cbrt(n));
    return (cr * cr * cr == n);
}

void LinkedList::Clear()
{
  //Clears list by deleting the nodes until m_head equals null
    Node* p;
    while (m_head != NULL) {
       p = m_head;
       m_head = m_head->m_next;
       delete p;
    }
    m_tail = NULL;
}
