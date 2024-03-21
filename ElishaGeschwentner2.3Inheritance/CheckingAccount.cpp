#include "CheckingAccount.h"
#include "BaseAccount.h"

void CheckingAccount::Withdraw(float amount)
{
	int fee = 0;
	if (withdrawals > 10) {fee = 5;}
	
	BaseAccount::Withdraw(amount + fee);
}
