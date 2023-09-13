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
    
    std::vector<std::string> cf1 = {"q1", "g", "Q2"};
    std::vector<std::string> cf2 = {"Q4", "g", "q3"};

    std::vector<std::vector<std::string>> cfVectors = {cf1, cf2};

    
    std::vector<std::string> particles = Particles(in, inter, out);

    std::map<std::string, int> particle_index = Particles_index(particles);
    
    std::vector<std::string> quarks = Quarks(particles);

    std::map<std::string, int> quark_index = Quarks_index(quarks, particle_index);
    
    arma::imat A = Matrix(particles);
    
    addColorFlow(A, particle_index, cfVectors);
    addGluonFlow(A, particles, quarks, quark_index, cfVectors, findColorflow);


    // std::cout << std::endl;
    // std::cout << A << std::endl;
    arma::imat absA = arma::abs(A);
    std::cout << absA << std::endl;

    for (std::string i: particles)
      std::cout << i << ' ';
    std::cout <<  std::endl;
    findTriangles(absA);
    std::cout <<  std::endl;
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
    
  return 0;
  }

    // Specify the row you want to iterate over (e.g., row 1)
    // size_t targetRow = 0;
    // string target = particles[targetRow];

    // std::cout << "quark_index = " << quark_index["q1"] << std::endl;
    // std::cout << "quark_index = " << quark_index["Q2"] << std::endl;
    // std::cout << "quark_index = " << quark_index["q3"] << std::endl;
    // std::cout << "quark_index = " << quark_index["Q4"] << std::endl;

    // std::cout << "particle_index[\"q1\"] = " << particle_index["q1"] << std::endl;
    // std::cout << "particle_index[\"g\"] = " << particle_index["g"] << std::endl;
    // std::cout << "particle_index[\"Q2\"] = " << particle_index["Q2"] << std::endl;
    // std::cout << "particle_index[\"q3\"] = " << particle_index["q3"] << std::endl;
    // std::cout << "particle_index[\"Q4\"] = " << particle_index["Q4"] << std::endl;

    // Print the first characters
//     std::cout << "First characters:" << std::endl;
//     for (std::string c : quarks) {
//         std::cout << c << " ";
// 	// std::cout << particle_index[c] << " ";
// n    }
//     std::cout << std::endl;
    // for (size_t i = 0; i < quarks.size(); i++) {
    //   // index and name of the quark
    //   int quark1_index =  quark_index[quarks[i]];
    //   std::string quark1 = particles[quark1_index];

    //   //loop over the particels
    //   for (size_t col = 0; col < numCols; ++col) {
    //     // check if incomming quark to a gluon is in the column
    //     if (A(quark1_index, col) == 1) {
	  
    // 	  int gluon_index = col;
    // 	  std::string gluon = particles[gluon_index];

    // 	  for (size_t col = 0; col < numCols; ++col) {
	    
    // 	    // check if outgoing quark from a gluon is in the column
    // 	    if (A(col, gluon_index) == -1) {
	      
    // 	      int quark2_index = col;
    // 	      std::string quark2 = particles[quark2_index];
	      
    // 	      // find the color flow of the quark
    // 	      std::string colorflow1 = findColorflow( cfVectors, particles, quark1_index);
    // 	      std::string colorflow2 = findColorflow( cfVectors, particles, quark2_index);
    // 	      // //check if the quarks are in different color flows
    // 	      if (colorflow1 != colorflow2) {
    // 		// add a vertex between the quarks if they are in different color flows
    // 		A(quark1_index, quark2_index) = -1;
    // 		A(quark2_index, quark1_index) = -1;
    // 		std::cout << "gluon flow " << quark2 << " -> " << quark1 << " added" << std::endl;
    // 	      }
    // 	    }
    // 	  }
    //     }
    //   }
    // }
