#include "../include/matrix.hpp"


arma::imat Matrix(std::vector<std::string> particles) {
  int n = particles.size();
  arma::imat matrix = arma::imat(n, n, arma::fill::zeros);
  // arma::imat matrix = arma::imat(n, n); //Initialize matrix but don't fill.
  return matrix;
}


void fillMatrix(arma::imat &matrix, std::map<std::string, int> particle_index, std::vector<std::string> cf) {
    for (size_t i = 0; i < cf.size()-1; ++i) {
      matrix(particle_index[cf[i]],particle_index[cf[i+1]]) = 1;
      matrix(particle_index[cf[i+1]],particle_index[cf[i]]) = -1;
    }

}

void addColorFlow(arma::imat &matrix, std::map<std::string, int> particle_index, const std::vector<std::vector<std::string>>& cfVectors) {
    for (const std::vector<std::string>& cf : cfVectors) {
        for (size_t i = 0; i < cf.size() - 1; ++i) {
            matrix(particle_index[cf[i]], particle_index[cf[i + 1]]) = 1;
            matrix(particle_index[cf[i + 1]], particle_index[cf[i]]) = -1;
        }
	std::string result;
	for (size_t i = 0; i < cf.size(); ++i) {
	  result += cf[i];
	  if (i < cf.size() - 1) {
            result += " -> ";
	  }
	}
	std::cout << "added color flow: " << result  << std::endl;	
    }
}

std::string findColorflow(const std::vector<std::vector<std::string>>& cfVectors, const std::vector<std::string>& particles, int targetRow) {
    std::string colorflow = "";
    std::string target = particles[targetRow];

    for (size_t i = 0; i < cfVectors.size(); ++i) {
        const std::vector<std::string>& cf = cfVectors[i];
        if (std::find(cf.begin(), cf.end(), target) != cf.end()) {
            colorflow = "cf" + std::to_string(i + 1); // Create the colorflow label dynamically
            break;
        }
    }

    return colorflow;
}

void addGluonFlow(arma::imat &A, std::vector<std::string> particles, std::vector<std::string> quarks, std::map<std::string, int> quark_index, std::vector<std::vector<std::string>> cfVectors, std::function<std::string(const std::vector<std::vector<std::string>>&, const std::vector<std::string>&, int)> findColorflow) {
  size_t numCols = A.n_cols;
  for (size_t i = 0; i < quarks.size(); i++) {
    // index and name of the quark
    int quark1_index =  quark_index[quarks[i]];
    std::string quark1 = particles[quark1_index];

    //loop over the particels
    for (size_t col = 0; col < numCols; ++col) {
      // check if incomming quark to a gluon is in the column
      if (A(quark1_index, col) == 1) {
	  
	int gluon_index = col;
	std::string gluon = particles[gluon_index];

	for (size_t col = 0; col < numCols; ++col) {
	    
	  // check if outgoing quark from a gluon is in the column
	  if (A(col, gluon_index) == -1) {
	      
	    int quark2_index = col;
	    std::string quark2 = particles[quark2_index];
	      
	    // find the color flow of the quark
	    std::string colorflow1 = findColorflow( cfVectors, particles, quark1_index);
	    std::string colorflow2 = findColorflow( cfVectors, particles, quark2_index);
	    // //check if the quarks are in different color flows
	    if (colorflow1 != colorflow2) {
	      // add a vertex between the quarks if they are in different color flows
	      A(quark1_index, quark2_index) = -1;
	      A(quark2_index, quark1_index) = -1;
	      std::cout << "added gluon flow: " << quark2 << " -> " << quark1 << std::endl;
	    }
	  }
	}
      }
    }
  }
}


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

