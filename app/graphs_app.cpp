#include "graphs/graphs.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    // Test graph I
    std::unordered_map<std::string, std::vector<std::string>> grapha = {
        {"a", {"b", "c"}}, {"b", {"d"}}, {"c", {"e"}},
        {"d", {"f"}},      {"e", {}},    {"f", {}}};

    // Depth first
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "depthFirstPrint:\n");
    graphs::depthFirstPrint(grapha, "a");
    // Depth first recursive
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "depthFirstRecPrint:\n");
    graphs::depthFirstRecPrint(grapha, "a");
    // Breath first
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "breathFirstPrint:\n");
    graphs::breathFirstPrint(grapha, "a");

    // Test graph II
    std::unordered_map<std::string, std::vector<std::string>> graphb = {
        {"f", {"g", "i"}}, {"g", {"h"}}, {"h", {}},
        {"i", {"g", "k"}}, {"j", {"i"}}, {"k", {}}};
    // TODO: These could be tuples?!
    std::vector<std::vector<std::string>> edgesa = {
        {"i", "j"}, {"k", "i"}, {"m", "k"}, {"k", "l"}, {"o", "n"}};

    // Has path
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "hasPath:\n");
    bool found = graphs::hasPath(graphb, "f", "j");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  found: {}\n", found);
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "hasPathRec:\n");
    found = graphs::hasPathRec(graphb, "f", "k");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  found: {}\n", found);
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "undirectedPath:\n");
    found = graphs::undirectedPath(edgesa, "i", "l");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  found: {}\n", found);
    found = graphs::undirectedPath(edgesa, "l", "n");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  found: {}\n", found);

    // Component count
    std::unordered_map<int, std::vector<int>> graphc = {
        {0, {8, 1, 5}}, {1, {0}},    {5, {0, 8}}, {8, {0, 5}},
        {2, {3, 4}},    {3, {2, 4}}, {4, {3, 2}}};
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "connectedComponentsCount:\n");
    int count = graphs::connectedComponentsCount(graphc);
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  count: {}\n", count);
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "largestComponentsCount:\n");
    count = graphs::largestComponentsCount(graphc);
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  count: {}\n", count);

    // Shortest path
    std::vector<std::vector<std::string>> edgesb = {
        {"w", "x"}, {"x", "y"}, {"z", "y"}, {"z", "v"}, {"w", "v"}};
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "shortestPath:\n");
    int size = graphs::shortestPath(edgesb, "w", "z");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  size: {}\n", size);

    // Island count
    // clang-format off
    std::vector<std::vector<std::string>> grid {
      {"W", "L", "W", "W", "W"},
      {"W", "L", "W", "W", "W"},
      {"W", "W", "W", "L", "W"},
      {"W", "W", "L", "L", "W"},
      {"L", "W", "W", "L", "L"},
      {"L", "L", "W", "W", "W"}
    };
    // clang-format on
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "islandCount:\n");
    count = graphs::islandCount(grid);
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  count: {}\n", count);
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "minimumIsland:\n");
    size = graphs::minimumIsland(grid);
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  size: {}\n", size);

    // Linked list
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "printLinkedList:\n");
    graphs::Node a("A");
    graphs::Node b("B");
    graphs::Node c("C");
    graphs::Node d("D");
    a.next = &b;
    b.next = &c;
    c.next = &d;
    fmt::print("  ");
    graphs::printLinkedList(&a);
    fmt::print("  ");
    graphs::printRecLinkedList(&a);
}