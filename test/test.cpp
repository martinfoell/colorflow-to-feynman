#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
  {
    std::vector<std::string> in = {"q1", "Q1"};
    std::vector<std::string> inter= {"g"};
    std::vector<std::string> out= {"q2", "Q2"};
    
    int n = in.size()+inter.size()+out.size();    
    std::cout << "n = " << n << std::endl;
    // Create a new vector to store the concatenated strings
    std::vector<std::string> cf1 = {"q1", "g", "Q1"};
    std::vector<std::string> cf2 = {"Q2", "g", "q2"};

    std::vector<std::string> particles;
    particles.reserve( in.size() + inter.size() + out.size() ); // preallocate memory
    particles.insert( particles.end(), in.begin(), in.end() );
    particles.insert( particles.end(), inter.begin(), inter.end() );
    particles.insert( particles.end(), out.begin(), out.end() );
    
    std::map<std::string, int> particle_index;
    for (size_t i = 0; i < particles.size(); ++i) {
      particle_index[particles[i]] = i;
    }


    std::cout << "q1: " << particle_index["q1"] << std::endl;
    std::cout << "Q1: " << particle_index["Q1"] << std::endl;
    std::cout << "g: " << particle_index["g"] << std::endl;
    std::cout << "q2: " << particle_index["q2"] << std::endl;
    std::cout << "Q2: " << particle_index["Q2"] << std::endl;

    arma::imat A = arma::imat(n+1, n+1); //Initialize matrix but don't fill.
    
    for (size_t i = 0; i < cf1.size()-1; ++i) {
      A(particle_index[cf1[i]],particle_index[cf1[i+1]]) = 1;
      A(particle_index[cf1[i+1]],particle_index[cf1[i]]) = -1;
    }

    for (size_t i = 0; i < cf2.size()-1; ++i) {
      A(particle_index[cf2[i]],particle_index[cf2[i+1]]) = 1;
      A(particle_index[cf2[i+1]],particle_index[cf2[i]]) = -1;
    }
    
    std::cout << A << std::endl;

    for (string i: particles)
      std::cout << i << ' ';

    std::cout << in.size() << std::endl;
    // std::cout << inter.size() << std::endl;
    // std::cout << out.size() << std::endl;
  return 0;
  }
