#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
const int INF=INT_MAX;

void dijkstra(int start, vector<pair<int,int> >*_graph, int *d){
    // priority queue of pair<distance, vertex>
    // start에서 vertex 까지 현재까지 알려진 distance
    //오름차순 정렬을 위해서
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
    // pq.push({0, start});    // start ----> start 까지의 최단거리는 0
    pq.push(make_pair(0,start));

    d[start] =0;            // start ----> start 최단거리는 결정
    while(!pq.empty()){
        int dist =pq.top().first;// 최단거리
        int updated_vtx =pq.top().second;// 최단거리가 알려진 vertex
        pq.pop();
        if(d[updated_vtx]<dist){
            //이미 알려진 최단거리가 (d[updated_ 가
            //최단거리 dist 보다 짧다면
            //\새로운 정보가 없는 것이므로 생략
            continue;
        }

        // updated_vtx에 연결된 vertex 들만 대상으로
        for(int i=0;i<_graph[updated_vtx].size();i++){
            int dist_from_updated_vtx_to_i =_graph[updated_vtx][i].first;
            // new_dist: updated_vtx를 통해 거쳐가는 길이
            int new_dist =dist +dist_from_updated_vtx_to_i;
            int known_dist= d[_graph[updated_vtx][i].second];
            if(new_dist<known_dist){ // update_vtx 를 통해 가는 경로길이 (new_dist 가
                                    //이미 알려진 길이 (known_ 보다 짧으면
                d[_graph[updated_vtx][i].second] =new_dist;
                pq.push(make_pair(new_dist,_graph[updated_vtx][i].second));
            }
        }
    }
}

void addEdgeInfo(int from, int to, int distance, vector <pair<int,int> >*_graph){
    _graph[from].push_back(make_pair(distance,to));
    _graph[to].push_back(make_pair(distance,from));
}

int main(void){
    int n=4;// num. of vertext
    //동적할당 그래프
    vector<pair<int,int> >*graph= new vector<pair<int,int> >[n];
    //각 요소는 vector 이고 , 요소는 각 vertex 에 해당
    // graph[x] : vertex x 에서 직접 도달가능한 vertex 정보를 저장
    // pair<distance, to_vertex> = pair<int,int>

    int* shortest_dist_tbl =new int[n];
    // shortest distance table
    // shortex_dist_tbl[x] : start vertex 에서 vertex x 까지의 최단 경로

    // vertex 0----> 1, distance 2
    addEdgeInfo(0,1,2,graph);
    addEdgeInfo(0,2,35,graph);
    addEdgeInfo(0,3,20,graph);
    addEdgeInfo(1,2,1,graph);
    addEdgeInfo(1,3,7,graph);
    addEdgeInfo(2,3,4,graph);
    // shortest distance table을 INF 로 초기화
    
    fill(shortest_dist_tbl,shortest_dist_tbl + n,INF);


    // start vertext
    int start= 0;
    //다익스트라 알고리즘을 수행
    dijkstra(start,graph,shortest_dist_tbl);
    //모든 노드로 가기 위한 최단 거리를 출력
    cout<<"From: "<<start<<endl;
    for(int i=0;i<n;i++){
        //도달할 수 없는 경우 , 무한 (INFINITY) 이라고 출력
        if(shortest_dist_tbl[i] ==INF){
            cout<<"INFINITY"<<'\n';
        }
        //도달할 수 있는 경우 거리를 출력
        else{    
            cout<<"To: "<<i<<" : "<<shortest_dist_tbl[i]<<'\n';
        }
    }
    delete[] graph;
    delete[] shortest_dist_tbl;
}

#endif


#if 01
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;
const int INF = INT_MAX;

void dijkstra(int start, const vector<pair<int, int> > *graph, int n, int *d, int *prev) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    fill(d, d + n, INF);
    fill(prev, prev + n, -1);

    d[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int updated_vtx = pq.top().second;
        pq.pop();

        if (d[updated_vtx] < dist) {
            continue;
        }

        for (int i = 0; i < graph[updated_vtx].size(); i++) {
            int v = graph[updated_vtx][i].second;
            int new_dist = dist + graph[updated_vtx][i].first;

            if (new_dist < d[v]) {
                d[v] = new_dist;
                prev[v] = updated_vtx;
                pq.push(make_pair(new_dist, v));
            }
        }
    }
}

void addEdgeInfo(int from, int to, int distance, vector<pair<int, int> > *graph) {
    graph[from].push_back(make_pair(distance, to));
    graph[to].push_back(make_pair(distance, from));
}

void printPath(int src, int dest, int *prev) {
    vector<int> path;
    for (int at = dest; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    for (int v : path) {
        cout << v << " ";
    }
}

int main() {
    int n, e, q, u, v, w;
    cin >> n >> e;
    vector<pair<int, int> > *graph = new vector<pair<int, int> >[n];
    int *shortest_dist_tbl = new int[n];
    int *prev = new int[n];

    for (int i = 0; i < e; ++i) {
        cin >> u >> v >> w;
        addEdgeInfo(u, v, w, graph);
    }

    cin >> q;
    while (q--) {
        cin >> u >> v;
        dijkstra(u, graph, n, shortest_dist_tbl, prev);
        printPath(u, v, prev);
        cout << shortest_dist_tbl[v] << endl;
    }

    delete[] graph;
    delete[] shortest_dist_tbl;
    delete[] prev;
}

#endif