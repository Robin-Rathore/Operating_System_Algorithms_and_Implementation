#include<iostream>
#include<vector>

using namespace std;


void WorstFit(vector<int>& memory, vector<int>& processes, int n, int m)
{
    vector<int> allocation(m);

    cout<<"Worst Fit Allocation Processes\n";
    cout<<"-----------------------------------------\n";
    cout<<"Process\tSize\tBlock Allocated\n";
    cout<<"-----------------------------------------\n";
    for(int i =0; i < m; ++i){
        int index = -1;
        int maxi = INT_MIN;

        for(int j =0; j < n; ++j){
            if(processes[i] <= memory[j] && maxi < memory[j]){
                maxi = memory[j];
                index = j;
            }
        }

        if(index != -1){
            memory[index] -= processes[i];
            allocation[i] = index;
        }

        if(allocation[i] != -1){
            cout<<"P"<<i+1<<"\t"<<processes[i]<<"\tBlock\t"<<allocation[i]+1<<endl;
        }else{
            cout<<"P"<<i+1<<"\t"<<processes[i]<<"\tNot Allocated"<<endl;
        }
    }
}
int main(){
    int n, m;
    cout<<"Enter the number of memory Blocks : ";
    cin>>n;
    cout<<"Enter the number of Processes Block : ";
    cin>>m;

    vector<int> memory(n);
    vector<int> proesses(m);

    cout<<"Enter the memory Blocks : ";
    for(int i =0; i < n; ++i){
        cin>>memory[i];
    }
    
    cout<<"Enter the processes size : ";
    for(int i =0; i < m; ++i){
        cin>>proesses[i];
    }

    WorstFit(memory, proesses, n, m);

    return 0;
}