#include <iostream>
using namespace std;

int main() {
    int n, bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << avg_wt / n;
    cout << "\nAverage Turnaround Time: " << avg_tat / n << endl;

    return 0;
}
