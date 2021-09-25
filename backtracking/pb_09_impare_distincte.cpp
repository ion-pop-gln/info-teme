#include <iostream>

using namespace std;

int x[100] {};
int n = 0;
int k = 0;

void init()
{
    x[k] = -1;
}

bool succesor()
{
    bool are_succesor = x[k] < 9;

    if (are_succesor)
        x[k] += 2;

    return are_succesor;
}

bool valid()
{
    for (int i = 1; i < k; i++)
        if (x[i] == x[k])
            return false;

    return true;
}

bool solutie()
{
    return k == n;
}

void tipar()
{
    for (int i = 1; i <= n; i++)
        cout << x[i];

    cout << endl;
}

void back()
{
    bool are_succesor = false;
    k = 1;
    
    init();

    while (k > 0) {
        do {
            are_succesor = succesor();
        } while (are_succesor && !valid());

        if (are_succesor) {
            if (solutie())
                tipar();
            else {
                k++;
                init();
            }
        } else
            k--;
    }
}

int main()
{
    cout << "Introdu n: ";
    cin >> n;
    back();
}
