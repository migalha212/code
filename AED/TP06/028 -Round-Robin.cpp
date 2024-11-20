#include <queue>
#include <iostream>
using namespace std;

typedef struct{
    string name;
    int interval;
}process;

void round_Robin(queue<process>&, int);

int main(){
    int timeLimit;  //* maximum time each pocess can take up per iteration
    cin >> timeLimit;
    int n;      //* #of processes in the queue
    cin >> n;
    queue<process> q;
    for(int i = 0; i < n; i++){
        string s; int j; //* get the imput for the name and interval of each process
        cin >> s >> j;
        q.push({s,j});
    }
    round_Robin(q,timeLimit);
}

void round_Robin(queue<process> &q, int timeLimit){
    int cc = 0; //* "clock counter" counts the number of clock cycles elated
    int pc = 0; //* "program counter" counts the number of times the processor changes process
    while(!q.empty()){
        process pr = q.front();
        pc++;
        if(pr.interval <= timeLimit){
            cc += pr.interval;
            pr.interval = 0;
            cout << pr.name << ' ' << cc << ' ' << pc << endl;
            q.pop();
        }
        else{
            pr.interval -= timeLimit;
            cc += timeLimit;
            q.push(pr);
            q.pop();
        }
    }
}