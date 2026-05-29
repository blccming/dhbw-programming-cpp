#include <iostream>
#include <string>


class Account {

    public:

        // The "default constructor" does not have any parameters.
        // It should "guess" reasonable default values, so that all
        // member variables are initialized to a known value.
        Account() : mOwner("unknown"), mBalance(0) {}

        // Constructor for initializing the member variables,
        // when creating a new object
        Account(const std::string &owner, int balance) :
            mOwner(owner), mBalance(balance) {}

        // Getter method for reading the private variables.
        // As there are no setter methods, the owner is read-only and
        // the balance can only be modifed via deduct().
        const std::string &getOwner() const {
            return mOwner;
        }
        int getBalance() const {
            return mBalance;
        }

        void printBalance() const {
            // From methods "inside" the class we can access the
            // private data attributes/variables/members.
            std::cout << "Balance: " << mBalance << std::endl;
        }

        // Method declaration, usually in header file
        bool deduct(int amount);

    private:
        std::string mOwner;
        int mBalance;
};


// Definition of class method, usually in a .cpp source file, with
// signature: Account::deduct(int)
bool Account::deduct(int amount) {
    // This method is part of class Account and thus can access
    // the private members.
    if (amount <= mBalance) {
        mBalance -= amount;
        return true;
    } else {
        return false;
    }
}


int main() {
    // Create variable of type Account on the stack.
    // The constructor is called for initialization.
    Account account1("Frank", 1000);

    // ERROR (private)! account1.mBalance = 1000;

    // We cannot access private member from "outside" the class
    // ERROR!  account1.mBalance += 1000;

    // We can access only public members from "outside"
    account1.printBalance();

    account1.deduct(200);
    account1.printBalance();
    account1.deduct(2000);
    account1.printBalance();

    std::cout << std::endl;

    Account account2;
    std::cout << "Owner: " << account2.getOwner()
        << " Balance: " << account2.getBalance() << std::endl;

    return 0;
}
