#pragma once

#include "types.hpp"
#include  <string>

// Updated by Chase on 10/14/2024

namespace Bank
{
    class Bank;
	class BankAccount;

    enum class TransactionType
    {
	    DEPOSIT,
        WITHDRAW,
        TRANSFER
    };

	class Transaction
    {
    public:
        void Display() const;
    private:
        Transaction() = default;
        Transaction(i64 transaction_id, BankAccount& account, f64 amount, TransactionType transaction_type); void Execute() const;

    private:
        i64 m_transaction_id;           // Unique transaction ID
        BankAccount& m_account;         // Reference to the account associated with this transaction
        f64 m_amount;                   // Amount to deposit or withdraw
        TransactionType m_transaction_type; // Deposit or Withdraw
        friend class Bank;
    };
}
