#include <iostream>
using namespace std;

class calculator
{

    int num1, num2, menuInt;
    char op;

public:
    void startMenu()
    {
        cout << endl;
        cout << "------------------------" << endl;
        cout << "Welcome to Calculator !" << endl
             << endl
             << "Select your operation : " << endl
             << "1. Normal" << endl
             << "2. Scientific" << endl
             << "Enter your Number : ";
        cin >> menuInt;
        cout << endl;

        if (menuInt == 1)
        {
            while (true)
            {
                normalCalcMenu();
            }
        }
        else if (menuInt == 2)
        {
            while (true)
            {
                scientificCalcMenu();
            }
        }
    }

    void normalCalcMenu()
    {
        cout << "---------------------" << endl;
        cout << "Normal Calculator !" << endl
             << "Enter your operation (+ - * /) : ";
        cin >> num1 >> op >> num2;
        normalCalc(num1, op, num2);
    }

    void normalCalc(int num1, char op, int num2)
    {
        long double ans;
        switch (op)
        {
        case '+':
            ans = num1 + num2;
            break;
        case '-':
            ans = num1 - num2;
            break;
        case '*':
            ans = num1 * num2;
            break;
        case '/':
            ans = (float)num1 / (float)num2;
            break;
        default:
            cout << "Wrong value, enter again!" << endl;
        }
        cout << "Your answer is " << ans << endl
             << endl;
    }

    void scientificCalcMenu()
    {
    }

    void scientificCalc()
    {
    }
};

int main()
{
    calculator calc;
    calc.startMenu();
}