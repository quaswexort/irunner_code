#include <iostream>
using namespace std;
int main()
{
    long  massa1, cost1, massa2, cost2, wholeMass, i = 0;
    cin >> massa1 >> cost1 >> massa2 >> cost2 >> wholeMass;
    if ((wholeMass < 1) || (massa1 < 1) || (massa2 < 1) || (cost1 < 1) || (cost2 < 1))
    {
        return 0;
    }
    if ((wholeMass > 1000) || (massa1 > 1000) || (massa2 > 1000) || (cost1 > 1000) || (cost2 > 1000))
    {
        return 0;
    }
    long ost = wholeMass / massa1 + (wholeMass % massa1 != 0);
    long finalCost = 2000000;
    while (i <= ost)
    {
        long a = wholeMass - i * massa1;
        long m = (a <= 0 ? 0 : (a / massa2 + (a % massa2 != 0)) * cost2) + i * cost1;
        if (m < finalCost) 
            finalCost = m;
        i++;
    }
    cout << finalCost << endl;
    return 0;
}