#pragma once

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace graphs {

int add_one(int x);

// Graphs

void depthFirstPrint(std::unordered_map<std::string, std::vector<std::string>>& graph,
                     std::string source);

void depthFirstRecPrint(std::unordered_map<std::string, std::vector<std::string>>& graph,
                        std::string source);

void breathFirstPrint(std::unordered_map<std::string, std::vector<std::string>>& graph,
                      std::string source);

bool hasPath(std::unordered_map<std::string, std::vector<std::string>>& graph,
             std::string src, std::string dst);

bool hasPathRec(std::unordered_map<std::string, std::vector<std::string>>& graph,
                std::string src, std::string dst);

bool undirectedPath(std::vector<std::vector<std::string>>& edges, std::string src,
                    std::string dst);
void buildGraph(std::vector<std::vector<std::string>>& edges,
                std::unordered_map<std::string, std::vector<std::string>>& graph);
bool hasUndirectedPath(std::unordered_map<std::string, std::vector<std::string>>& graph,
                       std::string src, std::string dst, std::set<std::string>& visited);

int connectedComponentsCount(std::unordered_map<int, std::vector<int>>& graph);
bool traverseGraph(std::unordered_map<int, std::vector<int>>& graph, int node,
                   std::set<int>& visited);

int largestComponentsCount(std::unordered_map<int, std::vector<int>>& graph);
int traverseSize(std::unordered_map<int, std::vector<int>>& graph, int curr,
                 std::set<int>& visited);

int shortestPath(std::vector<std::vector<std::string>>& edges, std::string src,
                 std::string dst);

int islandCount(std::vector<std::vector<std::string>>& grid);
bool exploreGrid(std::vector<std::vector<std::string>>& grid, int row, int col,
                 std::set<std::string>& visited);

int minimumIsland(std::vector<std::vector<std::string>>& grid);
int exploreSize(std::vector<std::vector<std::string>>& grid, int row, int col,
                std::set<std::string>& visited);

// TVQueue

template <typename T> class TVQueue {
  private:
    std::vector<T> elements;

  public:
    void push(const T& value) { elements.push_back(value); }
    void pop() {
        if (!empty()) {
            elements.erase(elements.begin());
        }
    }
    bool empty() const { return elements.empty(); }
    const T& front() const {
        if (!empty()) {
            return elements.front();
        }
        throw std::out_of_range("Queue is empty");
    }
};

// Linked list

class Node {
  public:
    std::string val;
    Node* next;
    Node(std::string init) : val(init), next(nullptr) {}
    // ~Node();
};

void printLinkedList(Node* head);
void printRecLinkedList(Node* head);

// Binary tree

class TreeNode {
  public:
    std::string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(std::string init) : val(init), left(nullptr), right(nullptr){};
    // ~TreeNode();
};

void depthFirstBT(TreeNode* root, std::vector<std::string>& values);
void breathFirstBT(TreeNode* root, std::vector<std::string>& values);
bool includesBT(TreeNode* root, std::string value);
bool includesRecBT(TreeNode* root, std::string value);

// Dynamic
int fib(int n);
int fibRec(int n, std::unordered_map<int, int>& cache);

} // namespace graphs
