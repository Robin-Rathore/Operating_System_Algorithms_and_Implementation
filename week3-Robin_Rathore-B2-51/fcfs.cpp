#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct process{
    int pid, at, bt;
    int tat, wt, ct;
};

void calculateAverages(const vector<process>& ps) {
    double totalTAT = 0, totalWT = 0;
    for (const auto& p : ps) {
        totalTAT += p.tat;
        totalWT += p.wt;
    }

    double avgTAT = totalTAT / ps.size();
    double avgWT = totalWT / ps.size();

    cout << "\nAverage Turn Around Time (TAT): " << avgTAT << endl;
    cout << "Average Waiting Time (WT): " << avgWT << endl;
}
void fcfs(vector<process>& ps){

    ps[0].ct = ps[0].at + ps[0].bt;
    
    //Completion Time
    for(int i =1; i < ps.size(); ++i){
        ps[i].ct = max(ps[i - 1].ct, ps[i].at) + ps[i].bt;
    }

    //Turn Around Time;
    for(int i =0; i < ps.size(); ++i){
        ps[i].tat = ps[i].ct - ps[i].at;
    }

    //Waiting Time
    for(int i =0; i < ps.size(); ++i){
        ps[i].wt = ps[i].tat - ps[i].bt;
    }
}

void print(vector<process> ps){
    cout<<"First Come First Serve CPU Scheduling Algo : "<<endl;
    cout<<"---------------------------------------------------\n";
    cout<<"Arrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    cout<<"----------------------------------------------------\n";

    for(int i =0; i < ps.size(); ++i){
        cout<<i+1<<"\t"<<ps[i].at<<"\t"<<ps[i].bt<<"\t"<<ps[i].ct<<"\t"<<ps[i].tat<<"\t"<<ps[i].wt<<"\n";
    }

    cout<<"-----------------------------------------------\n";
    for (int i = 0; i < ps.size(); ++i) {
        // for (int j = 0; j < ps[i].bt / 2; ++j) cout << " ";
        cout << " P " << ps[i].pid;
        // for (int j = ps[i].bt / 2 + 1; j < ps[i].bt; ++j) cout << " ";
        cout << "|";
    }cout<<endl;
    cout << "---------------------------------------------\n ";

    calculateAverages(ps);
}

bool compareByArrival(const process &a, const process &b) {
    return a.at < b.at;
}




int main(){
    int n;
    cout<<"Entre the number of processes : ";
    cin>>n;

    vector<process> ps(n);

    for(int i =0; i < n; ++i){
        cout<<"Enter the Arrival Time and Burst Time of Processes "<<i+1<<" : ";
        cin>>ps[i].at>>ps[i].bt;
        ps[i].pid = i+1;
    }


    sort(ps.begin(), ps.end(), compareByArrival);


    fcfs(ps);
    print(ps);

}
