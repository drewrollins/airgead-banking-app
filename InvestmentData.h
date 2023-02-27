#ifndef INVESTMENTDATA_
#define INVESTMENTDATA_

class InvestmentData {

public:
	InvestmentData(double initialDeposit, double monthDeposit, double interestRate, int numYears);
	void noMonthlyDeposits();
	void withMonthlyDeposits();
	virtual ~InvestmentData();

private:
	double initialDeposit;
	double monthlyDeposit;
	double interestRate;
	int numYears;
};

#endif