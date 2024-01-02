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
    std::vector<std::vector<std::string>> edges = {
        {"i", "j"}, {"k", "i"}, {"m", "k"}, {"k", "l"}, {"o", "n"}};

    // Has path
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "hasPath:\n");
    bool found = graphs::hasPath(graphb, "f", "j");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  found: {}\n", found);
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "hasPathRec:\n");
    found = graphs::hasPathRec(graphb, "f", "k");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  found: {}\n", found);
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "undirectedPath:\n");
    found = graphs::undirectedPath(edges, "i", "l");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "  found: {}\n", found);
    found = graphs::undirectedPath(edges, "l", "n");
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
}