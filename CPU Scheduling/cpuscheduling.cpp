/*
Write a program to simulate CPU Scheduling Algorithms: FCFS, SJF (Preemptive), Priority (Non-Preemptive) and Round Robin (Preemptive).
*/

#include <iostream>
using namespace std;

void fcfs() 
{
    int no, i;
    int bt[20], wt[20], tat[20], st[20], ft[20];
    float wat = 0.0, att = 0.0;

    cout << "Enter the number of processes: ";
    cin >> no;

    cout << "Enter the burst time for each process: \n";
    for (i = 0; i < no; i++) {
        cout << "Process[" << i + 1 << "]: ";
        cin >> bt[i];
    }

    st[0] = 0;
    ft[0] = bt[0];

    for (i = 1; i < no; i++) {
        st[i] = st[i - 1] + bt[i - 1];
        ft[i] = st[i] + bt[i];
    }

    cout << "\n-------------------------------------------\n";
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for (i = 0; i < no; i++) {
        wt[i] = st[i];
        tat[i] = ft[i];
        wat += wt[i];
        att += tat[i];

        cout << "P[" << i + 1 << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "\n----------------------------------------------\n";
    cout << "\nAverage Waiting Time : " << wat / no;
    cout << "\nAverage Turn Around Time : " << att / no;
    cout << endl;
}

void sjf() {
    int no, pos, temp;
    int bt[20], wt[20], tat[20], st[20], ft[20], p[20];
    float wat = 0.0, att = 0.0;

    cout << "Enter the Number of Processes: ";
    cin >> no;

    cout << "Enter Burst Time for each Process:\n";
    for (int i = 0; i < no; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
        p[i] = i + 1;
    }

    for (int i = 0; i < no; i++) {
        pos = i;
        for (int j = i + 1; j < no; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    st[0] = 0;
    ft[0] = bt[0];

    for (int i = 1; i < no; i++) {
        st[i] = st[i - 1] + bt[i - 1];
        ft[i] = st[i] + bt[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for (int i = 0; i < no; i++) {
        wt[i] = st[i];
        tat[i] = ft[i];
        wat += wt[i];
        att += tat[i];

        cout << "P[" << p[i] << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "Average Waiting Time: " << wat / no;
    cout << "\nAverage Turnaround Time: " << att / no;
}

void rr() {
    int i, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turn_around_time = 0;
    int at[10], bt[10], rt[10];

    cout << "Enter the Total number of Processes: ";
    cin >> n;
    remain = n;

    for (i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process P[" << i + 1 << "]: ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    cout << "\n\nProcess\t| Turn Around Time | Waiting Time\n\n";
    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= time_quantum && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= time_quantum;
            time += time_quantum;
        }

        if (rt[i] == 0 && flag == 1) {
            remain--;
            cout << "P[" << i + 1 << "]\t|\t" << time - at[i] << "\t|\t" << time - at[i] - bt[i] << "\n";
            wait_time += time - at[i] - bt[i];
            turn_around_time += time - at[i];
            flag = 0;
        }

        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    cout << "\nAverage Waiting Time = " << wait_time * 1.0 / n;
    cout << "\nAverage Turn Around Time = " << turn_around_time * 1.0 / n;
    cout << endl;
}

void priority() {
    int n;
    cout << "Enter the Number of Processes: ";
    cin >> n;

    int b[n], p[n], index[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time and Priority Value for process " << i + 1 << ": ";
        cin >> b[i] >> p[i];
        index[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int a = p[i], m = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j] > a) {
                a = p[j];
                m = j;
            }
        }
        swap(p[i], p[m]);
        swap(b[i], b[m]);
        swap(index[i], index[m]);
    }

    int t = 0;
    cout << "Order of Process Execution is: \n";
    for (int i = 0; i < n; i++) {
        cout << "P" << index[i] << " is executed from " << t << " to " << t + b[i] << "\n";
        t += b[i];
    }

    cout << "\nProcessId\tBurstTime\tWait-time\tTurn-Around-Time\n";
    int wait_time = 0;
    for (int i = 0; i < n; i++) {
        cout << "P" << index[i] << "\t\t" << b[i] << "\t\t" << wait_time << "\t\t" << wait_time + b[i] << "\n";
        wait_time += b[i];
    }
}


int main()
{
    int choice;
    do {
        cout << "\n==================MENU===================";
        cout << "\n 1. FCFS \n 2. SJF \n 3. Round Robin \n 4. Priority \n 0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fcfs();
                break;
            case 2:
                sjf();
                break;
            case 3:
                rr();
                break;
            case 4:
                priority();
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
