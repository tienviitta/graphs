#include "graphs/graphs.hpp"
#include <deque>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace graphs {

int add_one(int x) { return x + 1; }

void depthFirstPrint(std::unordered_map<std::string, std::vector<std::string>>& graph,
                     std::string source) {
    // Stack
    std::deque<std::string> stack;
    // Insert source
    stack.push_back(source);
    // Depth first
    while (!stack.empty()) {
        std::string curr = stack.back();
        stack.pop_back();
        fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "  node: {}\n", curr);
        for (std::string node : graph[curr]) {
            stack.push_back(node);
        }
    }
}

void depthFirstRecPrint(std::unordered_map<std::string, std::vector<std::string>>& graph,
                        std::string source) {
    fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "  node: {}\n", source);
    // Depth first recursive
    for (std::string node : graph[source]) {
        depthFirstRecPrint(graph, node);
    }
}

void breathFirstPrint(std::unordered_map<std::string, std::vector<std::string>>& graph,
                      std::string source) {
    // Queue
    std::deque<std::string> queue;
    // Insert source
    queue.push_back(source);
    // Breath first
    while (!queue.empty()) {
        std::string curr = queue.front();
        queue.pop_front();
        fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "  node: {}\n", curr);
        for (std::string node : graph[curr]) {
            queue.push_back(node);
        }
    }
}

bool hasPath(std::unordered_map<std::string, std::vector<std::string>>& graph,
             std::string src, std::string dst) {
    // Queue
    std::deque<std::string> queue;
    // Insert source
    queue.push_back(src);
    // Breath first
    while (!queue.empty()) {
        std::string curr = queue.front();
        queue.pop_front();
        // fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "  node: {}\n", curr);
        if (curr.compare(dst) == 0) {
            return true;
        }
        for (std::string node : graph[curr]) {
            queue.push_back(node);
        }
    }
    return false;
}

bool hasPathRec(std::unordered_map<std::string, std::vector<std::string>>& graph,
                std::string src, std::string dst) {
    if (src.compare(dst) == 0) {
        return true;
    }
    // Depth first recursive
    for (std::string neighbor : graph[src]) {
        if (hasPathRec(graph, neighbor, dst) == true) {
            return true;
        }
    }
    return false;
}

bool undirectedPath(std::vector<std::vector<std::string>>& edges, std::string src,
                    std::string dst) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::set<std::string> visited;
    buildGraph(edges, graph);
    return hasUndirectedPath(graph, src, dst, visited);
    // for (auto vertex : graph) {
    //     fmt::print("  vertex: {}\n", vertex);
    // }
}

void buildGraph(std::vector<std::vector<std::string>>& edges,
                std::unordered_map<std::string, std::vector<std::string>>& graph) {
    for (auto edge : edges) {
        auto a = edge.at(0);
        auto b = edge.at(1);
        if (!graph.contains(a)) {
            std::vector<std::string> neighbors;
            graph.emplace(a, neighbors);
        }
        if (!graph.contains(b)) {
            std::vector<std::string> neighbors;
            graph.emplace(b, neighbors);
        }
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
        // fmt::print("  edge: {}, a: {}, b: {}\n", edge, a, b);
    }
}

bool hasUndirectedPath(std::unordered_map<std::string, std::vector<std::string>>& graph,
                       std::string src, std::string dst, std::set<std::string>& visited) {
    // Check if we found destination
    if (src.compare(dst) == 0) {
        return true;
    }
    // Check if node visited already
    // if (visited.find(src) != visited.end()) { // Note! Pre C++20!
    if (visited.contains(src)) {
        return false;
    }
    // Add node to visited
    visited.emplace(src);
    // Depth first recursive
    for (std::string neighbor : graph[src]) {
        if (hasUndirectedPath(graph, neighbor, dst, visited) == true) {
            return true;
        }
    }
    return false;
}

} // namespace graphs