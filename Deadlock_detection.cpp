#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    vector<int> allocation, request;
};

bool deadlockDetection(vector<int> work, vector<process> x)
{
    string sequence = ""; //... Safe state sequence
    int no_of_resource = work.size();
    int no_of_process = x.size();
    vector<bool> finish(no_of_process, false);

    for (int i = 0; i < no_of_process; i++)
    {
        int count = accumulate(x[i].allocation.begin(), x[i].allocation.end(), 0);
        if (!count) finish[i] = true;
    }

    while (true)
    {
        bool found = false;
        for (int i = 0; i < no_of_process; i++)
        {
            if (finish[i]) continue;
            bool ok = true;
            for (int j = 0; j < no_of_resource; j++)
            {
                if (x[i].request[j] > work[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                found = true;
                finish[i] = true;
                for (int j = 0; j < no_of_resource; j++)
                {
                    work[j] += x[i].allocation[j];
                }
                sequence += x[i].id + " ";
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < no_of_process; i++)
    {
        if (!finish[i]) return false;
    }
    cout << sequence << "\n";
    return true;
}

int main()
{
    int no_of_resource; //... Total number of resources
    cin >> no_of_resource;
    vector<int> available(no_of_resource);
    for (int &value: available)
    {
        cin >> value; //... Total number of each available resource instances
    }

    int no_of_process; //... Total number of processes
    cin >> no_of_process;
    vector<process> x(no_of_process); //... Process descriptions
    for (int i = 0; i < no_of_process; i++)
    {
        x[i].allocation.resize(no_of_resource); //... Vector max_need size = no_of_resource
        x[i].request = x[i].allocation;
        cin >> x[i].id;
        for (int j = 0; j < no_of_resource; j++)
        {
            cin >> x[i].allocation[j]; //... Total already allocated resources
        }
        for (int j = 0; j < no_of_resource; j++)
        {
            cin >> x[i].request[j]; //... Total resource requests
        }
    }

    if (deadlockDetection(available, x))
    {
        cout << "No Deadlock. The system is in safe state";
    }
    else cout << "The system is in deadlock state!";
}
