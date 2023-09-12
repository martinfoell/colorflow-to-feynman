#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
  {
    std::vector<std::string> in = {"q1", "Q1"};
    std::vector<std::string> inter= {"g"};
    std::vector<std::string> out= {"q2,Q2"};
    int n = in.size()+inter.size()+out.size();    

    // Create a new vector to store the concatenated strings
    
    std::vector<std::string> particles;
    particles.reserve( in.size() + out.size() ); // preallocate memory
    particles.insert( particles.end(), in.begin(), in.end() );
    particles.insert( particles.end(), inter.begin(), inter.end() );
    particles.insert( particles.end(), out.begin(), out.end() );
    


    arma::imat A = arma::imat(n, n); //Initialize matrix but don't fill.
    A(0, 0) = 1;
    A(1, 1) = 2;
    A(2, 2) = 3;


    for (string i: particles)
      std::cout << i << ' ';

    std::cout << in.size() << std::endl;
    // std::cout << inter.size() << std::endl;
    // std::cout << out.size() << std::endl;
  return 0;
  }
