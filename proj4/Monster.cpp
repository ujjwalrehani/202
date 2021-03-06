/*
File: Monster.cpp
Project: CMSC 202 Project 4, Fall 2016
Author: Ujjwal Rehani
Date: 11/25/2016
Email: urehani1@umbc.edu

This file contains the main driver program for Monster.h.
It contains the implementations of the class functions
for class Monster which managers the villans for this game.
*/

#include "Monster.h"

//Default Constructor sets name and
//life,and attack randomly
Monster::Monster(int level)
{
    if (level == 1) {
        m_life = (rand() % 31) + 20;
        m_attack = (rand() % 5) + 1;
    } else if (level == 1) {
        m_life = (rand() % 31) + 30;
        m_attack = (rand() % 8) + 3;
    } else {
        m_life = (rand() % 31) + 40;
        m_attack = (rand() % 11) + 5;
    }
}

//Destructor clears and previous monsters
Monster::~Monster()
{
	m_monster.clear();
}

//Generates a random monster
string Monster::SummonMonster()
{
    const int NoOfMonster = 29;
    int i = rand() % NoOfMonster;
    m_name =  m_monster[i];
    return m_name;
}

//Loads a monster from the text file
void Monster::LoadMonster()
{
    const int NoOfMonster = 29;
    string fname = "monster.txt", monstername;
    ifstream fin;
    
    //Reads in file and checks for valid file
	fin.open(fname.c_str());
	if (fin.fail()) {
		cout << "Can't open the file " << fname << endl << endl;;
	} else {
        for (int i=0; i<NoOfMonster; i++) {
            //fin >> monstername;
            getline(fin, monstername);
            m_monster.push_back(monstername);
        }
		fin.close();
	}
}

//Displays how much attack the monster did
//and decreases Ben's health
void Monster::Attack(Ben *&target)
{
	cout << GetName() << " did " << m_attack << " to " << target->GetName() << "." << endl;
	int target_life = target->GetLife() - m_attack;
	target->SetLife(target_life);
}

//Mutators and Accessors
void Monster::SetLife(int life){
    m_life = life;
}
     
int Monster::GetLife()
{
    return m_life;
}

string Monster::GetName()
{
    return m_name;
}

//Displays info about Ben's attack
void Ben::Attack(Monster *&target)
{
	cout << GetName() << " attacks using his " << m_nameNormal << " attack." << endl;
	//Calculates the damage done by Ben
	int damage = (rand() % (m_maxDamageNormal - m_minDamageNormal +1)) + m_minDamageNormal;
	int percent = rand() % 100 + 1;
	int missPercent = static_cast<int>(m_missPercent * 100);
	//Decreases health of Monster
	if (percent > missPercent) {
		int target_life = target->GetLife() - damage;
		target->SetLife(target_life);
		cout << GetName() << " did " << damage << " to " << target->GetName() << "." << endl;
	} else {
	  //If Ben misses, the monster retaliates
		cout << GetName() << " has missed the " << m_nameNormal << "  attack! " << target->GetName() << " retaliates!" << endl;
	}
}

void Ben::SpecialAttack(Monster *&target)
{
	if (m_maxSpecial > 0) {
        cout << GetName() << " attacks using his " << m_nameSpecial << " attack." << endl;
	//Subtracts damage done by special attack from monsters health
		int target_life = target->GetLife() - m_damageSpecial;
		if (target_life < 0 )
		    target_life = 0;
		target->SetLife(target_life);
		m_maxSpecial--;
		m_usedSpecial++;
		cout << GetName() << " did " << m_damageSpecial << " to " << target->GetName() << "." << endl;
    } else {
    	cout << GetName() << " is out of special attack! " << target->GetName() << " retaliates!" << endl;
	}
}

void Ben::UltimateAttack(Monster *&target)
{
	cout << GetName() << " has no ultimate attack! " << target->GetName() << " retaliates!" << endl;
}

void Pyronite::Attack(Monster *&target)
{
	cout << GetName() << " attacks using his " << m_nameNormal << " attack." << endl;
	int damage = (rand() % (m_maxDamageNormal - m_minDamageNormal +1)) + m_minDamageNormal;
	int percent = rand() % 100 + 1;
	//Calculates chance of missing attack
	int missPercent = static_cast<int>(m_missPercent * 100);
	if (percent > missPercent) {
	  //Subtracts damage from monsters health
		int target_life = target->GetLife() - damage;
		target->SetLife(target_life);
		cout << GetName() << " did " << damage << " to " << target->GetName() << "." << endl;
	} else {
		cout << GetName() << " has missed the " << m_nameNormal << "  attack! " << target->GetName() << " retaliates!" << endl;
	}
}

void Pyronite::SpecialAttack(Monster *&target)
{
	if (m_maxSpecial > 0) {
		cout << GetName() << " attacks using his " << m_nameSpecial << " attack." << endl;
		//Subtracts damge from monsters health
	    int target_life = target->GetLife() - m_damageSpecial;
		if (target_life < 0 )
		    target_life = 0;
		target->SetLife(target_life);
		m_maxSpecial--;
		m_usedSpecial++;
		cout << GetName() << " did " << m_damageSpecial << " to " << target->GetName() << "." << endl;
    } else {
    	cout << GetName() << " is out of special attack! " << target->GetName() << " retaliates!" << endl;
	}
}

void Crystalsapien::Attack(Monster *&target)
{
	cout << GetName() << " attacks using his " << m_nameNormal << " attack." << endl;
	int damage = (rand() % (m_maxDamageNormal - m_minDamageNormal +1)) + m_minDamageNormal;
	int percent = rand() % 100 + 1;
	//Calculates miss percentage
	int missPercent = static_cast<int>(m_missPercent * 100);
	if (percent > missPercent) {
	  //Subtracts damge from monsters health
		int target_life = target->GetLife() - damage;
		if (target_life < 0 )
		    target_life = 0;
		target->SetLife(target_life);
		cout << GetName() << " did " << damage << " to " << target->GetName() << "." << endl;
	} else {
		cout << GetName() << " has missed the " << m_nameNormal << "  attack! " << target->GetName() << " retaliates!" << endl;
	}
}

void Crystalsapien::SpecialAttack(Monster *&target)
{
	if (m_maxSpecial > 0) {
		cout << GetName() << " attacks using his " << m_nameSpecial << " attack." << endl;
		//Subtracts damage from monsters health
	    int target_life = target->GetLife() - m_damageSpecial;
		if (target_life < 0 )
		    target_life = 0;
		target->SetLife(target_life);
		m_maxSpecial--;
		m_usedSpecial++;
		cout << GetName() << " did " << m_damageSpecial << " to " << target->GetName() << "." << endl;
    } else {
    	cout << GetName() << " has no special attack! " << target->GetName() << " retaliates!" << endl;
	}
}

void Crystalsapien::UltimateAttack(Monster *&target)
{
    cout << "Crystalsapien attacks using **ULTIMATE** ATTACK!!" << endl;
	int damage = m_damageSpecial * 10;
	//Subtracts damge from monsters health
	int target_life = target->GetLife() - damage;
    if (target_life < 0 )
	    target_life = 0;
	target->SetLife(target_life);
	cout << GetName() << " did " << damage << " to " << target->GetName() << "." << endl;
}

