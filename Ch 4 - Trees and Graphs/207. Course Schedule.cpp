class Solution {
public:
	vector<vector<int>> adj;
	vector<int> visited;

	bool isDAG(int x) {
		visited[x] = 1; // gray

		for (auto v : adj[x]) {
			if (visited[v] == 0) {
				if (!isDAG(v))
					return false;
			} else if (visited[v] == 1) {
				return false;// cycle detected
			}
		}

		visited[x] = 2;
		return true;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, {});
		for (auto p : prerequisites) {			
			adj[p[1]].push_back(p[0]);
		}

		visited.assign(numCourses, 0);
  
		for (int i = 0; i < numCourses; i++) {
			if (visited[i] == 0) {
				if (!isDAG(i))
					return false;
			}
		}

		// it is a DAG
		return true;
	}
};
