/*****************************************
 ** File:    Person.cpp
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  urehani1
 ** Date:    12/13/16
 ** Section: 14
 ** E-mail: urehani1@gl.umbc.edu 
 **
 ** This class is designed to handle people. Used in personnel ships.
 ** 
 ***********************************************/
// Person.cpp 

#include "Person.h"

//Default constructor
Person::Person()
{
    m_fName = "";
    m_lName = "";
    m_weight = 0.0;
    m_age = 0;
    m_id = 0;
}

//Overloaded constructor
Person::Person(string infName, string inlName, double inWeight, int inAge, int inId)
{
    m_fName = infName;
    m_lName = inlName;
    m_weight = inWeight;
    m_age = inAge;
    m_id = inId;
}

//Accesssors for Person
int Person::GetId() const 
{
    return m_id;
}

string Person::GetFName() const 
{
    return m_fName;
}

string Person::GetLName() const 
{
    return m_lName;
}

int Person::GetAge() const 
{
    return m_age;
}

double Person::GetWeight() const 
{
    return m_weight;
}

//Creates a single string for output
string Person::ToString() const 
{
    ostringstream os;
    os << "First Name: " << m_fName << endl;
    os << "Last Name: " << m_lName << endl;
    os << "Age: " << m_age << endl;
    os << "Weight: " << m_weight << endl;
    return os.str();
}
