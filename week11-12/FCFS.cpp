#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of disk request : ";
    cin>>n;

    vector<int> disk(n);
    cout<<"Enter the disk requets : ";

    for(int i =0; i < n; ++i){
        cin>>disk[i];
    }

    int initialPos;
    cout<<"Enter the initial Position : ";
    cin>>initialPos;

    int totalMoement =0;

    for(auto it : disk){
        totalMoement += abs(it - initialPos);
        initialPos = it;
    }

    cout<<"The Total Head Movements : "<<totalMoement<<endl;
    cout<<"Average Head Movements : "<<(float)totalMoement/n;
}