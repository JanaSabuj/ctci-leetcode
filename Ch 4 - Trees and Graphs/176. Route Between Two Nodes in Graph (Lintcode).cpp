/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool dfs(DirectedGraphNode* src, DirectedGraphNode* dest) {
        // base
        if (src == dest)
            return true;

        // main
        for (auto v : src->neighbors) {
            if (dfs(v, dest))
                return true;
        }

        return false;
    }
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        return dfs( s, t);
    }
};
