#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time, wt[n], tat[n];
    bool check = false;
    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival and Burst Time for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    while (complete != n) {
        minm = INT_MAX;
        check = false;

        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            complete++;
            finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
        }
        t++;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << total_wt / n;
    cout << "\nAverage Turn Around Time = " << total_tat / n << endl;

    return 0;
}
