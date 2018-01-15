/*
File: Ben.cpp
Project: CMSC 202 Project 4, Fall 2016
Author: Ujjwal Rehani
Date: 11/25/2016
Email: urehani1@umbc.edu

This file contains the main driver program for Ben.h.
It contains the implementations of the class functions
for parent class Ben.
*/

#include "Ben.h"

//Constructor initlizes to default values and
//creates a default version of Ben
Ben::Ben(string name, int life) 
{
    m_name = name;
    m_life = life;
    m_nameNormal = "hand-to-hand";
    m_nameSpecial = "kick";
    m_defenseBonus = 0.0;
    m_missPercent = 0.1;
    m_usedSpecial = 0;
    m_maxSpecial = 2;
    m_minDamageNormal = 10;
    m_maxDamageNormal = 20;
    m_damageSpecial = 25;
}

//Overloaded Constructor that creates a specific version of Ben
Ben::Ben(string name, int life, string nameNorm, string nameSpecial, 
       double defenseBonus, double missPercent, int usedSpecial,
       int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec)
{
    m_name = name;
    m_life = life;
    m_nameNormal = nameNorm;
    m_nameSpecial = nameSpecial;
    m_defenseBonus = defenseBonus;
    m_missPercent = missPercent;
    m_usedSpecial = usedSpecial;
    m_maxSpecial = maxSpecial;
    m_minDamageNormal = minDamNorm;
    m_maxDamageNormal = maxDamNorm;
    m_damageSpecial = damSpec;
    
    // vector <Ben> m_forms; //Stores all possible forms
}

//Destructor deallocates Ben from memory
Ben::~Ben()
{
   m_forms.clear();
}

// three virtual methods are defined in Monster.cpp

//Accessors and Mutators
void Ben::SetLife(int life)
{
    m_life = life;
}

string Ben::GetName()
{
    return m_name;
}

int Ben::GetLife()
{
    return m_life;
}
