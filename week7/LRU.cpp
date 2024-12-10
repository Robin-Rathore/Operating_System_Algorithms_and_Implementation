#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<queue>

using namespace std;

void printTable(list<int> memory){
    for(auto it : memory){
        cout<<it<<" ";
    }
}

void lruImplementation(vector<int>& pages, int n, int capacity){

    list<int> memory;
    map<int, list<int>::iterator> pageTable;
    int hits =0, miss =0;

    for(int i =0; i < n; ++i){
        int page = pages[i];

        if(pageTable.find(page) != pageTable.end()){
            hits++;

            memory.erase(pageTable[page]);
            memory.push_front(page);
            pageTable[page] = memory.begin();

            cout<<"Pages\t";
            printTable(memory);
            cout<<"\t\tHit\n";
        }else{
            miss++;
            if(memory.size() < capacity){
                memory.push_front(page);
                pageTable[page] = memory.begin();
            }else{
                int lru = memory.back();
                memory.pop_back();
                pageTable.erase(lru);
                memory.push_front(page);
                pageTable[page] = memory.begin();
            }

            cout<<"pages\t";
            printTable(memory);
            cout<<"\t\tMiss\n";
        }
    }

    // list<int> memory;
    // map<int, list<int>::iterator> pageTable;
    // int miss =0, hit =0;

    // for(int i =0; i < n; ++i) {
    //     int page = pages[i];

    //     if(pageTable.find(page) != pageTable.end()){
    //         hit++;

    //         memory.erase(pageTable[page]);
    //         memory.push_front(page);
    //         // pageTable[page].clear();
    //         pageTable[page] = memory.begin();

    //         cout<<page<<"\t";
    //         printTable(memory);
    //         cout<<"\t\tHit\n";
    //     }else{
    //         miss++;
    //         if(memory.size() < capacity){
    //             memory.push_front(page);
    //             pageTable[page] = memory.begin();
    //         }else{
    //             int lruPage = memory.back();
    //             memory.pop_back();
    //             pageTable.erase(lruPage);
    //             memory.push_front(page);
    //             pageTable[page] = memory.begin();
    //         }

    //         cout<<page<<"\t";
    //         printTable(memory);
    //         cout<<"\t\tMiss\n";
    //     }
    // }

    cout<<"--------------------------------------------\n";
    cout<<"Total Hits :"<<hits<<endl;
    cout<<"Total Misses :"<<miss<<endl;
    cout<<"Hit Ratio :"<<(float)hits/n<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of pages : ";
    cin>>n;
    vector<int> pages(n);

    cout<<"Entre the pages : ";
    for(int i =0; i < n; ++i){
        cin>>pages[i];
    }

    int capacity;
    cout<<"Entre the capacity : ";
    cin>>capacity;

    lruImplementation(pages, n, capacity);

    return 0;
}