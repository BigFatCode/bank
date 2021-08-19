#include <vector>
#include <memory>

class Date
{
	public:
		char timestamp[80];

		// constructor
		Date();
};



class PaymentHistory
{
	unsigned int accountNumber;
	long double transferAmount;
	std::string transferContent;
	std::unique_ptr<Date> transferDate;

public:
	// constructor
	PaymentHistory(const unsigned int& accNum, const long double& transAm, const std::string& transContent);

	friend class PaymentAccount;
};



class PaymentAccount
{
	std::unique_ptr<Date> openDate; // ngay mo tai khoan
	unsigned int accountNumber;
	long double balance;
	std::vector<std::unique_ptr<PaymentHistory>> HistoryArray;

public:
	// constructor
	PaymentAccount();

	// destructor
	~PaymentAccount();

	long double getBalance();
	bool transferTo(const long double& amount, const std::string& content);
	void showHistory();

	friend class CreditCardAccount;
	friend class RewardCardAccount;
	friend class CashBackCardAccount;
};



class CreditHistory
{
	std::unique_ptr<Date> transferDate;
	long double transferAmount;
	std::string transferContent;

public:
	// constructor
	CreditHistory(const long double& transAm, const std::string& transContent)
};



class CreditCardAccount
{
protected:
	long double creditLimit = 30000000;
	float interestRate;
	long double minPayment;
	long double latePenalty;
	long double balance; // balance la tong so no
	std::vector<std::unique_ptr<CreditHistory>> HistoryArray;
	
public:
	// constructor
	CreditCardAccount();

	long double getBalance();
	void writeHistory(const long double& amount, const std::string& historyContent);
	void showHistory();
	bool charge(const long double& amount);
	void payment(const long double& amount);
	void payDebt(PaymentAccount& yourPA, const std::string& transContent);
};



class RewardCardAccount : public CreditCardAccount
{
	float rewardRate;
	int currentPoints;

public:   
	// constructor
	RewardCardAccount();

	bool charge(const long double& amount);
	void payment(const long double& amount);
	int getCurrentPoints();
	void payWithPoints(const int& pAmount);
};



class CashBackCardAccount : public CreditCardAccount
{
	float cashbackRate;
	long double currentCashBack;

public:
	// constructor
	CashBackCardAccount();

	long double getCurrentCashBack();
	bool charge(const long double& amount);
	void payment(const long double& amount);
	void redeemCashBack(PaymentAccount& yourPA);
};