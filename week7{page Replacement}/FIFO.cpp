#include<iostream>
#include<string>

using namespace std;

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];  
    int index = 0;        
    int pageFaults = 0;      
    int found, i, j;

    for (i = 0; i < capacity; i++) {
        frames[i] = -1;
    }
    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[index] = pages[i];
            index = (index + 1) % capacity; 
            pageFaults++;               

            printf("Page %d -> Frames: ", pages[i]);
            for (j = 0; j < capacity; j++) {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }
            printf("\n");
        } else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;
    cout<<"Enter the N : ";
    cin>>n;
    cout<<"Enter the Cpacity : ";
    cin>>capacity;

    int pages[n];
    
    cout<<"Entre the pages to be load : ";

    for(int i =0; i < n; ++i) {
        cin>>pages[i];
    }

    fifoPageReplacement(pages, n, capacity);

    return 0;
}