// Added header guards
#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

// Everything on this page added by Camden K. on 9/10/2024
// Also you never included anything, also you are doing using namespace std, dont do this
// it is horrible practice
// also moved declarations to a source file

// Updated by Chase on 10/14/2024

#include "types.hpp"
#include "transaction.hpp"
#include <string>
#include <vector>

// Also added namespace
namespace Bank
{
    // Forward declare Bank so we can access it here
    class Bank;

    enum class AccountType
    {
        CHECKING,
        SAVING
    };

    class BankAccount
    {
    public:
        f64 GetBalance() const { return m_balance; }
        i64  GetAccountId() const { return m_account_id; }
		const std::string& GetHolderName() const { return m_holder_name; }
		AccountType GetAccountType() const { return m_account_type; }
    private:
        // Private constructors so only Bank can access them
        BankAccount() : m_account_id(0), m_balance(0) {}
        BankAccount(const std::string& holder_name, i64 account_id, AccountType account_type, f64 balance = 0) : m_holder_name(holder_name), m_account_id(account_id), m_account_type(account_type), m_balance(balance) {}
      
        // Private methods for Bank to use
        void SetBalance(f64 balance) { m_balance = balance; }
		void SetAccountId(i64 account_id) { m_account_id = account_id; }
		void SetHolderName(const std::string& holder_name) { m_holder_name = holder_name; }
		void SetAccountType(AccountType account_type) { m_account_type = account_type; }

		void AddTransaction(Transaction transaction) { m_transactions.push_back(transaction); }
		std::vector<Transaction>& GetTransactions() { return m_transactions; }
		void DisplayTransactions() const { for (const auto& transaction : m_transactions) { transaction.Display(); } }

        void Withdraw(f64 amount);
        void Deposit(f64 amount);
    private:
        i64 m_account_id;
        f64 m_balance;
        AccountType m_account_type;
		std::string m_holder_name;
		std::vector<Transaction> m_transactions;
        friend class Bank;
        friend class Transaction;
    };
}

#endif