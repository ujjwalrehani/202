/*
File: MyPokemon.cpp
Project: CMSC 202 Project 2, Fall 2016
Author: Ujjwal Rehani
Date: 10/16/2016
Email: urehani1@umbc.edu

This file contains the main driver program for the
MyPokemon.h file. It contains info about the users
Pokemon.
*/

#include "MyPokemon.h"

//Default construtor sets initializes values
MyPokemon::MyPokemon() {
	m_Num = 0;
	m_Name = "";
	m_CP = 1;
	m_HP = 1;
	m_Rarity = 1;
}


MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity) {
	m_Num = num;
	m_Name = name;
	m_CP = cp;
	m_HP = hp;
	m_Rarity = rarity;
}

int MyPokemon::GetNum() {
	return m_Num;
}

string MyPokemon::GetName() {
	return m_Name;
}

int MyPokemon::GetCP() {
	return m_CP;
}

int MyPokemon::GetHP() {
	return m_HP;
}

int MyPokemon::GetRarity() {
	return m_Rarity;
}
/* 
void MyPokemon::SetNum(int newNum) {
 	m_Num = newNum;
}
*/
void MyPokemon::SetName(string newName) {
 	m_Name = newName;
}
 
void MyPokemon::SetCP(int newCP) {
 	m_CP = newCP;
}
 
void MyPokemon::SetHP(int newHP) {
 	m_HP = newHP;
}
 
void MyPokemon::SetRarity(int newRarity) {
 	m_Rarity = newRarity;
}

void MyPokemon::Train() {
	m_CP = m_CP + 10;
}
