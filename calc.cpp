#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

class calculator
{

    int num1, num2, menuInt;
    char op;
    string trigo;
    double num_1, num_2;

    enum class trigoFunc
    {
        SIN,
        COS,
        TAN,
        UNKNOWN_FUNC
    };

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

        do
        {
            switch (menuInt)
            {
            case 1:
                while (true)
                {
                    normalCalcMenu();
                }
                break;
            case 2:
                while (true)
                {
                    scientificCalcMenu();
                }
                break;
            default:
                cout << "Wrong value, enter again." << endl;
            }
        } while (menuInt == 1 || menuInt == 2);
    }

    void normalCalcMenu()
    {
        cout << "---------------------" << endl;
        cout << "Normal Calculator !" << endl
             << "Enter your operation (+ - * /) : ";
        cin >> num1 >> op >> num2;
        cout<<endl;
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
            break;
        }
        cout << "--------------------" << endl
             << "| Your answer is " << ans << " |" << endl
             << "--------------------" << endl
             << endl;
    }

    void scientificCalcMenu()
    {
        cout << "------------------------" << endl
             << "Scientific Calculator !" << endl
             << "1. Trigonometric Function" << endl
             << "2. Exp and Log Function" << endl
             << "3. Power Function" << endl
             << "Enter your operation number : ";
        cin >> menuInt;
        cout << endl;
        do
        {
            switch (menuInt)
            {
            case 1:
                while (true)
                {
                    scientificTrigoCalc();
                }
                break;
            case 2:
                while (true)
                {
                    scientificExpLogCalc();
                }
                break;
            case 3:
                while (true)
                {
                    scientificPowerCalc();
                }
            default:
                cout << "Wrong value, enter again." << endl;
                break;
            }
        } while (menuInt == 1 || menuInt == 2 || menuInt == 3);
    }

    void scientificExpLogCalc()
    {
    }

    void scientificPowerCalc()
    {
    }

    void scientificTrigoCalc()
    {
        cout << "----------------------" << endl;
        cout << "Trignometric Function" << endl
             << "1. Sin" << endl
             << "2. Cos" << endl
             << "3. Tan" << endl
             << "Write your trigonometric function (eg., sin 30) : ";
        cin >> trigo >> num_1;
        cout << endl;

        num_2 = degreesToRadians(num_1);
        trigoFunc FUNC = stringToFunc(trigo);
        switch (FUNC)
        {
        case trigoFunc::SIN:
            cout << "------------------------" << endl;
            cout << "| Answer of sin " << num_1 << " is " << sin(num_2) << " |" << endl;
            cout << "------------------------" << endl;
            break;
        case trigoFunc::COS:
            cout << "------------------------" << endl;
            cout << "| Answer of cos " << num_1 << " is " << cos(num_2) << " |" << endl;
            cout << "------------------------" << endl;
            break;
        case trigoFunc::TAN:
            cout << "------------------------" << endl;
            cout << "| Answer of tan " << num_1 << " is " << tan(num_2) << " |" << endl;
            cout << "------------------------" << endl;
            break;
        default:
            cout << "Wrong value, enter again!" << endl;
            break;
        }
        cout << endl;
    }

    trigoFunc stringToFunc(const string &trigo)
    {
        static const unordered_map<string, trigoFunc> colorMap = {
            {"sin", trigoFunc::SIN},
            {"cos", trigoFunc::COS},
            {"tan", trigoFunc::TAN}};

        auto it = colorMap.find(trigo);
        if (it != colorMap.end())
        {
            return it->second;
        }
        else
        {
            return trigoFunc::UNKNOWN_FUNC;
        }
    };

    double degreesToRadians(double degrees)
    {
        return degrees * M_PI / 180.0;
    }
};

int main()
{
    calculator calc;
    calc.startMenu();
}