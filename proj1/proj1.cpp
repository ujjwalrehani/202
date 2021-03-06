/*
File: proj1.cpp
Project: CMSC 202 Project 1, Fall 2016
Author: Ujjwal Rehani
Date: 9/23/2016
Email: urehani1@umbc.edu

This file contains the main driver program for Project 1.
This program creates an ATM that can read in information from
a text file in order to create an account or the user can manually
create an account. This program also keeps track of money and allows
the user to deposit and withdraw money.
*/


#include "proj1.h"

int main()
{
	int choice, age = 0;
	string firstname = "", lastname = "";
	float balance = 0.0;
	ifstream fin;
	string checkSave;
	
	//Takes in user's choice and prints appropriate info.
	choice = menuStart();
	switch (choice) {
		case 1: fin.open("proj1.txt");
				if (fin.fail()) {
					cout << "Can't open the file proj1.txt!" << endl << endl;;
				} else {
					fin >> firstname >> lastname >> age >> balance;
					fin.close();
				}
				break;
		case 2: cout << "Please enter the following:" << endl;
				cout << "First Name:" << endl;
				cin >> firstname;
				cout << "Last  Name:" << endl;
				cin >> lastname;
				cout << "Age:" << endl;
				cin >> age;
				cout << "Initial Deposit:" << endl;
				cin >> balance;
				break;
		case 3: break;
	}
	
	//Recieves the user's choice and calls the intended fuction
	if (choice >=1 && choice <=2) {
		cout << fixed << showpoint << setprecision(2);
		while (choice >=1 && choice <= 4) {
			choice = menuMain();
			switch (choice) {
				case 1: displayBalance(balance); break;
				case 2: deposit(balance); break;
				case 3: withdraw(balance); break;
				case 4: displayAccountDetails(firstname, lastname, age, balance); break;
				case 5: 
					//Prompts user to save file
					cout<<"Would you like to save your account information?: "<<endl;
					cout<<"Yes or No"<<endl;
					cin >> checkSave;
					if (checkSave == "Yes")
						cout<<"File saved"<<endl;
					
					else{
						break;
					}		
				
			}
		}
	}
	
	cout << endl << "Thank you for using the UMBC ATM!" << endl << endl;
	return 0;
}

int menuStart()
{
	int choice=0;
	
	//Asks user for selection and bounds checks for correct number
	while (choice < 1 || choice > 3) {
		cout << "Welcome to the UMBC ATM" << endl;
		cout << "Choose from below:" << endl;
		cout << "1. Load a User Profile from File" << endl;
		cout << "2. Enter a new User Profile" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (!cin || choice < 1 || choice > 3) {
		
			cout << "Please enter a valid choice!" << endl << endl;
		}
	}
	return choice;
}

int menuMain()
{
	int choice=0;
	
	//Asks user for selection and bounds checks for correct number
	while (choice < 1 || choice > 5) {
		cout << endl;
		cout << "********Please choose option from the menu*********" << endl;
		cout << "1. Account Balance" << endl;
		cout << "2. Deposit money" << endl;
		cout << "3. Withdraw money" << endl;
		cout << "4. Display your account details" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (!cin || choice < 1 || choice > 5) {
		
			cout << "Please enter a valid choice!" << endl << endl;
		}
	}
	return choice;
}

void displayAccountDetails(string fName, string lName, int age, float accountBalance)
{
	//Prints the information of the account
	cout << fixed << showpoint << setprecision(2);
	cout << "First Name : " << fName << endl;
	cout << "Last Name : " << lName << endl;
	cout << "Age : " << age << endl;
	cout << "Account Balance: $" << accountBalance << endl;
}

void displayBalance(float accountBalance)
{
	//Prints the user's current balance
	cout << fixed << showpoint << setprecision(2);
	cout << "Account Balance: $" << accountBalance << endl;
}

void deposit(float &accountBalance)
{
	float amount;
	
	//Deposits money and bounds checks to make sure amount is acceptable
	cout << "Please enter the amount to be deposited" << endl;
	cin >> amount;
	if (amount <= 0.0)
		cout << "Amount should be greater than 0" << endl;
	else {
		accountBalance += amount;
		cout << "$" << amount << " deposited to your account" << endl;
	}
}

void withdraw(float &accountBalance) 
{
	float amount;
	
	//Withdraws money and bounds checks to make sure amount is acceptable
	cout << "Please enter the amount to be withdrawn" << endl;
	cin >> amount;
	if (amount <= 0.0) {
		cout << "Amount can not be less than 0" << endl;
	} else if (amount > accountBalance) {
		cout << "Withdrawn amount cannot be larger than the balance" << endl;
	} else {
		accountBalance -= amount;
		cout << "$" << amount << " withdrawn from your account" << endl;
	}
	
}
