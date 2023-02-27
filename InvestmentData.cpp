#include <iomanip>
#include <iostream>
#include "InvestmentData.h"

using namespace std;

//member variables being set here
InvestmentData::InvestmentData(double initialDeposit, double monthDeposit, double interestRate, int numYears) {
	this->initialDeposit = initialDeposit;
	this->monthlyDeposit = monthDeposit;
	this->interestRate = interestRate;
	this->numYears = numYears;
}

//Destructor
InvestmentData::~InvestmentData() {

}

//shows the result of no monthly deposits
void InvestmentData::noMonthlyDeposits() {
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout << "==========================================================================" << endl;
	cout << setw(10) << "Year" << setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	int currentyear = 1;
	double yearendBalance = this->initialDeposit;


	//calculating interest, adding it to year end balance and printing
	while (currentyear <= this->numYears) {
		double interestearned = yearendBalance * this->interestRate / 100;
		yearendBalance += interestearned;

		cout << right << setw(10) << currentyear << fixed << setprecision(2)
			<< setw(20) << "$" << yearendBalance
			<< setw(35) << "$" << interestearned << endl;

		currentyear++;
	}

}

//shows the result of investment with monthly deposits
void InvestmentData::withMonthlyDeposits() {

	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout << "==========================================================================" << endl;
	cout << setw(10) << "Year" << setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	//calculate interest earned
	int currentyear = 1;
	double yearendBalance = this->initialDeposit;
	
	while (currentyear <= this->numYears) {

		int month = 1;
		double interestearned = 0.0;
		double monthendbalance = yearendBalance;
		
		//back dating the earned interest to monthly from yearly
		while (month <= 12) {

			monthendbalance += this->monthlyDeposit;
			double monthlyinterest = monthendbalance * this->interestRate / (100 * 12);
			interestearned += monthlyinterest;
			monthendbalance += monthlyinterest;
			
			month++;
		}

		yearendBalance = monthendbalance;

		//print the end result
		cout << right << setw(10) << currentyear << fixed << setprecision(2)
			<< setw(20) << "$" << yearendBalance
			<< setw(35) << "$" << interestearned << endl;
		
		currentyear++;

	}

}