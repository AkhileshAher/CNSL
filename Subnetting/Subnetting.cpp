#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string IP;
    cout << "Enter the IP Address ==> ";
    cin >> IP;

    stringstream ss(IP);
    string word;
    int ip_add[4];
    int i = 0;

    while (getline(ss, word, '.') && i < 4)
    {
        try
        {
            int t = stoi(word);
            if (t >= 0 && t <= 255)
                ip_add[i++] = t;
            else
            {
                cout << "Invalid IP Address: Octet out of range (0-255).\nTerminating Program....";
                return 0;
            }
        }
        catch (exception &e)
        {
            cout << "Invalid IP Address: Non-numeric value detected.\nTerminating Program....";
            return 0;
        }
    }

    if (i != 4)
    {
        cout << "Invalid IP Address: Incorrect number of octets.\nTerminating Program....";
        return 0;
    }

    int mask[4] = {0, 0, 0, 0};
    if (ip_add[0] >= 0 && ip_add[0] <= 127)
    {
        mask[0] = 255;
        cout << "CLASS A IP Address" << endl;
        cout << "Subnet Mask: 255.0.0.0" << endl;
    }
    else if (ip_add[0] >= 128 && ip_add[0] <= 191)
    {
        mask[0] = 255;
        mask[1] = 255;
        cout << "CLASS B IP Address" << endl;
        cout << "Subnet Mask: 255.255.0.0" << endl;
    }
    else if (ip_add[0] >= 192 && ip_add[0] <= 223)
    {
        mask[0] = 255;
        mask[1] = 255;
        mask[2] = 255;
        cout << "CLASS C IP Address" << endl;
        cout << "Subnet Mask: 255.255.255.0" << endl;
    }
    else if (ip_add[0] >= 224 && ip_add[0] <= 239)
    {
        cout << "CLASS D IP Address (Multicast)" << endl;
    }
    else if (ip_add[0] >= 240 && ip_add[0] <= 255)
    {
        cout << "CLASS E IP Address (Experimental)" << endl;
    }

    if (ip_add[0] >= 0 && ip_add[0] <= 223)
    {
        int network_add[4], last_add[4];
        for (int i = 0; i < 4; i++)
        {
            network_add[i] = ip_add[i] & mask[i];
            last_add[i] = network_add[i] | (255 - mask[i]); // Calculating broadcast address
        }

        cout << "First IP (Network IP) of subnet is: ";
        for (int i = 0; i < 4; i++)
        {
            cout << network_add[i];
            if (i != 3) cout << ".";
        }
        cout << endl;

        cout << "Last IP (Direct Broadcast IP) of subnet is: ";
        for (int i = 0; i < 4; i++)
        {
            cout << last_add[i];
            if (i != 3) cout << ".";
        }
        cout << endl;
    }

    return 0;
}
