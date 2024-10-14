#include "bank.hpp"

namespace Bank
{
	BankAccount& Bank::CreateAccount(const std::string& account_holder_name, f64 balance, AccountType account_type)
	{
		switch (account_type)
		{
		case AccountType::CHECKING:
		case AccountType::SAVING:
		{
				// New here instead of make_unique because the constructor is private
			BankAccount* account = new BankAccount(account_holder_name, GetNextAccountId(), account_type, balance);
			m_bank_accounts.insert({ account->GetAccountId(), std::unique_ptr<BankAccount>(account)});
			return *account;
		}
		default:
			std::cout << "Invalid account type" << std::endl;
			break;
		}
	}

	BankAccount& Bank::GetAccount(i64 account_id)
	{
		return *m_bank_accounts.at(account_id);
	}

	void Bank::Deposit(i64 account_id, f64 amount)
	{
		GetAccount(account_id).Deposit(amount);
		Transaction transaction(GetNextTransactionId(), GetAccount(account_id), amount, TransactionType::DEPOSIT);
		transaction.Display();
	}

	void Bank::Withdraw(i64 account_id, f64 amount)
	{
		GetAccount(account_id).Withdraw(amount);
		Transaction transaction(GetNextTransactionId(), GetAccount(account_id), amount, TransactionType::WITHDRAW);
		transaction.Display();
	}

	void Bank::Transfer(i64 from_account_id, i64 to_account_id, f64 amount)
	{
		GetAccount(from_account_id).Withdraw(amount);
		GetAccount(to_account_id).Deposit(amount);
		Transaction transaction(GetNextTransactionId(), GetAccount(from_account_id), amount, TransactionType::TRANSFER);
		transaction.Display();
	}

	f64 Bank::GetBalance(i64 account_id)
	{
		return GetAccount(account_id).GetBalance();
	}

	void Bank::DisplayAllAccounts()
	{
		for (const auto& account : m_bank_accounts)
		{
			std::cout << "Account ID: " << account.second->GetAccountId() << std::endl;
			std::cout << "Account Holder Name: " << account.second->GetHolderName() << std::endl;
			std::cout << "Account Balance: $" << account.second->GetBalance() << std::endl;
			std::cout << std::endl;
		}
	}

	void Bank::DisplayAllTransactions()
	{
		for (const auto& account : m_bank_accounts)
		{
			account.second->DisplayTransactions();
		}
	}

	i64 Bank::GetNextAccountId() const
	{
		return m_account_id++;
	}

	i64 Bank::GetNextTransactionId() const
	{
		return m_transaction_id++;
	}
}