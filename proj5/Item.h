/*****************************************
 ** File:    Item.h
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  urehani1
 ** Date:    12/13/16
 ** Section: 14
 ** E-mail: urehani1@gl.umbc.edu 
 **
 ** This file contains the class defining cargo items. Used in item ships
 **
 ***********************************************/
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <sstream>
#include <iomanip>
#include "Person.h"

using namespace std;

class Item
{
public:
// Constructors for Item
  Item();
  Item(int inId, string inName, float inWeight);

// Accessors for Item
  int GetId() const;
  string GetName() const;
  float GetWeight() const;

  //Name: ToString
  //Precondition: Requires item to be formatted for output
  //Postcondition: Creates single string for output 
  //Allowed to use <sstream> for this (not necessarily)
  string ToString() const;

private:
  int m_id;
  string m_name;
  float m_weight;
};

#endif
