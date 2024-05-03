#include <iostream>
#include <cmath>
using namespace std;

int countdigits(long long number);
void seperate(long long number, int SepNum[]);
long long exp_by_squaring(long long base, int exp);

int main() {
    long long number;
    long long dig;
    long long sum = 0;
    int SepNum[40];
    cout<<"Enter a number : ";
    cin>>number;
    dig = countdigits(number);
    seperate(number, SepNum);
    for(int i=0; i<dig; i++) {
        sum += exp_by_squaring(SepNum[i], dig);
    }
    if(sum == number) {
        cout<<"Number is armstrong"<<endl;
    }
    else {
        cout<<"Number is not armstrong"<<endl;
    }
    cout<<sum<<endl;
}

int countdigits(long long number) {
    int count = 0;
    while(number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

void seperate(long long number, int SepNum[]) {
    int i=0;
    while(number != 0) {
        SepNum[i] = number % 10;
        number /= 10;
        i++;
    }
}

long long exp_by_squaring(long long base, int exp) {
    if (exp < 0) {
        throw std::invalid_argument("Exponent should be non-negative.");
    }
    if (exp == 0) {
        return 1; // Base case
    }
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exponent is odd, multiply by the base
            result *= base;
        }
        base *= base; // Square the base
        exp /= 2; // Halve the exponent
    }
    return result;
}
