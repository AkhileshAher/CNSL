#include <iostream>
#include <string>
#include <iomanip>  // For std::setw
using namespace std;

const int INF = 9999;
const int MAX_NODES = 10;

struct DVR_table
{
    int distance[MAX_NODES];
    int nexthop[MAX_NODES];
} rt[MAX_NODES];

string nodeNames[MAX_NODES];

void printTable(int n, int nodeIndex, const string &header)
{
    cout << "\n" << header << "\n";
    cout << "Destination\tDistance\tNext HOP\n";
    for (int j = 1; j <= n; j++)
    {
        if (rt[nodeIndex].distance[j] == INF)
            cout << nodeNames[j] << "\t\t" << "∞" << "\t\t";
        else
            cout << nodeNames[j] << "\t\t" << rt[nodeIndex].distance[j] << "\t\t";
        
        if (rt[nodeIndex].nexthop[j] == -1)
            cout << "-";
        else
            cout << nodeNames[rt[nodeIndex].nexthop[j]];
        cout << endl;
    }
}

void printDistanceTables(int n, const string &phase)
{
    int choice;
    cout << "\nWhich node's table would you like to see during " << phase << "?\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ". " << nodeNames[i] << endl;
    }
    cout << "Enter your choice (1-" << n << "): ";
    cin >> choice;
    if (choice >= 1 && choice <= n)
    {
        printTable(n, choice, "Table for Router " + nodeNames[choice]);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the Number of Router Nodes  ==> ";
    cin >> n;

    cout << "Enter the names of the nodes:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Name of Router " << i << " ==> ";
        cin >> nodeNames[i];
    }

    cout << "Enter the Distance Matrix (use 9999 for infinity) :- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int distance;
            cin >> distance;
            rt[i].distance[j] = (distance == 9999) ? INF : distance;
            rt[i].nexthop[j] = (i == j) ? -1 : j;
        }
    }

    printDistanceTables(n, "Initialization Table");

    for (int steps = 1; steps < n; steps++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (i == j || j == k || k == i)
                        continue;
                    if (rt[i].distance[j] > rt[i].distance[k] + rt[k].distance[j])
                    {
                        rt[i].distance[j] = rt[i].distance[k] + rt[k].distance[j];
                        rt[i].nexthop[j] = k;
                    }
                }
            }
        }
        printDistanceTables(n, "Update Table");
    }

    printDistanceTables(n, "Final Table");

    cout << "\nFinal Shortest Distance Matrix: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (rt[i].distance[j] == INF)
                cout << setw(4) << "∞" << " ";
            else
                cout << setw(4) << rt[i].distance[j] << " ";
        }
        cout << endl;
    }

    string srcName, destName;
    cout << "\nEnter the source router name: ";
    cin >> srcName;
    cout << "Enter the destination router name: ";
    cin >> destName;

    int src = -1, dest = -1;
    for (int i = 1; i <= n; i++)
    {
        if (nodeNames[i] == srcName)
            src = i;
        if (nodeNames[i] == destName)
            dest = i;
    }

    if (src != -1 && dest != -1)
    {
        cout << "The shortest distance between router " << srcName << " and router " << destName << " is: ";
        if (rt[src].distance[dest] == INF)
            cout << "∞" << endl;
        else
            cout << rt[src].distance[dest] << endl;
    }
    else
    {
        cout << "Invalid source or destination router name!" << endl;
    }

    return 0;
}
