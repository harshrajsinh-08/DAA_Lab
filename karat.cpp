#include <iostream> 
#include <math.h> 
using namespace std;

int size(long num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}
long kts(long X, long Y)
{
    if (X <= 10 && Y <= 10)
        return X * Y;
    int maxsize = fmax(size(X),size(Y));
    int n =(int)ceil(maxsize / 2.0);
    long p = (long)pow(10, n);
    long a = (long)floor(X / (double)p);
    long b = X % p;
    long c =(long)floor(Y / (double)p);
    long d = Y % p;
    long ac = kts(a, c);
    long bd = kts(b,d);
    long e = kts(a + b, c + d) - ac - bd;
    return (long)(pow(10 * 1L, 2 * n) * ac + pow(10 * 1L, n) * e + bd);
}
int main()
{
    int num1, num2;
    cout << "Welcome to my program for multiplication of two number using KARATSUBA ALGORITHM " << endl;
    cout << endl;
    cout << "Enter number 1" << endl;
    cin >> num1;
    cout << "Enter number 2" << endl;
    cin >> num2;
    long ans = kts(num1, num2);
    cout << "The multiplication of two numbers using karatsuba algorithm is: ";
    cout << ans << endl;
    cout << endl;
    cout << "HARSHRAJSINH ZALA" << endl;
    cout << "22BCE2238" << endl;
    return 0;
}