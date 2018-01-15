/*****************************************
 ** File:    ReadySupply.cpp
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  urehani1
 ** Date:    12/13/16
 ** Section: 14
 ** E-mail: urehani1@gl.umbc.edu 
 **
 ** This class is designed to load files into vectors.
 ** Uses the proj5_cargo.txt to build Items and Persons. Uses proj5_ships.txt to build item ships and person ships
 ***********************************************/
// ReadySupply.cpp

#include "ReadySupply.h"

//Default constructor
ReadySupply::ReadySupply()
{
    m_shipFile = "";
    m_cargoFile = "";
}

//Overloaded constructor
ReadySupply::ReadySupply(string shipFile, string cargoFile)
{
    m_shipFile = shipFile;
    m_cargoFile = cargoFile;
    LoadShips();
    LoadCargo();
}

//Builds two vectors for ships
void ReadySupply::LoadShips()
{
    ifstream fin;
    string sType, sName;
    double capacity;
    int num, nPerson=0, nItem=0;
    
	fin.open(m_shipFile.c_str());
	if (fin.fail()) {
		cout << "Can't open the file " << m_shipFile << endl << endl;;
	} else {
        while (true) {
            fin >> sType;
            if (sType == "Item") {
                fin >> sName >> capacity;
				//Ships 1 holds cargo
                Spaceship<Item> sI(sName, sType, capacity);
                //cout << sType << ", " << sName << ", " << capacity << endl;
                m_itemShips.push_back(sI);
                nItem++;
            } else if (sType == "Person") {
                fin >> sName >> num;
				//Ship2 holds people
                Spaceship<Person> sP(sName, sType, num);
                //cout << sType << ", " << sName << ", " << num << endl;
                m_personShips.push_back(sP);
                nPerson++;
            } else break;
            sType = "";
            if (fin.eof()) break;            
        }
		fin.close();
		cout << "Item Ships Loaded: " << nItem << endl;
        cout << "Person Ships Loaded: " << nPerson << endl;
	}
}

//Builds two vectors for two types of cargo
void ReadySupply::LoadCargo()
{
	ifstream fin;
    string sType, sName, fName, lName;
    int cID, age, nPerson=0, nItem=0;
	float weight;
	
	fin.open(m_cargoFile.c_str());
	if (fin.fail()) {
		cout << "Can't open the file " << m_cargoFile << endl << endl;;
	} else {
        while (true) {
            fin >> sType;
            if (sType == "i") {
                fin >> cID >> sName >> weight;
				//Cargo 1 holds items
                Item item(cID, sName, weight);
                //cout << cID << ", " << sName << ", " << weight << endl;
                m_itemCargo.push_back(item);
                nItem++;
            } else if (sType == "p") {
                fin >> fName >> lName >> weight >> age >> cID;
				//Cargo 2 holds people
                Person person(fName, lName, weight, age, cID);
                //cout << fName << ", " << lName << ", " << weight << ", " << age << ", " << cID << endl;
                m_personCargo.push_back(person);
                nPerson++;
            } else break;
            sType = "";
            if (fin.eof()) break;            
        }
		fin.close();
		cout << "Persons Loaded: " << nPerson << endl;
		cout << "Items Loaded: " << nItem << endl;
	}
}

//Returns a vector of all item ships
vector< Spaceship<Item> > ReadySupply::GetItemShips()
{
    return m_itemShips;
}

//Returns a vector of all person ships
vector< Spaceship<Person> > ReadySupply::GetPersonShips()
{
    return m_personShips;
}

//Returns a vector of all items
vector <Item> ReadySupply::GetItemCargo()
{
    return m_itemCargo;
}

//Returns a vector of all people (person)
vector <Person> ReadySupply::GetPersonCargo()
{
    return m_personCargo;
}



