#include "bank_account.hpp"
#include <iostream>
#include <cassert>

namespace Bank
{
    void BankAccount::Withdraw(f64 amount)
    {
        // Changed this to be in a single if statement
        if (amount > m_balance || amount < 0)
            // Dont use exceptions, use asserts
            assert(false && "Insufficient funds");

        m_balance -= amount;
    }

    void BankAccount::Deposit(f64 amount)
    {
        if (amount <= 0)
            assert(false && "Invalid amount");

        m_balance += amount;
    }
}
