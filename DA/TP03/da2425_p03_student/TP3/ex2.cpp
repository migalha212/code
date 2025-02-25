// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "MSTTestAux.h"
#include "../data_structures/UFDS.h"

/**
 * Auxiliary function to set the "path" field to make a spanning tree.
 */
template <typename T>
void dfsKruskalPath(Vertex<T> *v) {
 // TODO
}

template <typename T>
std::vector<Vertex<T> *> kruskal(Graph<T> *g) {
    int i = 0;
    for (auto v : g->getVertexSet()) {
        v->setInfo(i++);
        v->setVisited(false);
    }
    // create a set for each vertex, for now every vertex is a SCC
    UFDS vset(g->getVertexSet().size());
    // The ordered set of all edges
    std::vector<Edge<T>> edges;
    for (auto v : g->getVertexSet()) {
        for (auto e : v->getAdj()) {
            if (!e->isSelected() && !e->getReverse()->isSelected()) {
                e->setSelected(true);
                e->getReverse()->setSelected(true);
                edges.push_back(e);
            }
        }
    }
    std::sort(edges.begin(),edges.end());
    for (auto e : edges) {
        if (vset.findSet(e.getOrig()) != vset.findSet(e.getDest())) {
            vset.linkSets(e.getOrig(),e.getDest());
        }
    }
    return g->getVertexSet();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

TEST(TP3_Ex2, test_kruskal) {
    Graph<int> graph = createMSTTestGraph<int>();
    std::vector<Vertex<int> *> res = kruskal(&graph);

    std::stringstream ss;
    for(const auto v : res) {
        ss << v->getInfo() << "<-";
        if ( v->getPath() != nullptr ) {
            ss << v->getPath()->getOrig()->getInfo();
        }
        ss << "|";
    }
    std::cout << ss.str() << std::endl;

    EXPECT_TRUE(isSpanningTree(res));
    EXPECT_EQ(spanningTreeCost(res), 11);
}

TEST(TP3_Ex2_performance, test_performance_kruskal) {
    //Change these const parameters as needed
    const int MIN_SIZE = 10;
    const int MAX_SIZE = 30; //Try with 100
    const int STEP_SIZE = 10;
    const int N_REPETITIONS = 50;
    for (int n = MIN_SIZE; n <= MAX_SIZE; n += STEP_SIZE) {
        Graph<int> g;
        generateRandomGridGraph(n, g);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= N_REPETITIONS; i++)
            kruskal(&g);
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        std::cout << "Processing grid (Kruskal) " << n << " x " << n << " average time (milliseconds)=" << (elapsed / N_REPETITIONS) << std::endl;
    }
}
