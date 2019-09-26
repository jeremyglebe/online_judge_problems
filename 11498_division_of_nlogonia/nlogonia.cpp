#include <iostream>
using namespace std;

int main()
{
    int k, dx, dy, rx, ry;
    cin >> k;
    while (k != 0)
    {
        // read in the division point coords
        cin >> dx >> dy;
        // loop through every residence in the list
        for (int i = 0; i < k; i++)
        {
            // read in the residence coordinates
            cin >> rx >> ry;
            // compare the coordinates to the division point and print
            if (rx == dx || ry == dy)
            {
                cout << "divisa\n";
            }
            else if (rx > dx)
            {
                if (ry > dy)
                {
                    cout << "NE\n";
                }
                else
                {
                    cout << "SE\n";
                }
            }
            else
            {
                if (ry > dy)
                {
                    cout << "NO\n";
                }
                else
                {
                    cout << "SO\n";
                }
            }
        }
        // read in k for the next iteration (or to end the process)
        cin >> k;
    }
}