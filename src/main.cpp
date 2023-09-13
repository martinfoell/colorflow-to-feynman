#include <iostream>
#include <armadillo>
#include <vector>
#include <string>
#include "../include/matrix.hpp"
#include "../include/particles.hpp"
#include "../include/readfile.hpp"

void printVector(std::vector<std::string> v) {
  std::string result;
  for (size_t i = 0; i < v.size(); ++i) {
      result += v[i];
      if (i < v.size() - 1) {
	result += ", ";
      }
    }
    std::cout << "vector: " << result << std::endl;
}

void addParticlesFromFile(std::string filename, std::string vectorname, std::vector<std::string> &particles) {
  std::map<std::string, std::vector<std::string>> data = readNamedCommaSeparatedValues(filename);
  auto it = data.find(vectorname);
  if (it != data.end()) {
    const std::vector<std::string>& values = it->second;
    for (const std::string& value : values) {
      particles.push_back(value);
    }
  } else {
    std::cout << "Name: " << vectorname << " does not exist in the map." << std::endl;
  }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1; // Return an error code
    }

    std::string filename = argv[1];
    // std::string filename = "../example.txt"; // Replace with your file's name

    std::vector<std::string> in;
    std::vector<std::string> inter;
    std::vector<std::string> out;
 
    std::vector<std::string> cf1;
    std::vector<std::string> cf2;
    std::vector<std::string> cf3;
    std::vector<std::string> cf4;
    std::vector<std::vector<std::string>> cfVectors;

    addParticlesFromFile(filename, "in", in);
    addParticlesFromFile(filename, "inter", inter);
    addParticlesFromFile(filename, "out", out);
    addParticlesFromFile(filename, "cf1", cf1);
    addParticlesFromFile(filename, "cf2", cf2);
    addParticlesFromFile(filename, "cf3", cf3);
    addParticlesFromFile(filename, "cf4", cf4);

    cfVectors.push_back(cf1);
    cfVectors.push_back(cf2);
    cfVectors.push_back(cf3);
    cfVectors.push_back(cf4);
    
    // remove empty vectors from cfVectors
    cfVectors.erase(std::remove_if(cfVectors.begin(), cfVectors.end(), 
				   [](const std::vector<std::string>& innerVector) {
				     return innerVector.empty();
				   }), 
		    cfVectors.end());
    
    std::vector<std::string> particles = Particles(in, inter, out);

    std::map<std::string, int> particle_index = Particles_index(particles);
    
    std::vector<std::string> quarks = Quarks(particles);

    std::map<std::string, int> quark_index = Quarks_index(quarks, particle_index);
    
    arma::imat A = Matrix(particles);
    
    std::cout << " " << std::endl;
    printParticles("incomming particlse; ", in);
    printParticles("intermediate particlse: ", inter);
    printParticles("outgoing particlse: ", out);
    std::cout << "Total particels in Feyman diagram: " << particles.size() << std::endl;
    std::cout << " " << std::endl;
    printColorFlows(cfVectors);
    std::cout << " " << std::endl;
    addColorFlow(A, particle_index, cfVectors);
    addGluonFlow(A, particles, quarks, quark_index, cfVectors, findColorflow);

    arma::imat absA = arma::abs(A);
    std::vector<std::vector<int>> vertices;
    std::cout << " " << std::endl;
    findVertices(absA, vertices, particle_index, findParticle);

    
    // std::cout << absA << std::endl;

  return 0;
  }



    // std::vector<std::string> in = {"q1", "q2"};
    // std::vector<std::string> inter= {"q7", "g8", "q9"};
    // std::vector<std::string> out= {"g3", "q4", "q5", "g6"};
    
    // std::vector<std::string> cf1 = {"q1", "g8", "q9", "g6"};
    // std::vector<std::string> cf2 = {"q2", "g8", "q7", "g3"};
    // std::vector<std::string> cf3 = {"g3", "q4"};
    // std::vector<std::string> cf4 = {"g6", "q5"};
    // std::vector<std::vector<std::string>> cfVectors = {cf1, cf2, cf3, cf4};
