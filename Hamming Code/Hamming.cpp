#include <iostream>
using namespace std;
int main()
{
    int d[4];
    cout << "Enter the four bit data:- ";
    for (int &i : d)
        cin >> i;

    int data[8];

    // Giving the vcalues of data bits in data[]
    data[7] = d[0], data[6] = d[1], data[5] = d[2], data[3] = d[3];

    // Giving the values of parity bits in data[]
    data[1] = data[3] ^ data[5] ^ data[7];
    data[2] = data[3] ^ data[6] ^ data[7];
    data[4] = data[5] ^ data[6] ^ data[7];

    // Print the 7-bit Encoded data after adding parity bit
    cout << "\n\nData After Encoding :- ";
    for (int i = 1; i <= 7; i++)
        cout << data[i] << " ";
    cout << endl;

    // Input Received Data to the receiver to check for error detection
    int R_data[8];
    cout << "Enter the Received 7-bit data :- ";
    for (int i = 7; i >= 1; i--)
        cin >> R_data[i];

    // Check for which At which position data bit is inverted
    int c1, c2, c3;
    c1 = R_data[1] ^ R_data[3] ^ R_data[5] ^ R_data[7];
    c2 = R_data[2] ^ R_data[3] ^ R_data[6] ^ R_data[7];
    c3 = R_data[4] ^ R_data[5] ^ R_data[6] ^ R_data[7];
    int pos = (c3 * 4) + (c2 * 2) + (c1 * 1);

    // Print Error if data has changed or print no error on the basis of pos
    if (pos == 0)
    {
        cout << "\nThere is no error in data transmission " << endl;
    }
    else
    {
        cout << "Error occured at postion " << pos << endl;
        cout << "Received data   :- ";
        for (int i = 7; i >= 1; i--)
            cout << R_data[i];
        cout << endl;

        R_data[pos] = R_data[pos] == 1 ? 0 : 1;
        cout << "Corrected  data :- ";
        for (int i = 7; i >= 1; i--)
            cout << R_data[i];
        cout << endl;
    }
}
