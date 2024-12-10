#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector> // Include vector for iterating queue contents
using namespace std;

void printQueue(queue<int> memory) {
    vector<int> temp; // Temporary vector to store queue contents for printing
    while (!memory.empty()) {
        temp.push_back(memory.front());
        memory.pop();
    }
    for (int p : temp) {
        cout << p << " ";
    }
}

void fifoPageReplacement(vector<int>& pages, int n, int capacity) {
    queue<int> memory;
    unordered_set<int> st;

    int hits =0, miss =0;

    cout<<"Page Replacement Algo. FIFO : \n";
    cout<<"---------------------------------------------\n";
    cout<<"Page\tMemory Content\t\tStatus\n";
    cout<<"---------------------------------------------\n";

    for(int i =0; i < n; ++i){
        int page = pages[i];

        if(st.find(page) != st.end()){
            hits++;

            cout << page << "\t";
            printQueue(memory); // Print current memory content
            cout << "\t\tHit\n";
        }else{
            miss++;
            if(memory.size() < capacity){
                memory.push(page);
                st.insert(page);
            }else{
                int lru = memory.front();
                memory.pop();
                st.erase(lru);
                memory.push(page);
                st.insert(page);
            }
            cout << page << "\t";
            printQueue(memory); // Print current memory content
            cout << "\t\tMiss\n";
        }
    }

    // queue<int> memory;                // Queue to store pages in memory
    // unordered_set<int> memSet;        // Set to quickly check if a page is in memory
    // int hits = 0, misses = 0;         // Count hits and misses

    // cout << "Page Replacement Process:\n";
    // cout << "---------------------------------------------\n";
    // cout << "Page\tMemory Content\t\tStatus\n";
    // cout << "---------------------------------------------\n";

    // for (int i = 0; i < n; i++) {
    //     int page = pages[i];

    //     // Check if the page is already in memory
    //     if (memSet.find(page) != memSet.end()) {
    //         hits++;
    //         cout << page << "\t";
    //         printQueue(memory); // Print current memory content
    //         cout << "\t\tHit\n";
    //     } else {
    //         misses++;

    //         // If memory is full, remove the oldest page
    //         if (memory.size() < capacity) {
    //             memory.push(page);
    //             memSet.insert(page);
    //         }else{
    //             int lru = memory.front();
    //             memory.pop();
    //             memSet.erase(lru);
    //             memory.push(page);
    //             memSet.insert(page);
    //         }

    //         cout << page << "\t";
    //         printQueue(memory); // Print current memory content
    //         cout << "\t\tMiss\n";
    //     }
    // }

    cout << "---------------------------------------------\n";
    cout << "Total Hits: " << hits << "\n";
    cout << "Total Misses: " << miss << "\n";
    cout << "Hit Ratio: " << (float)hits / n << "\n";
}

int main(){
    int n;
    cout<<"Enter the number of pages :";
    cin>>n;
    cout<<"Enter the pages :";
    vector<int> pages(n);

    for(int i =0; i < n; ++i){
        cin>>pages[i];
    }

    int capacity;

    cout<<"Enter the capacity :";
    cin>>capacity;

    fifoPageReplacement(pages, n, capacity);

    return 0;
}