#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main()
{
    int noofframes = 6, N = 4;
    int count = 0;
    srand(time(NULL));
    int i = 1;
    while (i <= noofframes)
    {
        sleep(1);
        int x = 0;
        for (int j = i; j < i + N && j <= noofframes; j++)
        {
            cout << "Sending the Frame " << j << endl;
            count++;
        }
        for (int j = i; j < i + N && j <= noofframes; j++)
        {
            sleep(1);
            int flag = rand() % 2;
            if (!flag)
            {
                cout << "\n Acknowledgment for Window Received whose first packet is " << j;
                x++;
            }
            else
            {
                cout << "\n Data Packet in Cumulative Acknowledgement Not Received whose first packet is " << j;
                cout << "\n Retransmitting the Same Window \n";
                break;
            }
        }
        cout << endl;
        i += x;
    }
    cout << "\n Total number of transmissions : " << count;
    return 0;
}