#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num_frames = 3, faults = 0;
    int frames[num_frames], temp[num_frames];
    int inputStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int num_pages = sizeof(inputStream) / sizeof(inputStream[0]);

    for (int i = 0; i < num_frames; i++)
        frames[i] = -1;

    cout << "\n--- Optimal Page Replacement ---";
    cout << "\nIncoming\tFrame 1\t\tFrame 2\t\tFrame 3";

    for (int i = 0; i < num_pages; i++)
    {
        bool page_hit = false;

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
    return 0;
}
