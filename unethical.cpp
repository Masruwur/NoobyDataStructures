#include <iostream>
#include <map>
#include <queue>

using namespace std;

class unethicalQueue{
    queue<int>* q;
    map<int,int>* m;
    public:
    unethicalQueue(){
        q = new queue<int>;
    }
    unethicalQueue(map<int,int>* m){
         q = new queue<int>;
         this->m = m;
    }
    ~unethicalQueue(){
        delete q;
    }

    void enqueue(int x){
        
        if(q->empty()){
            q->push(x);
            return;
        }

        int count=0;

        while(count <q->size() && m->at(q->front())!=m->at(x)){
            q->push(q->front());
            q->pop();
            count++;
        }

        while(count<q->size() && m->at(q->front())==m->at(x)){
            q->push(q->front());
            q->pop();
            count++;
        }

        q->push(x);

        int rotate = q->size()-count-1;

        for(int i=0;i<rotate;i++){
           q->push(q->front());
           q->pop();
        }

    

    }

    void dequeue(){
        int res = q->front();
        q->pop();
        cout<<res<<endl;
    }

    

};

int main(){

    map<int,int> m;

    int gCount=0;
    cin>>gCount;
    for(int i=0;i<gCount;i++){
        int pCount;
        cin>>pCount;
        for(int j=0;j<pCount;j++){
            int temp;
            cin>>temp;
            m[temp] = i;
        }
    }

    unethicalQueue q(&m);
    string command="";
    int data=0;

    while(true){
        cin>>command;
        if(command=="STOP") break;
        if(command=="DEQUEUE") q.dequeue();
        else if(command=="ENQUEUE"){
            cin>>data;
            q.enqueue(data);
        }
    }

    


    return 0;
    
}