#pragma once
#include "BaseAccount.h"

class CreditAccount : public BaseAccount
{
private:
	int creditLimit = -40;

public:
	void Withdraw(float amount);

	CreditAccount(float baseBalance)
	{
		this->balance = baseBalance;
	}
};

