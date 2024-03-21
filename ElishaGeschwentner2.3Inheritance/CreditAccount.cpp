#include "CreditAccount.h"
#include <iostream>
#include <string>

void CreditAccount::Withdraw(float amount)
{
	balance -= amount;
	
	if (balance < creditLimit)
	{ 
		balance -= 5000;

		std::cout << "You used your credit past your limit. A fee has been applied to your balance." << std::endl;
	}
	else if (balance > creditLimit)
	{
		std::cout << std::to_string(amount) << " has been deducted";
		if (balance < 0) { std::cout << ", you have used " << std::to_string(balance * -1) << std::endl; }
		else if (balance > 0) { std::cout << "." << std::endl; }
	}
}
