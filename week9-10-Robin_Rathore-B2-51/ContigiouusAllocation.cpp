#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

struct File{
    string name;
    int startBlock;
    int bloackCount;
};

int main(){
    int numFiles;
    cout<<"Enter the number of files : ";
    cin>>numFiles;

    unordered_map<string, File> files;

    cout<<"Entre the file details : \n";

    vector<int> Disk(1000, -1);

    for(int i =0; i < numFiles; ++i){
        string name;
        int startBlock;
        int totalCount;

        cout<<"Enter the Name of File "<<i+1<<" : ";
        cin>>name;
        cout<<"Enter the Start Block of file : ";
        cin>>startBlock;
        cout<<"Enter the Total Number of Blocks : ";
        cin>>totalCount;

        bool canAllocate = true;
        for(int j = startBlock; j <= startBlock+totalCount; ++j){
            if(Disk[j] != -1 || j > Disk.size()){
                canAllocate = false;
                break;
            }
        }

        if(canAllocate){
            for(int j = startBlock; j <= startBlock+totalCount; ++j){
                Disk[j] = 1;
            }

            files[name].name = name;
            files[name].startBlock = startBlock;
            files[name].bloackCount = totalCount;

        }else{
            cout<<name<<" Cannot be Allocated \n";
        }
    }

    string search;
    cout<<"Enter the String to saerch : ";
    cin>>search;

    if(files.find(search) != files.end()){
        cout<<"File Name : "<<files[search].name<<endl;
        cout<<"Starting Block : "<<files[search].startBlock<<endl;
        cout<<"Total Block Count : "<<files[search].bloackCount<<endl;
    }else{
        
    }

}



// #include <iostream>
// #include <unordered_map>
// #include <string>
// #include <vector>

// using namespace std;

// // Structure to represent a file
// struct File {
//     string name;   // File name
//     int startBlock; // Starting block of the file
//     int blockCount; // Number of blocks allocated
// };

// int main() {
//     int numFiles;
//     cout << "Enter the number of files: ";
//     cin >> numFiles;

//     unordered_map<string, File> files; // Store file details
//     vector<int> disk(1000, 0); // Simulate a disk with 100 blocks (0 = free, 1 = allocated)

//     // Input file details
//     for (int i = 0; i < numFiles; ++i) {
//         string fileName;
//         int startBlock, blockCount;
//         cout << "\nEnter file name, starting block, and number of blocks: ";
//         cin >> fileName >> startBlock >> blockCount;

//         bool isAllocated = true;

//         // Check for contiguous space
//         for (int j = startBlock; j < startBlock + blockCount; ++j) {
//             if (j >= disk.size() || disk[j] == 1) { // Out of bounds or block already allocated
//                 isAllocated = false;
//                 break;
//             }
//         }

//         if (isAllocated) {
//             for (int j = startBlock; j < startBlock + blockCount; ++j) {
//                 disk[j] = 1; // Mark blocks as allocated
//             }

//             // Manually create a File object and add it to the map
//             File newFile;
//             newFile.name = fileName;
//             newFile.startBlock = startBlock;
//             newFile.blockCount = blockCount;

//             files[fileName] = newFile; // Insert into the map

//             cout << "File " << fileName << " allocated successfully.\n";
//         } else {
//             cout << "File " << fileName << " could not be allocated due to insufficient or non-contiguous space.\n";
//         }
//     }

//     // Search for a file
//     string searchFile;
//     cout << "\nEnter the name of the file to search: ";
//     cin >> searchFile;

//     if (files.find(searchFile) != files.end()) {
//         const File& file = files[searchFile];
//         cout << "\nFile Details:\n";
//         cout << "File Name: " << file.name << endl;
//         cout << "Starting Block: " << file.startBlock << endl;
//         cout << "Number of Blocks: " << file.blockCount << endl;
//         cout << "Block Numbers: ";
//         for (int j = file.startBlock; j < file.startBlock + file.blockCount; ++j) {
//             cout << j << " ";
//         }
//         cout << endl;
//     } else {
//         cout << "File not found." << endl;
//     }

//     return 0;
// }
