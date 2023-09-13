#include <iostream>
#include <armadillo>
#include <vector>
#include <string>
#include "../include/matrix.hpp"
#include "../include/particles.hpp"


int main()
  {
    std::vector<std::string> in = {"q1", "Q2"};
    std::vector<std::string> inter= {"g"};
    std::vector<std::string> out= {"q3", "Q4"};
    
    int n = in.size()+inter.size()+out.size();    
    std::cout << "n = " << n << std::endl;
    
    // Create a new vector to store the concatenated strings
    std::vector<std::string> cf1 = {"q1", "g", "Q2"};
    std::vector<std::string> cf2 = {"Q4", "g", "q3"};


    std::vector<std::string> particles = Particles(in, inter, out);

    std::map<std::string, int> particle_index = Particles_index(particles);
    
    std::vector<std::string> quarks = Quarks(particles);

    std::map<std::string, int> quark_index = Quarks_index(quarks, particle_index);



    
    // Print the first characters
    std::cout << "First characters:" << std::endl;
    for (std::string c : quarks) {
        std::cout << c << " ";
	// std::cout << particle_index[c] << " ";
    }
    std::cout << std::endl;
    

    arma::imat A = arma::imat(n, n); //Initialize matrix but don't fill.
    size_t numCols = A.n_cols;
    size_t numRows = A.n_rows;
    
    for (size_t i = 0; i < cf1.size()-1; ++i) {
      A(particle_index[cf1[i]],particle_index[cf1[i+1]]) = 1;
      A(particle_index[cf1[i+1]],particle_index[cf1[i]]) = -1;
    }

    for (size_t i = 0; i < cf2.size()-1; ++i) {
      A(particle_index[cf2[i]],particle_index[cf2[i+1]]) = 1;
      A(particle_index[cf2[i+1]],particle_index[cf2[i]]) = -1;
    }
    
    // Specify the row you want to iterate over (e.g., row 1)
    // size_t targetRow = 0;
    // string target = particles[targetRow];

    int targetValue = 0;

    // Search for the key associated with the target value
    std::string foundKey = "";

    for (const auto& pair : particle_index) {
        if (pair.second == targetValue) {
            foundKey = pair.first;
            break; // Exit the loop once the key is found
        }
    }
    std::cout << "foundKey = " << foundKey << std::endl;
    
    for (size_t i = 0; i < quarks.size(); i++) {
      int targetRow =  quark_index[quarks[i]];
      std::cout << "targetRow = " << targetRow << std::endl;
      for (size_t col = 0; col < numCols; ++col) {
        if (A(targetRow, col) == 1.0) {
	  int targetCol = col;
	  std::cout << "targetCol = " << targetCol << std::endl;
	  for (size_t col = 0; col < numCols; ++col) {
	    if (A(col, targetCol) == -1) {
	      std::cout << col << std::endl;
	      std::string target = particles[targetRow];
	      std::string target2 = particles[col];
	      
	      std::string key1;
	      std::string key2;
	      
	      if (std::find(cf1.begin(), cf1.end(), target) != cf1.end()) {
		key1 = "cf1";
	      }
	      else if (std::find(cf2.begin(), cf2.end(), target) != cf2.end()) {
		key1 = "cf2";
	      }
	      
	      if (std::find(cf1.begin(), cf1.end(), target2) != cf1.end()) {
		key2 = "cf1";
	      }
	      else if (std::find(cf2.begin(), cf2.end(), target2) != cf2.end()) {
		key2 = "cf2";
	      }
	      if (key1 != key2) {
		A(targetRow, col) = -1;
		A(col, targetRow) = -1;
		std::cout << "A(" << targetRow << "," << col << ") = " << A(targetRow, col) << std::endl;
		std::cout << "key1 = " << key1 << std::endl;
		std::cout << "key2 = " << key2 << std::endl;}
	    }
	  }
        }
      }
    }


    std::cout << std::endl;
    std::cout << A << std::endl;
    arma::imat absA = arma::abs(A);
    std::cout << absA << std::endl;

    for (std::string i: particles)
      std::cout << i << ' ';
    std::cout <<  std::endl;
    findTriangles(absA);
    std::cout <<  std::endl;
  return 0;
  }


    // std::cout << "quark_index = " << quark_index["q1"] << std::endl;
    // std::cout << "quark_index = " << quark_index["Q2"] << std::endl;
    // std::cout << "quark_index = " << quark_index["q3"] << std::endl;
    // std::cout << "quark_index = " << quark_index["Q4"] << std::endl;

    // std::cout << "particle_index[\"q1\"] = " << particle_index["q1"] << std::endl;
    // std::cout << "particle_index[\"g\"] = " << particle_index["g"] << std::endl;
    // std::cout << "particle_index[\"Q2\"] = " << particle_index["Q2"] << std::endl;
    // std::cout << "particle_index[\"q3\"] = " << particle_index["q3"] << std::endl;
    // std::cout << "particle_index[\"Q4\"] = " << particle_index["Q4"] << std::endl;

