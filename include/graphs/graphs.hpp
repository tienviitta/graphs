#pragma once

#include <set>
#include <string>
#include <unordered_map>

namespace graphs {

int add_one(int x);

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

} // namespace graphs
