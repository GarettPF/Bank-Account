#ifndef CHECKINGS_H
#define CHECKINGS_H

#include "Account.h"
class Checkings : public Account {
	public:
		Checkings(double b, double i) : Account(b, i) {};

		void withdraw(double amount) {
			if (balance - amount < 0)
				balance -= 15;
			else
				Account::withdraw(amount);
		}

		void monthlyProc() {
			charges += 5 + (0.1 * withdraws);
			Account::monthlyProc();
		}
};

#endif //CHECKINGS_H