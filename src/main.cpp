#include "bank.hpp"
	
i32 main()
{
    Bank::Bank bank("Veridian");

	Bank::BankAccount& chase = bank.CreateAccount("Chase", 1000, Bank::AccountType::CHECKING);
	Bank::BankAccount& jess = bank.CreateAccount("Jess", 1000, Bank::AccountType::SAVING);

	bank.Deposit(chase.GetAccountId(), 500);
	bank.Withdraw(jess.GetAccountId(), 200);

	bank.Transfer(chase.GetAccountId(), jess.GetAccountId(), 100);

	bank.DisplayAllAccounts();
	bank.DisplayAllTransactions();

    return 0;
}
