#include "bank_account.hpp"
#include "transaction.hpp"
#include "customer.hpp"
#include <iostream>

i32 main()
{
    Bank::Customer customer(1, "John Doe");
    // maybe checking accounts should start with an id of 1, and savings with 2
    Bank::CheckingAccount checking_account(12345, 1000, customer.GetCustomerName());

    std::cout << "Account ID: " << checking_account.GetAccountId() << std::endl;
    std::cout << "Account Balance: $" << checking_account.GetBalance() << std::endl;
    std::cout << "Account Holder Name: " << checking_account.GetName() << std::endl
              << std::endl;

    // not need to call the view balance method, since the transaction will display the balance
    // checking_account.ViewBalance();
    // std::cout << std::endl;

    // this is not needed, since the transaction object will execute the transaction
    // checking_account.Withdraw(500);

    // transactions are used to deposit or withdraw money from the account
    // when the transaction object is created, the transaction is executed automatically
    Bank::Transaction transaction1(1, checking_account, 500, "Withdraw");
    // display the transaciton details, and the account balance
    transaction1.Display();

    std::cout << std::endl;

    Bank::Transaction transaction2(2, checking_account, 1000, "Deposit");
    transaction2.Display();

    return 0;
}
