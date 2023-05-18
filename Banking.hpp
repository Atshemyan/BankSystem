#include <iostream>
#include <vector>

class Account
        {

        public:
            Account(int accountNumber, double balance): accountNumber(accountNumber), m_balance(balance) {}

            double getBalance() const
            {
                return m_balance;
            }

            int getAccountNumber() const
            {
                return accountNumber;
            }
            void Deposit(double HowMuch)
            {
                m_balance += HowMuch;
            }

            void WithDraw(double HowMuch)
            {
                m_balance -= HowMuch;
            }

        private:
            int accountNumber;
            double m_balance;
        };

class Customer
        {
            public:

                Customer(int customerId, std::string name): m_customerId(customerId), name(name) {}
                
                void AddAccount(Account account)
                {
                    m_accounts.push_back(account);
                }

                double getBalance(int accountNumber) const
                {
                    for (const auto& acc : m_accounts) {
                        if (acc.getAccountNumber() == accountNumber)
                        {
                            return acc.getBalance();
                        }
                    }
                    return -1;
                
                }

                int getCustomerid() const
                {
                    return m_customerId;
                }

                void deposit(int accountNumber, double amount)
                {
                    for (auto& acc : m_accounts)
                    {
                        if (acc.getAccountNumber() == accountNumber)
                        {
                            acc.Deposit(amount);
                        }
                    }

                }

                void withdraw(int accountNumber, double amount)
                {
                    for (auto& acc : m_accounts)
                    {
                        if (acc.getAccountNumber() == accountNumber)
                        {
                            acc.WithDraw(amount);
                        }
                    }
                }
   

            private:
                int m_customerId;
                std::string name;
                std::vector<Account> m_accounts;     

        };



class BankSystem
{
    public:
        void AddCoustomer(Customer customer)
        {
            m_customers.push_back(customer);
        }
        
        double getBalance(int customerId, int accountNumber) const
        {
            for (const auto& cust : m_customers)
            {
                if (cust.getCustomerid() == customerId)
                {
                    return cust.getBalance(accountNumber);
                }
            }
            return -1;

        }

        void deposit(int customerId, int accountNumber, double amount)
        {
            for (auto& cust : m_customers)
            {
                if (cust.getCustomerid() == customerId)
                {
                    cust.deposit(accountNumber, amount);
                }
            }
        }
        void withdraw(int customerId, int accountNumber, double amount)
        {
            for (auto& cust : m_customers)
            {
                if (cust.getCustomerid() == customerId)
                {
                    cust.withdraw(accountNumber, amount);
                }
            }
        }

        

    private:
        std::vector<Customer> m_customers;
};



