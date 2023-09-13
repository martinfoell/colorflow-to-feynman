#include <iostream>
#include <armadillo>


arma::imat Matrix(std::vector<std::string> particles);

void fillMatrix(arma::imat &matrix, std::map<std::string, int> particle_index, std::vector<std::string> cf);

void addColorFlow(arma::imat &matrix, std::map<std::string, int> particle_index, const std::vector<std::vector<std::string>>& cfVectors);

std::string findColorflow(const std::vector<std::vector<std::string>>& cfVectors, const std::vector<std::string>& particles, int targetRow);

void addGluonFlow(arma::imat &A, std::vector<std::string> particles, std::vector<std::string> quarks, std::map<std::string, int> quark_index, std::vector<std::vector<std::string>> cfVectors, std::function<std::string(const std::vector<std::vector<std::string>>&, const std::vector<std::string>&, int)> findColorflow);
  
  
void findTriangles(const arma::imat& adjacencyMatrix);

