/*
File: proj3.cpp
Project: CMSC 202 Project 3, Fall 2016
Author: Ujjwal Rehani
Date: 10/31/2016
Email: urehani1@umbc.edu

This file contains the main driver program for Project 3.
This program reads in a text file and can decode the message
if the user chooses to.
*/

#include "LinkedList.h"
#include "proj3.h"

int main () {
  LinkedList list;
  mainMenu(list);
  return 0;
}

void readFile(LinkedList &list){
    string fname, payload;
    int option = 0, num;
    
    //Asks the user for their option
    if (!list.IsEmpty()) {
       do {
         cout << "Do you want to:" << endl;
         cout << "1. Overwrite the message" << endl;
         cout << "2. Append the message" << endl;
         cout << "3. Cancel" << endl;
         cin >> option;
       } while(option < 1 || option > 3);
       
       if (option == 1)
         list.Clear();
       else if (option == 3) return;
    }
    
    //Asks user for valid text file
    cout << "What is the file name?:" << endl;
    cin >> fname;
    ifstream fin;
    
	fin.open(fname.c_str());
	//if invalid file print out error message
	if (fin.fail()) {
		cout << "Can't open the file " << fname << endl << endl;;
	} else {
	  //reads in file and places and adds into linked list
        while (true) {
            fin >> num;
            if (fin.eof()) break;
            fin >> payload;
            if (fin.eof()) break;
            list.InsertEnd(num, payload);
        }
        cout << "New message loaded!" << endl << endl;
		fin.close();
	}
}

void mainMenu(LinkedList &list){
  int option = 0;
  bool isExit = 0;
  //Asks user for input
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. Load a new encrypted message" << endl;
      cout << "2. Display a raw message" << endl;
      cout << "3. Display an encrypted message" << endl;
      cout << "4. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 4);
    
    //Function is called based on user input
    switch(option){
    case 1:
      readFile(list);
      break;
    case 2:
      displayMessage(list);
      break;
    case 3:
      displayEncrypt(list);
      break;
    case 4:
      exitLinked(list);
      isExit = 1;
    }
  }while(isExit == 0);
}

void displayMessage(LinkedList &list){
  //If the list is empty, message is displayed
     if (list.IsEmpty())
        cout << "You haven't loaded an encrypted message yet!" << endl << endl;
     else {
        list.Display();
        list.Sort();
        list.Display();
     }
}

void exitLinked(LinkedList &list){
  //Uses Clear method to clear list before exiting
     list.Clear();
     cout << "Have a nice day!" << endl << endl; 
}

void displayEncrypt(LinkedList &list){
  //If list is empty, print error message
     if (list.IsEmpty()) {
        cout << "You haven't loaded an encrypted message yet!" << endl << endl;
        return;
     }
     //Calls decrypt method before displaying the final message
     LinkedList list2 = list.Decrypt();
     list2.Sort();
     list2.Display();
     list2.Clear();
}
