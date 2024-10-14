#include "bank_account.hpp"
#include "transaction.hpp"
#include <iostream>
#include <cassert>

namespace Bank
{
	static std::string TransactionTypeToString(TransactionType transaction_type)
	{
		switch (transaction_type) {
		case TransactionType::DEPOSIT:
			return "Deposit";
		case TransactionType::WITHDRAW:
			return "Withdraw";
		case TransactionType::TRANSFER:
			return "Transfer";
		default:
			return "Invalid transaction type";
		}
	}

	Transaction::Transaction(i64 transaction_id, BankAccount& account, f64 amount, TransactionType transaction_type)
		: m_transaction_id(transaction_id), m_account(account), m_amount(amount), m_transaction_type(transaction_type)
	{
		// make sure the amount is greater than 0 and the transaction type is valid
		assert(m_amount > 0 && "Amount must be greater than 0");
		// This was an invalid assert, also we should use an enum class instead of a string
		//assert((m_transaction_type == "Withdraw" || m_transaction_type == "Deposit") && "Invalid transaction type");

		// execute the transaction when the transaction object is created
		Execute();
	}

	// either deposit or withdraw money from the account
	void Transaction::Execute() const
	{
		switch (m_transaction_type) {
		case TransactionType::DEPOSIT:
			m_account.Deposit(m_amount);
			break;
		case TransactionType::WITHDRAW:
			m_account.Withdraw(m_amount);
			break;
		}
	}

	// display the transaction details
	void Transaction::Display() const
	{
		std::cout << "Transaction ID: " << m_transaction_id << std::endl;
		std::cout << "Transaction Type: " << TransactionTypeToString(m_transaction_type) << std::endl;
		std::cout << "Transaction Amount: $" << m_amount << std::endl;

		// display the account balance
		m_account.GetBalance();
	}

}
