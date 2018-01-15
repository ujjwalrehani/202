/*****************************************
 ** File:    ManageShips.cpp
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  urehani1
 ** Date:    12/13/16
 ** Section: 14
 ** E-mail: urehani1@gl.umbc.edu 
 **
 ** This file manages a majority of functions. This class manages
 ** the various aspects including getting ships,persons, and items.
 **
 ***********************************************/

#include "ManageShips.h"

//Constructor for managing the ships
//Creates two ships and two cargo lists
ManageShips::ManageShips(vector< Spaceship <Item> > itemShip, 
	      vector< Spaceship <Person> > personShip,
	      vector< Item > itemCargo,
	      vector< Person > personCargo)
{
    m_itemShips = itemShip;
    m_personShips = personShip;
    m_items = itemCargo;
    m_person = personCargo;
    
    LoadItemShip();
    LoadPersonShip();
}

//Loads items into each ship 
void ManageShips::LoadItemShip()
{
  //temporary vector
    vector<Item> temp_items;
    
    for (vector< Spaceship <Item> >::iterator shipPtr = m_itemShips.begin(); shipPtr!=m_itemShips.end(); ++shipPtr) {
        //cout << "Ship Name: " << (*shipPtr).GetName() << endl;
        //cout << "Ship Capacity: " << (*shipPtr).GetCapacity() << endl;
      
      //Adds items using the AddCargo method
        for (vector<Item>::iterator it=m_items.begin(); it!=m_items.end(); ++it) {
            if ((*it).GetWeight() <= (*shipPtr).GetCapacity()) {
               (*shipPtr).AddCargo(*it);
            } else {
               temp_items.push_back(*it); 
            }
        }
        m_items = temp_items;
        temp_items.clear();
    }
}

//Loads people into each ship
void ManageShips::LoadPersonShip()
{
    vector<Person> temp_persons;
    
    //User iterators to go through and add persons onto ship
    for (vector< Spaceship <Person> >::iterator shipPtr = m_personShips.begin(); shipPtr!=m_personShips.end(); ++shipPtr) {
        for (vector<Person>::iterator it=m_person.begin(); it!=m_person.end(); ++it) {
            if ((*shipPtr).GetCapacity() >= 1) {
               (*shipPtr).AddCargo(*it);
            } else {
               temp_persons.push_back(*it); 
            }
        }
        m_person = temp_persons;
        temp_persons.clear();
    }
}

//Displays the items not on a ship
void ManageShips::DisplayItemLeft()
{
    if (m_items.size() <= 0)
        cout << "None" << endl;
    else 
        for (int i=1; i<=m_items.size(); i++) {
            cout << "Item " << i << " - Name: " << m_items[i-1].GetName() << endl;
        }
}

//Displays the people not on a ship
void ManageShips::DisplayPersonLeft()
{
    if (m_person.size() <= 0)
        cout << "None" << endl;
    else 
        for (int i=1; i<=m_person.size(); i++) {
            cout << "Person " << i << " - Name: " << m_person[i-1].GetFName() << " " << m_person[i-1].GetLName() << endl;
        }
}

//Writes out all ships and their cargo to a specific output file
void ManageShips::OutputShips()
{
    ofstream fout;
    
    fout.open("output.txt");
    vector <Person> tp;
    cout << "**Personnel Ships**" << endl;
    fout << "**Personnel Ships**" << endl;
    
    //Gets the name of the ships
    for (vector< Spaceship <Person> >::iterator shipPtr = m_personShips.begin(); shipPtr!=m_personShips.end(); ++shipPtr) {
        cout << "** Ship Name: " << (*shipPtr).GetName() << endl;
        fout << "** Ship Name: " << (*shipPtr).GetName() << endl;
        tp = (*shipPtr).GetCargo();
        for (int i=0; i<tp.size(); i++) {
            cout << tp[i].GetFName() << " " << tp[i].GetLName() << endl;
            fout << tp[i].GetFName() << " " << tp[i].GetLName() << endl;
        }
    }
    
    //Finds and prints out cargo on ships
    vector <Item> ti;
    cout << endl;
    fout << endl;
    cout << "**Item Ships**" << endl;
    fout << "**Item Ships**" << endl;
    for (vector< Spaceship <Item> >::iterator shipPtr = m_itemShips.begin(); shipPtr!=m_itemShips.end(); ++shipPtr) {
        cout << "** Ship Name: " << (*shipPtr).GetName() << endl;
        fout << "** Ship Name: " << (*shipPtr).GetName() << endl;
        ti = (*shipPtr).GetCargo();
        for (int i=0; i<ti.size(); i++) {
            cout << ti[i].GetName() << endl;
            fout << ti[i].GetName() << endl;
        }
    }
    fout.close();
    cout << "The above data is also written to the output.txt file." << endl;
}

//Finds the heaviest ship and prints it out
string ManageShips::GetHeaviestShip()
{
    if (m_itemShips.size() <= 0)
        return "No Item Ships!";
    else {
        Spaceship <Item> heaviest = m_itemShips[0];
        int hvIndex = 0;
    
	//Looks for heaviest ship
        for (int i=1; i<m_itemShips.size(); i++) {
            if (m_itemShips[i] > heaviest) {
                 heaviest = m_itemShips[i];
                 hvIndex = i;
            }
        }
        return m_itemShips[hvIndex].ToString();
    }
}

//Finds the lightest ship and prints it out
string ManageShips::GetLightestShip()
{
    if (m_itemShips.size() <= 0)
        return "No Item Ships!";
    else {
        Spaceship <Item> lightest = m_itemShips[0];
        int liIndex = 0;
    
	//Finds lightest ship
        for (int i=1; i<m_itemShips.size(); i++) {
            if (m_itemShips[i] < lightest) {
                 lightest = m_itemShips[i];
                 liIndex = i;
            }
        }
        return m_itemShips[liIndex].ToString();
    }
}

//Outputs the lightest item on a ship
string ManageShips::GetLightestItem()
{
    vector <Item> temp_Items = m_items, t2;
    
    for (vector< Spaceship <Item> >::iterator shipPtr = m_itemShips.begin(); shipPtr!=m_itemShips.end(); ++shipPtr) {
        t2 = (*shipPtr).GetCargo();
        for (int i=0; i<t2.size(); i++) {
            temp_Items.push_back(t2[i]);
        }
    }
    if (temp_Items.size() <= 0)
        return "No Item cargos!";
    else {
        double lightest = temp_Items[0].GetWeight();
        int liIndex = 0;
    
        for (int i=1; i<temp_Items.size(); i++) {
            if (temp_Items[i].GetWeight() < lightest) {
                 lightest = temp_Items[i].GetWeight();
                 liIndex = i;
            }
        }
        return temp_Items[liIndex].ToString();
    }
}

//Outputs the heaviest item
string ManageShips::GetHeaviestItem()
{
    vector <Item> temp_Items = m_items, t2;
    
    for (vector< Spaceship <Item> >::iterator shipPtr = m_itemShips.begin(); shipPtr!=m_itemShips.end(); ++shipPtr) {
        t2 = (*shipPtr).GetCargo();
        for (int i=0; i<t2.size(); i++) {
            temp_Items.push_back(t2[i]);
        }
    }
    if (temp_Items.size() <= 0)
        return "No Item cargos!";
    else {
        double heaviest = temp_Items[0].GetWeight();
        int hvIndex = 0;
    
        for (int i=1; i<temp_Items.size(); i++) {
            if (temp_Items[i].GetWeight() > heaviest) {
                 heaviest = temp_Items[i].GetWeight();
                 hvIndex = i;
            }
        }
        return temp_Items[hvIndex].ToString();
    }
}

//Outputs oldest person
string ManageShips::GetOldestPerson()
{
    vector <Person> temp_Persons = m_person, t2;
    
    for (vector< Spaceship <Person> >::iterator shipPtr = m_personShips.begin(); shipPtr!=m_personShips.end(); ++shipPtr) {
        t2 = (*shipPtr).GetCargo();
        for (int i=0; i<t2.size(); i++) {
            temp_Persons.push_back(t2[i]);
        }
    }
    if (temp_Persons.size() <= 0)
        return "No Person cargos!";
    else {
        int oldest = temp_Persons[0].GetAge();
        int odIndex = 0;
    
        for (int i=1; i<temp_Persons.size(); i++) {
            if (temp_Persons[i].GetAge() > oldest) {
                 oldest = temp_Persons[i].GetAge();
                 odIndex = i;
            }
        }
        return temp_Persons[odIndex].ToString();
    }
}

//Outputs youngest person
string ManageShips::GetYoungestPerson()
{
    vector <Person> temp_Persons = m_person, t2;
    
    for (vector< Spaceship <Person> >::iterator shipPtr = m_personShips.begin(); shipPtr!=m_personShips.end(); ++shipPtr) {
        t2 = (*shipPtr).GetCargo();
        for (int i=0; i<t2.size(); i++) {
            temp_Persons.push_back(t2[i]);
        }
    }
    if (temp_Persons.size() <= 0)
        return "No Person cargos";
    else {
        int youngest = temp_Persons[0].GetAge();
        int ynIndex = 0;
    
        for (int i=1; i<temp_Persons.size(); i++) {
            if (temp_Persons[i].GetAge() < youngest) {
                 youngest = temp_Persons[i].GetAge();
                 ynIndex = i;
            }
        }
        return temp_Persons[ynIndex].ToString();
    }
}
