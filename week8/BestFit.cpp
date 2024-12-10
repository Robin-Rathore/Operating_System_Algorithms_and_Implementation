#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void LOOK(vector<int>& requests, int head, int diskSize, string direction) {
    vector<int> left, right, sequence;
    int seekCount = 0;

    // Separate requests into left and right of the head
    for (int request : requests) {
        if (request < head) {
            left.push_back(request);
        } else {
            right.push_back(request);
        }
    }

    // Sort requests in ascending order
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    // Process based on the direction
    if (direction == "Left") {
        // Process leftward requests
        for (int i = left.size() - 1; i >= 0; --i) {
            sequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }
        // Process rightward requests
        for (int i = 0; i < right.size(); ++i) {
            sequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }
    } else if (direction == "Right") {
        // Process rightward requests
        for (int i = 0; i < right.size(); ++i) {
            sequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }
        // Process leftward requests
        for (int i = left.size() - 1; i >= 0; --i) {
            sequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }
    }

    // Output results
    cout << "\nSeek Sequence: ";
    for (int seq : sequence) {
        cout << seq << " ";
    }
    cout << "\nTotal Seek Distance: " << seekCount << " cylinders\n";
}

int main() {
    int n, head, diskSize = 200;
    string direction;

    cout << "Enter the number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the requests: ";
    for (int i = 0; i < n; ++i) {
        cin >> requests[i];
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    cout << "Enter the direction (Left or Right): ";
    cin >> direction;

    LOOK(requests, head, diskSize, direction);

    return 0;
}
