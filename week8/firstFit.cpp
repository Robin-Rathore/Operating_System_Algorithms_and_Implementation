#include <iostream>
#include <vector>

using namespace std;

void FirstFit(vector<int>& memory, vector<int>& process, int n, int m) {
    vector<int> allocation(m, -1);

    cout << "\nFirst Fit Allocation Process:\n";
    cout << "----------------------------------------\n";
    cout << "Process\tSize\tBlock Allocated\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (process[i] <= memory[j]) {
                memory[j] -= process[i];
                allocation[i] = j;
                break;
            }
        }

        if (allocation[i] != -1) {
            cout << "P" << i + 1 << "\t" << process[i] << "\tBlock " << allocation[i] + 1 << "\n";
        } else {
            cout << "P" << i + 1 << "\t" << process[i] << "\tNot Allocated\n";
        }
    }

    cout << "----------------------------------------\n";
}

int main() {
    int n, m;

    cout << "Enter the number of memory blocks: ";
    cin >> n;
    cout << "Enter the number of processes: ";
    cin >> m;

    vector<int> memory(n);
    vector<int> process(m);

    cout << "Enter the sizes of memory blocks:\n";
    for (int i = 0; i < n; ++i) {
        // cout << "Block " << i + 1 << ": ";
        cin >> memory[i];
    }

    cout << "Enter the sizes of processes:\n";
    for (int i = 0; i < m; ++i) {
        // cout << "Process " << i + 1 << ": ";
        cin >> process[i];
    }

    FirstFit(memory, process, n, m);

    return 0;
}
