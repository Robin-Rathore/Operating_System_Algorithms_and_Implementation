#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void SCAN(vector<int>& requests, string dirextion, int n, int diskSize, int head){
    vector<int> left, right;
    vector<int> sequence;
    int seekCount =0;

    for(int i =0; i < n; ++i){
        if(requests[i] >= head){
            right.push_back(requests[i]);
        }else{
            left.push_back(requests[i]);
        }
    }

    if(dirextion == "Left"){
        left.push_back(0);
    }else if(dirextion == "Right"){
        right.push_back(diskSize-1);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if(dirextion == "Left"){
        for(int i = left.size()-1; i >= 0; --i){
            sequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }

        for(int i =0; i < right.size(); ++i){
            sequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }
    }else if(dirextion == "Right"){
        for(int i =0; i < right.size(); ++i){
            sequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }

        for(int i = left.size()-1; i >= 0; --i){
            sequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }
    }

    cout << "Seek Sequence: ";
    for (int seq : sequence)
        cout << seq << " ";
    cout << endl;

    cout << "Total Seek Distance: " << seekCount << endl;
}

int main(){
    int n;
    int diskSize, head;
    string direction;

    cout<<"Enter the number of requests : ";
    cin>>n;

    vector<int> requests(n);

    cout<<"Enter the request : ";
    for(int i =0; i < n; ++i){
        cin>>requests[i];
    }

    cout<<"Enter the head : ";
    cin>>head;

    cout<<"Enter the disk Size : ";
    cin>>diskSize;

    cout<<"Enter the directoin Left or Right :  ";
    cin>>direction;

    SCAN(requests, direction, n, diskSize, head);

    return 0;
}