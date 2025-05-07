#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0, remain = n, flag = 0;
    float total_wt = 0, total_tat = 0;

    while (remain != 0) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                flag = 1;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    tat[i] = time - at[i];
                    rt[i] = 0;
                    remain--;
                    total_wt += wt[i];
                    total_tat += tat[i];
                }
            }
        }
        if (!flag) time++;
    }

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

    return 0;
}
