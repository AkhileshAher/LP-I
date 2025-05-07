#include <iostream>
#include <iomanip> // For output formatting
using namespace std;

int main()
{
    int incomingStream[] = {1, 3, 0, 3, 5, 6, 3};
    int pageFaults = 0, frames = 3, m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    int temp[frames];
    for (m = 0; m < frames; m++)
        temp[m] = -1; // Initialize frames to -1

    cout << "\n--- FIFO Page Replacement ---";
    cout << "\nIncoming\tFrame 1\t\tFrame 2\t\tFrame 3";

    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
                break;
            }
        }
        pageFaults++;
        if (pageFaults <= frames && s == 0)
            temp[pageFaults - 1] = incomingStream[m];
        else if (s == 0)
            temp[(pageFaults - 1) % frames] = incomingStream[m];

        cout << "\n" << setw(7) << incomingStream[m] << "\t";
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                cout << setw(8) << temp[n] << "\t";
            else
                cout << setw(8) << "-" << "\t";
        }
    }
    cout << "\nTotal Page Faults: " << pageFaults << endl;
    return 0;
}
