#pragma once
class BaseAccount
{
public:
	virtual void Withdraw(float amount);
	virtual void Deposit(float amount);
	float GetBalance() const;

protected:
	float balance = 0.0000;
	int withdrawals = 0;
};

