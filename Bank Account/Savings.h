#ifndef SAVINGS_H
#define SAVINGS_H

#include <iostream>

#include "Account.h"
class Savings : public Account {
	private:
		bool status;

	public:
		Savings(double b, double i) : Account(b, i) {
			status = (balance >= 25) ? true : false;
		}

		void withdraw(double amount) {
			double before = balance;
			if (status) Account::withdraw(amount);
			status = (before - amount < 25) ? false : true;
		}

		void deposit(double amount) {
			if (!status)
				if (balance + amount > 25)
					status = true;
			
			if (status)
				Account::deposit(amount);
		}

		void monthlyProc() {
			if (withdraws > 4)
				charges = (withdraws - 4.0);

			Account::monthlyProc();
			if (balance < 25) status = false;
		}

		std::string getStatus() const {
			return status ? "Active" : "Inactive";
		}
};

#endif //SAVINGS_H