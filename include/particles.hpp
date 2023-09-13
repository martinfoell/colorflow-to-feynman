#include <armadillo>
#include <vector>
#include <string>

std::vector<std::string> Particles(std::vector<std::string> in, std::vector<std::string> inter, std::vector<std::string> out );

std::map<std::string, int> Particles_index(std::vector<std::string> particles);

std::vector<std::string> Quarks(std::vector<std::string> particles);

std::map<std::string, int> Quarks_index(std::vector<std::string> quarks, std::map<std::string, int> particle_index);
  
