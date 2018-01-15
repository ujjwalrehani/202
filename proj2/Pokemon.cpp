/*
File: Pokemon.cpp
Project: CMSC 202 Project 2, Fall 2016
Author: Ujjwal Rehani
Date: 10/16/2016
Email: urehani1@umbc.edu

This file contains the main driver program for the
Pokemon.h file. It contains info about the
Pokemon from the Pokedex.
*/

#include "Pokemon.h"

//Default constructor initializes default values
Pokemon::Pokemon() {
	m_Num = 0;
	m_Name = "";
	m_MinCP = 1;
	m_MaxCP = 3000;
	m_Rarity = 1;
}


Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity) {

	m_Num = num;
	m_Name = name;
	m_MinCP = cpMin;
	m_MaxCP = cpMax;
	m_Rarity = rarity;
}

int Pokemon::GetNum() {
	return m_Num;
}

string Pokemon::GetName() {
	return m_Name;
}

int Pokemon::GetCPMin() {
	return m_MinCP;
}

int Pokemon::GetCPMax() {
	return m_MaxCP;
}

int Pokemon::GetRarity() {
	return m_Rarity;
}
/* 
void Pokemon::SetNum(int newNum) {
 	m_Num = newNum;
}
*/
void Pokemon::SetName(string newName) {
 	m_Name = newName;
}

/* 
void Pokemon::SetCPMin(int newCP) {
 	m_MinCP = newCP;
}
 
void Pokemon::SetCPMax(int newCP) {
 	m_MaxCP = newCP;
}
*/ 
void Pokemon::SetRarity(int newRarity) {
 	m_Rarity = newRarity;
}

void Pokemon::SetCP(int newCP){
  m_MinCP = newCP;
  m_MaxCP = newCP;
}
