#include "SavingsAccount.h"
#include "BaseAccount.h"

void SavingsAccount::Withdraw(float amount)
{
	if (withdrawals <= 3) { BaseAccount::Withdraw(amount); }
}
