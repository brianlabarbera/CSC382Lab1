//Brian LaBarbera
//CSC382 Project 1
//9-11-24

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int FiboNR(int n);
int FiboR(int n);
int MODFiboR(int n, int* F);

int main() {

    int testArr[] = { 1,5,10,15,20,25,30,35,40,45,50,55,60,65 };
    int length = sizeof(testArr) / sizeof(testArr[0]);
    int* fiboArr = new int[100]();
    fiboArr[0] = 0;
    fiboArr[1] = 1;

    cout << left
        << setw(10) << "Number"
        << setw(20) << "FiboR (seconds)"
        << setw(20) << "MODFiboR (seconds)"
        << setw(20) << "FiboNR (seconds)"
        << "Fibo-Value" << endl;

    for (int i = 0; i < length; i++) {

        clock_t start, stop;

        start = clock();
        FiboNR(testArr[i]);
        stop = clock();
        double nrSeconds = ((double)stop - start) / CLOCKS_PER_SEC;

        start = clock();
        FiboR(testArr[i]);
        stop = clock();
        double rSeconds = ((double)stop - start) / CLOCKS_PER_SEC;

        start = clock();
        int fibVal = MODFiboR(testArr[i], fiboArr);
        stop = clock();
        double modSeconds = ((double)stop - start) / CLOCKS_PER_SEC;

        cout << right << setw(2) << testArr[i]
            << left << setw(10) << ""  
            << setw(20) << fixed << setprecision(12) << rSeconds
            << setw(20) << modSeconds
            << setw(20) << nrSeconds
            << fibVal << endl;

    }

    delete[] fiboArr;  
    return 0;
}

int FiboR(int n)
{
    if (n == 0 || n == 1)
        return (n);
    else return (FiboR(n - 1) + FiboR(n - 2));
}

int FiboNR(int n)
{
    int* F = new int[n + 1];

    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    int result = F[n];
    delete[] F;
    return result;
}

int MODFiboR(int n, int* F)
{
    if (n == 0) {
        return 0;
    }

    if (F[n] == 0) {  
        F[n] = MODFiboR(n - 1, F) + MODFiboR(n - 2, F);
    }

    return F[n];
}