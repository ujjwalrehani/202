/*****************************************
 ** File:    Item.cpp
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  urehani1
 ** Date:    12/13/16
 ** Section: 14
 ** E-mail: urehani1@gl.umbc.edu 
 **
 ** This file contains the class defining cargo items. Used in item ships
 **
 ***********************************************/


#include "Item.h"

// Default constructor for Item
Item::Item() 
{
    m_id = 0;
    m_name = "";
    m_weight = 0.0;
}

// Overloaded constructor 
Item::Item(int inId, string inName, float inWeight) 
{
    m_id = inId;
    m_name = inName;
    m_weight = inWeight;
}

// Accessors for Item
int Item::GetId() const 
{
    return m_id;
}

string Item::GetName() const 
{
    return m_name;
}

float Item::GetWeight() const 
{
    return m_weight;
}

//Creates single string for output 
string Item::ToString() const 
{
    ostringstream os;
    os << "Item Name: " << m_name << endl;
    os << "ID: " << m_id << endl;
    os << "Weight: " << m_weight << endl;
    return os.str();
}
