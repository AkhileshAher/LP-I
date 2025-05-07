#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int total_frames = 3, total_pages = 12, page_faults = 0;
    int frames[total_frames], pages[] = {8, 3, 4, 8, 2, 4, 5, 4, 3, 6, 3, 4};
    int temp[total_frames], position, m, n, k;

    for (m = 0; m < total_frames; m++)
        frames[m] = -1;

    cout << "\n--- LRU Page Replacement ---";
    cout << "\nIncoming\tFrame 1\t\tFrame 2\t\tFrame 3";

    for (n = 0; n < total_pages; n++)
    {
        bool page_hit = false;

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
    return 0;
}
