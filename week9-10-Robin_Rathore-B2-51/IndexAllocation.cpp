#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct File {
    string name;
    int startBlock;
    vector<int> indexBlock;
};

int main(){
    int n;
    cout<<"Enter the no. Of Files : ";
    cin>>n;
    vector<int> disk(1000, -1);

    unordered_map<string, File> files;

    cout<<"Enter te File Details : \n";
    
    for(int i =0; i <n; ++i){
        string name;
        int startBlcok, blockCount;

        cout<<"Enter the anem of File : "<<i+1;
        cin>>name;
        cout<<"Enter the Starting Block : ";
        cin>>startBlcok;
        cout<<"Enter the Total number of Blocks : ";
        cin>>blockCount;

        vector<int> indexBlock(blockCount);
        cout<<"Enter the Blocks : ";
        for(int j =0; j < blockCount; ++j){
            cin>>indexBlock[j];
        }

        bool isAllocate = true;
        for(int j =0; j < indexBlock.size(); ++j){
            if(disk[indexBlock[j]] != -1 || indexBlock[j] > disk.size()){
                isAllocate = false;
                break;
            }
        }

        if(isAllocate){
            for(int j = 0; j < indexBlock.size(); ++j){
                disk[indexBlock[j]] = 1;
            }
            files[name].name = name;
            files[name].startBlock = startBlcok;
            files[name].indexBlock = indexBlock;
        }else{
            cout<<"File Cannot be Allocated : \n";
        }

    }

    string search;

    cout<<"Entre the file to be searched : ";
    cin>>search;

    if(files.find(search) != files.end()){
        cout<<"File Name : "<<files[search].name<<endl;
        cout<<"Start Block : "<<files[search].startBlock<<endl;
        cout<<"Index Blocks : ";
        for(int i =0; i < files[search].indexBlock.size(); ++i){
            cout<<files[search].indexBlock[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"File Not Found \n";
    }
}
