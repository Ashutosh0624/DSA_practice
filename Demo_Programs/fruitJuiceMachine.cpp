#include <iostream>
#include <string>
using namespace std;

class CashRegister {
public:
    int getCurrentCashBalance() const;
    void acceptAmount(int amountIn);
    CashRegister();
    CashRegister(int cashIn)
        : cashOnHand{ cashIn } {}

private:
    int cashOnHand;
};

int CashRegister::getCurrentCashBalance() const {
    return cashOnHand;
}

void CashRegister::acceptAmount(int amountIn) {
    cashOnHand += amountIn;
}

CashRegister::CashRegister() {
    cashOnHand = 500;
}

class dispenserType {
public:
    int getNoOfItems() const;
    int getCost() const;
    void makeSale();
    dispenserType() {
        numberOfItems = 50;
        cost = 50;
    }
    dispenserType(int setNofItems, int setCost);
private:
    int numberOfItems;
    int cost;
};

int dispenserType::getNoOfItems() const {
    return numberOfItems;
}

int dispenserType::getCost() const {
    return cost;
}

void dispenserType::makeSale() {
    numberOfItems--;
}

dispenserType::dispenserType(int setNofItems, int setCost) {
    if (setNofItems >= 0)
        numberOfItems = setNofItems;
    else
        numberOfItems = 50;

    if (setCost >= 50)
        cost = setCost;
    else
        cost = 50;
}

void showSelection() {
    cout << "**Welcome to the Ash fruit juice stall **" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for apple juice" << endl;
    cout << "2 for orange juice" << endl;
    cout << "3 for mango lassi" << endl;
    cout << "4 for fruit punch" << endl;
    cout << "9 to exit" << endl;
} // end of show selection

void sellProduct(dispenserType& product, CashRegister& pCounter) {
    int amount;
    int amount2;

    if (product.getNoOfItems() > 0) // if dispenser is not empty
    {
        cout << "Please deposit " << product.getCost() << " cents " << endl;
        cin >> amount;

        if (amount < product.getCost()) {
            cout << "Please deposit another " << product.getCost() - amount << " cents " << endl;
            cin >> amount2;
            amount += amount2;
        }

        if (amount >= product.getCost()) {
            pCounter.acceptAmount(product.getCost());
            product.makeSale();
            if (amount > product.getCost()) {
                cout << "Collect your change: " << amount - product.getCost() << " cents." << endl;
            }
            cout << "Collect your item at the bottom and enjoy" << endl;
        }
        else {
            cout << "The amount is not enough. Collect what you have deposited." << endl;
            cout << "************************************************" << endl << endl;
        }

    }
    else {
        cout << "Sorry, this item is sold out. " << endl;
    }
}

int main() {
    CashRegister counter;
    dispenserType appleJuice(100, 50);
    dispenserType orangeJuice(100, 50);
    dispenserType mangoLassi(100, 50);
    dispenserType fruitPunch(100, 50);

    int choice;

    showSelection();

    cin >> choice;

    while (choice != 9) {
        switch (choice) {
        case 1:
            sellProduct(appleJuice, counter);
            break;
        case 2:
            sellProduct(orangeJuice, counter);
            break;
        case 3:
            sellProduct(mangoLassi, counter);
            break;
        case 4:
            sellProduct(fruitPunch, counter);
            break;
        default:
            cout << "Invalid selection." << endl;
        } // end of switch
        showSelection();
        cin >> choice;
    }// end of while
    return 0;

} 