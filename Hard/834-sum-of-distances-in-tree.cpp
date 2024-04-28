class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> subtreeSize(n);
        vector<int> totalDistances(n);
        vector<int> answer(n);
        
        // Step 1: Build adjacency list
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // Step 2: Perform DFS to calculate subtree sizes and total distances
        dfs(0, -1, adjList, subtreeSize, totalDistances);
        
        // Step 3: Perform DFS to propagate information and calculate sum of distances
        propagate(0, -1, adjList, subtreeSize, totalDistances, answer);
        
        return answer;
    }
    
private:
    // Step 2: Depth-first traversal to calculate subtree sizes and total distances
    void dfs(int node, int parent, const vector<vector<int>>& adjList, vector<int>& subtreeSize, vector<int>& totalDistances) {
        subtreeSize[node] = 1;
        totalDistances[node] = 0;
        
        for (int neighbor : adjList[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, adjList, subtreeSize, totalDistances);
                subtreeSize[node] += subtreeSize[neighbor];
                totalDistances[node] += totalDistances[neighbor] + subtreeSize[neighbor];
            }
        }
    }
    
    // Step 3: Depth-first traversal to propagate information and calculate sum of distances
    void propagate(int node, int parent, const vector<vector<int>>& adjList, const vector<int>& subtreeSize, const vector<int>& totalDistances, vector<int>& answer) {
        answer[node] = totalDistances[node] + (parent == -1 ? 0 : answer[parent] - subtreeSize[node] - totalDistances[node]) + (parent == -1 ? 0 : (int)adjList.size() - subtreeSize[node]);
        
        for (int neighbor : adjList[node]) {
            if (neighbor != parent) {
                propagate(neighbor, node, adjList, subtreeSize, totalDistances, answer);
            }
        }
    }
};