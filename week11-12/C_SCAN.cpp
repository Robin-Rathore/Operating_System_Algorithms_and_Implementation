#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

void C_SCAN(vector<int>& request, int diskSize, string direction, int n, int head){
    vector<int> sequence;
    vector<int> left, right;

    for(int i =0; i < n; ++i){
        if(request[i] >= head){
            right.push_back(request[i]);
        }else{
            left.push_back(request[i]);
        }
    }

        left.push_back(0);
        right.push_back(diskSize-1);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int seekCount =0;
    for(int i =0; i < right.size(); ++i){
        seekCount += abs(right[i] - head);
        head = right[i];
        sequence.push_back(right[i]);
    }

    head = 0;
    seekCount += diskSize-1;

    for(int i = left.size()-1; i >= 0; --i){
        seekCount += abs(head - left[i]);
        sequence.push_back(left[i]);
        head = left[i];
    }

    cout << "\nSeek Sequence: ";
    for (int seq : sequence) {
        cout << seq << " ";
    }
    cout << "\nTotal Seek Distance: " << seekCount << " cylinders\n";
}

int main(){
    int n, diskSize, head;
    string direction;
    cout<<"Entre the number of request : ";
    cin>>n;

    vector<int> request(n);
    cout<<"Enter the request : ";
    
    for(int i =0; i < n; ++i){
        cin>>request[i];
    }

    cout<<"Entre the disk Size : ";
    cin>>diskSize;

    cout<<"Enter the head : ";
    cin>>head;

    cout<<"Entre the directio : ";
    cin>>direction;

    C_SCAN(request, diskSize, direction, n, head);

    return 0;

}