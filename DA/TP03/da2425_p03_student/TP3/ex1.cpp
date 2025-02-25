// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "MSTTestAux.h"
#include "../data_structures/Graph.h"

template <typename T>
std::vector<Vertex<T> *> prim(Graph<T> *g) {
    auto v = g->getVertexSet();
    // Structure that will keep track and sort the tree using the Dist value
    MutablePriorityQueue<Vertex<T>> q;
    // All vertex belong to the NotVisited set
    // 2 sets exists and are completely disconnected, one being empty, the other all
    for (Vertex<T>* vertex : v) {
        vertex->setDist(INF); // Currently the distance is infinite since the other set is empty
        vertex->setPath(nullptr); // Since the sets are fully disconnected there is no path
        vertex->setVisited(false); // Set which set it belongs to
        q.insert(vertex);
    }
    Vertex<T>* front = v.front(); // Chosen starting vertex
    front->setVisited(true); // The first vertex has changed to the visited set
    front->setDist(0); // The distance from front to itself is 0
    // could be wrong WIP
    q.decreaseKey(front);

    while (!q.empty()) {
        // Get the vertex that currently has the smallest weight connection
        Vertex<T>* curv = q.extractMin();
        // change the current vertex to the Visited set
        curv->setVisited(true);
        // visit all adjacent nodes
        for (auto e : curv->getAdj()) {
            Vertex<T>* w = e->getDest();
            // check if the vertex has already transitioned and if we have found a better path to it
            if (!w->isVisited() && e->getWeight() < w->getDist()) {
                // set the new predecessor
                w->setPath(e);
                // set the new distance
                w->setDist(e->getWeight());
                // update the priority queue
                q.decreaseKey(w);
            }
        }
    }
    return g->getVertexSet();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

TEST(TP3_Ex1, test_prim) {
    Graph<int> graph = createMSTTestGraph<int>();
    std::vector<Vertex<int> *> res = prim(&graph);

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

TEST(TP3_Ex1_performance, test_performance_prim) {
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
            prim(&g);
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        std::cout << "Processing grid (Prim) " << n << " x " << n << " average time (milliseconds)=" << (elapsed / N_REPETITIONS) << std::endl;
    }
}
