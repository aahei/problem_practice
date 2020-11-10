#include <iostream>
#include <queue>

using namespace std;



const int INF = ~(1 << 31);

struct Edge{
    int w;
    int to;
    Edge(int w_ = 0, int to_ = 0):w(w_), to(to_){}
};



bool operator < (const Edge & a, const Edge & b){
    return a.w > b.w;
}//priority_queue puts bigger elements on the top

Edge g[105][105];

int main(){
    int n, d;
    while(cin >> n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){

            cin >> d;
            g[i][j] = Edge(d, j);
        }

    priority_queue<Edge> pq;
    pq.push(Edge(0, 0));
    bool bUsed[105];
    Edge nowPoint;
    int vDist[105];
    int total_w = 0;

    for(int i = 0; i < 100; ++i){
        vDist[i] = INF;
        bUsed[i] = false;
    }

    while(!pq.empty()){
        do{
            nowPoint = pq.top();
            pq.pop();
        }while(!pq.empty() && bUsed[nowPoint.to] == true);
        if(bUsed[nowPoint.to] == false){//In case of the do-while block stopped due to pq.empty
            bUsed[nowPoint.to] = true;
            total_w += nowPoint.w;
            for(int i = 0; i < n; i++){
                if(bUsed[i] == true)
                    continue;
                if(vDist[i] > g[nowPoint.to][i].w){
                    vDist[i] = g[nowPoint.to][i].w;
                    pq.push(Edge(vDist[i], i));
                }
            }
        }
         // cout << total_w << endl;
    }

    cout << total_w << endl;
}
    return 0;
}
