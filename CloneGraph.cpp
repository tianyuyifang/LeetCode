// bfs
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == 0) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> toVisit;
        toVisit.push(node);
        map[node] = head;
        while(!toVisit.empty()){
            UndirectedGraphNode *cur = toVisit.front();
            toVisit.pop();
            for(auto nb:cur->neighbors){
                if(map.find(nb) == map.end()){
                    UndirectedGraphNode *nb_copy = new UndirectedGraphNode(nb->label);
                    map[nb] = nb_copy;
                    toVisit.push(nb);
                }
                map[cur]->neighbors.push_back(map[nb]);
            }
        }
        return head;
    }
};
// iterative dfs
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == 0) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
        stack<UndirectedGraphNode *> toVisit;
        toVisit.push(node);
        map[node] = head;
        while(!toVisit.empty()){
            UndirectedGraphNode *cur = toVisit.top();
            toVisit.pop();
            for(auto nb:cur->neighbors){
                if(map.find(nb) == map.end()){
                    UndirectedGraphNode *nb_copy = new UndirectedGraphNode(nb->label);
                    map[nb] = nb_copy;
                    toVisit.push(nb);
                }
                map[cur]->neighbors.push_back(map[nb]);
            }
        }
        return head;
    }
};
// recursive dfs
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == 0) return NULL;
        if (map.find(node) == map.end()){
            UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
            map[node] = copy;
            for(auto nb:node->neighbors){
                map[node]->neighbors.push_back(cloneGraph(nb));
            }
        }
        return map[node];
    }
private:
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
};
