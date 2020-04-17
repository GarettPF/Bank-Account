#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
	protected:
		double balance, interest, charges;
		int deposits, withdraws;

	public:
		Account(double b, double i) {
			deposits = withdraws = 0;
			charges = 0.0;
			balance = b;
			interest = i;
		};

		virtual void deposit(double amount) {
			balance += amount;
			deposits++;
		}

		virtual void withdraw(double amount) {
			balance -= amount;
			withdraws++;
		}

		virtual void calcInt() {
			double monthlyIntRate = interest / 12;
			balance += (balance * monthlyIntRate);
		}

		virtual void monthlyProc() {
			balance -= charges;
			calcInt();
			withdraws = deposits = 0;
			charges = 0.0;
		}

		int getBalance() const { return balance; }
};

#endif //ACCOUNT_H