#include <iostream>
#include <iomanip> // For output formatting
using namespace std;

// Function for FIFO Page Replacement
void FIFO()
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
        s = 0; // Flag to check if page is already in frame
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

        // Print the current status of frames
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
}

// Function for LRU Page Replacement
void LRU()
{
    int total_frames = 3, total_pages = 12, page_faults = 0;
    int frames[total_frames], pages[] = {8, 3, 4, 8, 2, 4, 5, 4, 3, 6, 3, 4};
    int temp[total_frames], position, m, n, k;

    for (m = 0; m < total_frames; m++)
        frames[m] = -1; // Initialize frames to -1

    cout << "\n--- LRU Page Replacement ---";
    cout << "\nIncoming\tFrame 1\t\tFrame 2\t\tFrame 3";

    for (n = 0; n < total_pages; n++)
    {
        bool page_hit = false;

        // Check if page is already in the frame
        for (m = 0; m < total_frames; m++)
        {
            if (frames[m] == pages[n])
            {
                page_hit = true;
                break;
            }
        }

        if (!page_hit)
        {
            // Find the least recently used page
            for (m = 0; m < total_frames; m++)
                temp[m] = 0;

            int l = 0;
            for (k = n - 1; l < total_frames - 1 && k >= 0; k--)
            {
                for (m = 0; m < total_frames; m++)
                {
                    if (frames[m] == pages[k])
                        temp[m] = 1;
                }
                l++;
            }

            for (m = 0; m < total_frames; m++)
            {
                if (temp[m] == 0)
                {
                    position = m;
                    break;
                }
            }

            frames[position] = pages[n];
            page_faults++;
        }

        // Print the current status of frames
        cout << "\n" << setw(7) << pages[n] << "\t";
        for (m = 0; m < total_frames; m++)
        {
            if (frames[m] != -1)
                cout << setw(8) << frames[m] << "\t";
            else
                cout << setw(8) << "-" << "\t";
        }
    }
    cout << "\nTotal Page Faults: " << page_faults << endl;
}

// Function for Optimal Page Replacement
void Optimal()
{
    int num_frames = 3, faults = 0;
    int frames[num_frames], temp[num_frames];
    int inputStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int num_pages = sizeof(inputStream) / sizeof(inputStream[0]);

    for (int i = 0; i < num_frames; i++)
        frames[i] = -1; // Initialize frames to -1

    cout << "\n--- Optimal Page Replacement ---";
    cout << "\nIncoming\tFrame 1\t\tFrame 2\t\tFrame 3";

    for (int i = 0; i < num_pages; i++)
    {
        bool page_hit = false;

        // Check if the page is already in memory
        for (int j = 0; j < num_frames; j++)
        {
            if (frames[j] == inputStream[i])
            {
                page_hit = true;
                break;
            }
        }

        if (!page_hit)
        {
            for (int j = 0; j < num_frames; j++)
                temp[j] = -1;

            for (int j = 0; j < num_frames; j++)
            {
                for (int k = i + 1; k < num_pages; k++)
                {
                    if (frames[j] == inputStream[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            int position = 0, max = -1;
            for (int j = 0; j < num_frames; j++)
            {
                if (temp[j] == -1)
                {
                    position = j;
                    break;
                }
                else if (temp[j] > max)
                {
                    max = temp[j];
                    position = j;
                }
            }

            frames[position] = inputStream[i];
            faults++;
        }

        // Print the current status of frames
        cout << "\n" << setw(7) << inputStream[i] << "\t";
        for (int j = 0; j < num_frames; j++)
        {
            if (frames[j] != -1)
                cout << setw(8) << frames[j] << "\t";
            else
                cout << setw(8) << "-" << "\t";
        }
    }
    cout << "\nTotal Page Faults: " << faults << endl;
}

// Main Function: Menu-Driven Program
int main()
{
    int choice;
    do
    {
        cout << "\n\n========= MENU =========";
        cout << "\n1. FIFO Page Replacement";
        cout << "\n2. LRU Page Replacement";
        cout << "\n3. Optimal Page Replacement";
        cout << "\n4. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            FIFO();
            break;
        case 2:
            LRU();
            break;
        case 3:
            Optimal();
            break;
        case 4:
            cout << "Program Exited Successfully. Thank you!\n";
            break;
        default:
            cout << "Invalid Choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
