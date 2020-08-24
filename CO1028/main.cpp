#include <iostream>

class cashRegister
{
    int cashOnHand;

public:
    cashRegister() { this->cashOnHand = 500; }
    cashRegister(int n) { this->cashOnHand = n; }
    int getCurrentBalance() const { return this->cashOnHand; }
    void acceptAmount(int n) { this->cashOnHand += n; }
};

class dispRegister
{
    int noOfItems;
    int cost;

public:
    dispRegister()
    {
        this->noOfItems = 50;
        this->cost = 50;
    }

    dispRegister(int a, int b)
    {
        this->noOfItems = a;
        this->cost = b;
    }

    int getNoOfItems() const { return this->noOfItems; }
    int getCost() const { return this->cost; }
    void makeSale() { this->noOfItems -= 1; }
};

struct Product
{
    cashRegister cash;
    dispRegister disp;
};

Product water, coke, chips, cookies;

int showSelection(int n)
{
    int deposit = 0;
    switch (n)
    {
    case 0:
        if (water.disp.getNoOfItems() > 0)
        {
            std::cout << "The cost is: " << water.disp.getCost();
            std::cout << "Enter your deposit: ";
            std::cin >> deposit;
            if (deposit >= water.disp.getCost())
                sellProduct(0, deposit);
            return 1;
        }
        else
        {
            std::cout << "We are out of this product. Please choose another one.";
            return 0;
        }
        break;
    }
}

void sellProduct(int n, int deposit)
{
    switch (n)
    {
    case 0:
        water.disp.makeSale();
        water.cash.acceptAmount(deposit);
        std::cout << "Sold.";
        break;
    }
}

int main(int argc, char *argv[])
{
    int sel = 0;
    do
    {
        std::cout << "We are selling water, coke, chips, cookies.";
        std::cout << "Enter the respective index: ";
        std::cin >> sel;
    } while (showSelection(sel) == 0);
}