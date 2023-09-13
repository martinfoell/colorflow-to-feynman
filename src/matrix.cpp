#include "../include/matrix.hpp"


// Function to find triangles in a graph represented by an Armadillo imat
void findTriangles(const arma::imat& adjacencyMatrix) {
    int numNodes = adjacencyMatrix.n_rows;

    // Loop through each node in the graph
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (adjacencyMatrix(i, j)) {  // If there is an edge between nodes i and j
                // Check for a third node k that forms a triangle with nodes i and j
                for (int k = j + 1; k < numNodes; k++) {
                    if (adjacencyMatrix(i, k) && adjacencyMatrix(j, k)) {
                        // Nodes i, j, and k form a triangle
                        std::cout << "Triangle found: " << i << " " << j << " " << k << std::endl;
                    }
                }
            }
        }
    }
}

