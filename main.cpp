#include <iostream>

#include "InvestmentData.h"

using namespace std;

int main() {

	while (1) {

		//printing the menu
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;
		cout << "Press Enter to continue . . ." << endl;
		cout << endl;
		cout << "Initial Investment Amount: $";
		
		double investment, monthlydeposit, interestrate;
		int years;

		//gathering user input with a prompt
		cin >> investment;
		cout << "Monthly Deposit: $";
		cin >> monthlydeposit;
		cout << "Annual Interest: %";
		cin >> interestrate;
		cout << "Number of years: ";
		cin >> years;
		cout << "Press Enter to continue . . ." << endl;

		//creating an object given the user input
		InvestmentData mysavings = InvestmentData(investment, monthlydeposit, interestrate, years);

		cout << endl;
		mysavings.noMonthlyDeposits();
		cout << endl;

		//verify user inout at least 1 dollar
		if (monthlydeposit > 0) {
			mysavings.withMonthlyDeposits();
		}

		//ask user for another invesment
		cout << endl << "Do you want to try another? (y/n): ";

		string choice;
		cin >> choice;

		//break if the user has finished
		if (choice != "y") {
			break;
		}
		cout << endl;
	}

	return 0;

}