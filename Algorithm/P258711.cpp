#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<unordered_map>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> graph_column;
vector<bool> visited;
vector<int> outdegree;
vector<int> indegree;
vector<int> original_node;

void print_edges(vector<vector<int>> edges) {
	for (int i = 0;i < edges.size();i++) {
		cout << edges[i][0] << " " << edges[i][1] << endl;
	}
}

void print_degree(vector<int> degree) {
	for (int i = 0;i < degree.size();i++) {
		cout << degree[i] << " ";
	}
	cout << endl;
}

void print_graph(vector<vector<int>> graph) {
	for (int i = 0;i < graph.size();i++) {
		for (int j = 0;j < graph[i].size();j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void print_visited(vector<bool> visited) {
	for (int i = 0;i < visited.size();i++) {
		cout << visited[i] << " ";
	}
	cout << endl;
}

void dfs(int start) {
	//1. 스타트 노드 방문 처리
	if (visited[start]) return;
	visited[start] = true;
	//cout << start << " ";

	//2. 연결된 노드 탐색하며 방문 처리
	for (int next:graph[start]) {
		if (!visited[next])
			dfs(next);
	}
}

void edge_find(int start) {
	//1. 스타트 노드 방문 처리
	if(visited[start]) return;
	visited[start] = true;
	
	//2. edge에서 [i][1]==start인 노드를 찾아 재귀 호출
	for (int prev: graph_column[start]) {
		if(!visited[prev]&&outdegree[prev]==1) {
			edge_find(prev);
		}
	}
}


vector<int> solution(vector<vector<int>> edges) {
	vector<int> answer;

	//0. 변수 선언
	int special_node = 0;
	int stick_graph = 0;
	int donut_graph = 0;
	int eight_graph = 0;

	//0.0 노드 압축
	set<int> nodes;
	for (auto &edge: edges) {
		nodes.insert(edge[0]);
		nodes.insert(edge[1]);
	}

	unordered_map<int, int> node_compress;
	original_node.assign(nodes.begin(), nodes.end());
	for (int i = 0; i < original_node.size(); i++) {
		node_compress[original_node[i]] = i;
	}

	int node_count = original_node.size();


	//0.1  벡터들 초기화
	graph.assign(node_count, vector<int>());
	graph_column.assign(node_count , vector<int>());
	visited.assign(node_count , false);
	outdegree.assign(node_count , 0);
	indegree.assign(node_count , 0);

	//0.2. 연결 리스트 새로 만들기
	for (auto &edge: edges) {
		int parent = node_compress[edge[0]];
		int child = node_compress[edge[1]];

		graph[parent].push_back(child);
		graph_column[child].push_back(parent);
		outdegree[parent] += 1;
		indegree[child] += 1;
	}
	
	
	//2. outdegreed와 indegree에 따른 그래프 분류
	for (int i = 0;i < node_count;i++) {
		
		if(visited[i]) continue; 
		print_visited(visited);

		if (indegree[i] == 0 && outdegree[i] >= 2) {
			special_node = original_node[i];
			visited[i] = true;
		}

		else if (outdegree[i] == 0 && indegree[i]!=0) {
			stick_graph += 1;
			// 막대 그래프는 종점 노드를 기준으로 탐색
			edge_find(i);
		}
		else if(outdegree[i] == 2 && outdegree[i]<=indegree[i]) {
			eight_graph += 1;
			dfs(i);
		}
	}

	//3. 도넛 그래프 탐색
	for (int i = 0;i < node_count;i++) {
		if (!visited[i]) {
			//cout<< "donut node: " << i << endl;
			donut_graph += 1;
			dfs(i);
		}
	}

	//4. 결과 할당
	print_degree(outdegree);
	print_degree(indegree);

	cout << special_node << endl;
	cout << donut_graph << endl;
	cout << stick_graph << endl;
	cout << eight_graph << endl;
	

	
	answer.push_back(special_node);
	answer.push_back(donut_graph);
	answer.push_back(stick_graph);
	answer.push_back(eight_graph);

    return answer;
}

int main() {
	//vector<vector<int>> edges = { {2,3},{4,3},{1,1},{2,1} };
	vector<vector<int>> edges={{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}};
	vector<int> answer = solution(edges);
	
	return 0;
}