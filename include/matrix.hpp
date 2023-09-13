#include <iostream>
#include <armadillo>


arma::imat Matrix(std::vector<std::string> particles);

void fillMatrix(arma::imat &matrix, std::map<std::string, int> particle_index, std::vector<std::string> cf);
  
void findTriangles(const arma::imat& adjacencyMatrix);

