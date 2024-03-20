#include "BaseAccount.h"
#include <iostream>

void BaseAccount::Withdraw(float amount)
{
	balance -= amount;
	withdrawals++;
}

void BaseAccount::Deposit(float amount)
{
	balance += amount;
}

float BaseAccount::GetBalance() const
{
	return balance;
}


