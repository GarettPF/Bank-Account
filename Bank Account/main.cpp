/**********************************************************
* Programmer: Garett Pascual-Folster					  *
* Class: CptS 122, Spring, 2020; Lab Section 4			  *
* Programming Assignment: PA7							  *
* Date: April 16, 2020			       					  *
* Description: Generic classes for bank accounts		  *
**********************************************************/

#define CLS system("cls");
#define PAUSE system("pause");

#include "Checkings.h"
#include "Savings.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	bool userInput = false;

	double data[3][2] = { {0.0} },
		amount = 0.0;

	cout << "Do you want to input data yourself (y/n): ";
	userInput = (toupper(getchar()) == 'Y') ? true : false;
	
	for (int x = 0; x < 3; x++) {
		cout << "\nFor account " << x + 1 << endl;
		cout << "Balance = ";
		if (userInput)
			cin >> data[x][0];
		else {
			data[x][0] = (double)(rand() % 1000) / (rand() % 4 + 1);
			cout << fixed << setprecision(2) << data[x][0] << endl;
		}

		cout << "Interest = ";
		if (userInput)
			cin >> data[x][1];
		else {
			data[x][1] = (double)(rand() % 100) / (rand() % 5 + 5);
			cout << data[x][1] << endl;
		}
	}
	PAUSE;



	// test case 1 (Account)
	Account accounts[3] = {
		Account(data[0][0], data[0][1]),
		Account(data[1][0], data[1][1]),
		Account(data[2][0], data[2][1])
	};

	CLS; // deposit
	for (int i = 0; i < 3; i++)
		cout << "Account " << i+1 << endl
			 << "Balance: " << accounts[i].getBalance() << endl << endl;
	cout << "Deposit amount for all: ";
	cin >> amount;
	cout << endl << "After deposit" << endl;

	for (int i = 0; i < 3; i++) {
		accounts[i].deposit(amount);
		cout << "Account " << i+1 << endl
			<< "Balance: " << accounts[i].getBalance() << endl << endl;
	}
	PAUSE;
	
	CLS; // withdraw
	for (int i = 0; i < 3; i++)
		cout << "Account " << i+1 << endl
		<< "Balance: " << accounts[i].getBalance() << endl << endl;
	cout << "Withdraw amount for all: ";
	cin >> amount;
	cout << endl << "After withdraw" << endl;

	for (int i = 0; i < 3; i++) {
		accounts[i].withdraw(amount);
		cout << "Account " << i+1 << endl
			<< "Balance: " << accounts[i].getBalance() << endl << endl;
	}
	PAUSE;

	CLS; // CalcInt
	for (int i = 0; i < 3; i++) {
		cout << "Account " << i+1 << endl;
		cout << "Balance: " << accounts[i].getBalance() << endl;
		cout << "Interest: " << data[i][1] << endl << endl;
	}
	cout << endl << "After monthlyProc" << endl;
	for (int i = 0; i < 3; i++) {
		accounts[i].monthlyProc();
		cout << "Account " << i+1 << endl
			<< "Balance: " << accounts[i].getBalance() << endl << endl;
	}
	PAUSE;






	// test case 2 (Savings)
	Savings savings[3] = {
		Savings(data[0][0], data[0][1]),
		Savings(data[1][0], data[1][1]),
		Savings(data[2][0], data[2][1])
	};

	CLS;
	for (int i = 0; i < 3; i++) {
		cout << "Savings " << i+1 << endl;
		cout << "Balance: " << savings[i].getBalance() << endl;
		cout << "Status: " << savings[i].getStatus() << endl << endl;
	}
	cout << "Deposit amount for all: ";
	cin >> amount;
	cout << endl << "After deposit" << endl;

	for (int i = 0; i < 3; i++) {
		savings[i].deposit(amount);
		cout << "Savings " << i+1 << endl;
		cout << "Balance: " << savings[i].getBalance() << endl;
		cout << "Status: " << savings[i].getStatus() << endl << endl;
	}
	PAUSE;

	CLS; // withdraw
	for (int i = 0; i < 3; i++) {
		cout << "Savings " << i+1 << endl;
		cout << "Balance: " << savings[i].getBalance() << endl;
		cout << "Status: " << savings[i].getStatus() << endl << endl;
	}
	cout << "Withdraw amount for all (for 6 withdrawal times): ";
	cin >> amount;
	cout << endl << "After 6 withdraw" << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) savings[i].withdraw(amount);
		cout << "Savings " << i+1 << endl;
		cout << "Balance: " << savings[i].getBalance() << endl;
		cout << "Status: " << savings[i].getStatus() << endl << endl;
	}
	PAUSE;

	CLS; // monthlyProc
	for (int i = 0; i < 3; i++) {
		cout << "Savings " << i+1 << endl;
		cout << "Balance: " << savings[i].getBalance() << endl;
		cout << "Status: " << savings[i].getStatus() << endl << endl;
	}
	cout << "After monthlyProc" << endl << endl;

	for (int i = 0; i < 3; i++) {
		savings[i].monthlyProc();
		cout << "Savings " << i+1 << endl;
		cout << "Balance: " << savings[i].getBalance() << endl;
		cout << "Status: " << savings[i].getStatus() << endl << endl;
	}
	PAUSE;







	// test case 3 (checkings)
	Checkings checkings[3] = {
		Checkings(data[0][0], data[0][1]),
		Checkings(data[1][0], data[1][1]),
		Checkings(data[2][0], data[2][1])
	};

	CLS; // withdraw
	for (int i = 0; i < 3; i++)
		cout << "Checkings " << i+1 << endl
		<< "Balance: " << checkings[i].getBalance() << endl << endl;
	cout << "Withdraw amount for all: ";
	cin >> amount;
	cout << endl << "After withdraw" << endl;

	for (int i = 0; i < 3; i++) {
		checkings[i].withdraw(amount);
		cout << "Checkings " << i+1 << endl
			<< "Balance: " << checkings[i].getBalance() << endl << endl;
	}
	PAUSE;
	CLS; // withdraw 2
	for (int i = 0; i < 3; i++)
		cout << "Checkings " << i+1 << endl
		<< "Balance: " << checkings[i].getBalance() << endl << endl;
	cout << "Withdraw amount for all: ";
	cin >> amount;
	cout << endl << "After second withdraw" << endl;

	for (int i = 0; i < 3; i++) {
		checkings[i].withdraw(amount);
		cout << "Checkings " << i+1 << endl
			<< "Balance: " << checkings[i].getBalance() << endl << endl;
	}
	PAUSE;

	CLS; // monthlyProc
	for (int i = 0; i < 3; i++)
		cout << "Checkings " << i+1 << endl
		<< "Balance: " << checkings[i].getBalance() << endl << endl;
	cout << "After MonthlyProc" << endl << endl;

	for (int i = 0; i < 3; i++) {
		checkings[i].monthlyProc();
		cout << "Checkings " << i+1 << endl
			<< "Balance: " << checkings[i].getBalance() << endl << endl;
	}
	PAUSE;

	CLS;
	cout << "Finished each test case" << endl;

	return 0;
}