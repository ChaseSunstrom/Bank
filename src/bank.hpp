#ifndef BANK_HPP
#define BANK_HPP

// Created by chase on 10/14/2024

#include <iostream>
#include <unordered_map>

#include "bank_account.hpp"
#include "transaction.hpp"


namespace Bank
{
	class Bank
	{
	public:
		Bank(const std::string& bank_name) : m_bank_name(bank_name) {}
		~Bank() = default;
		BankAccount& CreateAccount(const std::string& account_holder_name, f64 balance, AccountType account_type);
		BankAccount& GetAccount(i64 account_id);
		void Deposit(i64 account_id, f64 amount);
		void Withdraw(i64 account_id, f64 amount);
		void Transfer(i64 from_account_id, i64 to_account_id, f64 amount);
		void ViewBalance(i64 account_id);
		void DisplayAllAccounts();
		void DisplayAllTransactions();
		i64 GetNextAccountId() const;
		i64 GetNextTransactionId() const;
		f64 GetBalance(i64 account_id);
	private:
		// Account id
		std::unordered_map<i64, std::unique_ptr<BankAccount>> m_bank_accounts;
		// Static counter of the next bank account id, starts at 0
		static inline i64 m_account_id = 0;
		static inline i64 m_transaction_id = 0;
		// Veridian, First National Bank, etc.
		std::string m_bank_name;
	};
}

#endif