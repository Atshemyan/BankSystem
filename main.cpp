#include "Banking.hpp"

int main()
{
    BankSystem bank;
  
    Account acc1(101, 1000.0);
    Account acc2(102, 5000.0);
    Account acc3(103, 20000.0);
    Customer cust1(1, "Gohar Arzumanyan");
    Customer cust2(2, "Hayk Atshemyan");
    cust1.AddAccount(acc1);
    cust1.AddAccount(acc2);
    cust2.AddAccount(acc3);
    
    bank.AddCoustomer(cust1);
    bank.AddCoustomer(cust2);

    bank.deposit(1, 101, 500.0);
    bank.withdraw(1, 102, 1000.0);
    bank.deposit(2, 103, 10000.0);

    std::cout << "Balance for account 101: " << bank.getBalance(1, 101) << std::endl;
    std::cout << "Balance for account 102: " << bank.getBalance(1, 102) << std::endl;
    std::cout << "Balance for account 103: " << bank.getBalance(2, 103) << std::endl;

  
    
    
}