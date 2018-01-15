/*****************************************
 ** File:    Spaceship.h
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  urehani1
 ** Date:    12/13/16
 ** Section: 14
 ** E-mail: urehani1@gl.umbc.edu 
 **
 ** This is a templated class. Used to build either item ships or personnel ships.
 ** 
 ***********************************************/
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Item.h"
#include "Person.h"

#include <vector>
#include <sstream> //Used to concatenate a string that includes numbers
#include <iomanip> //Used to format weights to make more sense

using namespace std;

template <class T>
class Spaceship
{
 public:
  //Name: Spaceship
  //Default constructor 
  Spaceship();
  
  //Name: Spaceship(string, string, double) Overloaded constructor.
  //Precondition: Requires ship file has been loaded
  //Postcondition: Builds a new templated ship
  Spaceship(string inName, string inType, double inCapacity);

  //Name: GetCargo
  //Precondition: Requires that the ship's cargo has been populated
  //Postcondition: Templated accessor for this ship's cargo
  vector<T> GetCargo() const;

  //Name: GetCargoAt
  //Precondition: Requires that the ship's cargo has been populated
  //Postcondition: Templated accessor for this ship's cargo at a specific location
  const T& GetCargoAt(int index) const;

  //Name: AddCargo
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Adds an item into this ship
  void AddCargo(T inputObject);
  //Name: ToString
  //Precondition: Requires that the ships and cargo have been loaded
  //Postcondition: Used to output information about a specific ship
  string ToString() const;
  //Name: GetCapacity
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Used to access the capacity of a ship
  double GetCapacity() const;
  //Name: GetName
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Used to access the name of a ship
  string GetName() const;

  //Name: operator> (Overloaded) Both ships are templated!
  //Precondition: Requires two ships
  //Postcondition: Returns which ship heavier including cargo
  template <class U>
  bool operator>( Spaceship<U> &otherShip) ;
  //Name: operator< (Overloaded) Both ships are templated!
  //Precondition: Requires two ships
  //Postcondition: Returns which ship lighter including cargo
  template <class U>
  bool operator<( Spaceship<U> &otherShip) ;

private:
  string m_name;
  string m_type;
  double m_capacity;
  vector<T> m_cargo;	
};
//*************************************************************
//You need to implement all of this code - it is templated so we can't split the file

//Default constructor
template <class T> Spaceship<T>::Spaceship()
{
    m_name = "";
    m_type = "";
    m_capacity = 0.0;
}

//Overloaded constructor
template <class T> Spaceship<T>::Spaceship(string inName, string inType, double inCapacity)
{
    m_name = inName;
    m_type = inType;
    m_capacity = inCapacity;
}

//Templated accessor for this ship's cargo
template <class T> vector<T> Spaceship<T>::GetCargo() const
{
    return m_cargo;
}

//Templated accessor for this ship's cargo at a specific location
template <class T> const T& Spaceship<T>::GetCargoAt(int index) const
{
    return m_cargo[index];
}

//Adds an item into this ship
template <class T> void Spaceship<T>::AddCargo(T inputObject)
{
    m_cargo.push_back(inputObject);
}

//Used to output information about a specific ship
template <class T> string Spaceship<T>::ToString() const
{
    double my_weight = 0.0;
    if (m_type == "Item") {
        for (int i=0; i<m_cargo.size(); i++) {
            my_weight += m_cargo[i].GetWeight();
        }
    } else my_weight = m_cargo.size();
    
    ostringstream os;
    os << fixed << showpoint << setprecision(2);
    os << "Ship Type: " << m_type << endl;
    os << "Ship Name: " << m_name << endl;
    os << "Total Weight: " << my_weight << endl;
    os << "Total Capacity: " << m_capacity << endl;
    return os.str();
}

//Used to access the capacity of a ship
template <class T> double Spaceship<T>::GetCapacity() const
{
    double my_weight = 0.0;
    
    if (m_type == "Item") {
        for (int i=0; i<m_cargo.size(); i++) {
            my_weight += m_cargo[i].GetWeight();
        }
        if (my_weight < m_capacity)
            return m_capacity - my_weight;
        else return 0.0;
    } else {
        if (m_cargo.size() < m_capacity)
            return m_capacity - m_cargo.size();
        else return 0.0;
    }
}

//Used to access the name of a ship
template <class T> string Spaceship<T>::GetName() const
{
    return m_name;
}

//Returns which ship heavier including cargo
template <class T> template <class U> bool Spaceship<T>::operator>(Spaceship<U> &otherShip)
{
    double my_weight = 0.0;
    double your_weight = 0.0;
    if (m_type == "Item") {
        for (int i=0; i<m_cargo.size(); i++) {
            my_weight += m_cargo[i].GetWeight();
        }
        for (int i=0; i<otherShip.GetCargo().size(); i++) {
            your_weight += otherShip.GetCargo()[i].GetWeight();
        }
    } else {
        my_weight = m_cargo.size();
        your_weight = otherShip.GetCargo().size();
    }
    return my_weight > your_weight;
}

//Returns which ship lighter including cargo
template <class T> template <class U> bool Spaceship<T>::operator<(Spaceship<U> &otherShip)
{
    double my_weight = 0.0;
    double your_weight = 0.0;
    if (m_type == "Item") {
        for (int i=0; i<m_cargo.size(); i++) {
            my_weight += m_cargo[i].GetWeight();
        }
        for (int i=0; i<otherShip.GetCargo().size(); i++) {
            your_weight += otherShip.GetCargo()[i].GetWeight();
        }
    } else {
        my_weight = m_cargo.size();
        your_weight = otherShip.GetCargo().size();
    }
    return my_weight < your_weight;
}

#endif
