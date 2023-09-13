#include "../include/particles.hpp"


std::vector<std::string> Particles(std::vector<std::string> in, std::vector<std::string> inter, std::vector<std::string> out ) {
  std::vector<std::string> particles_vec;
  particles_vec.reserve( in.size() + inter.size() + out.size() ); // preallocate memory
  particles_vec.insert( particles_vec.end(), in.begin(), in.end() );
  particles_vec.insert( particles_vec.end(), inter.begin(), inter.end() );
  particles_vec.insert( particles_vec.end(), out.begin(), out.end() );
  return particles_vec;
}


std::map<std::string, int> Particles_index(std::vector<std::string> particles) {
  std::map<std::string, int> particle_index;
  for (size_t i = 0; i < particles.size(); ++i) {
    particle_index[particles[i]] = i;
  }
  return particle_index;
}


std::vector<std::string> Quarks(std::vector<std::string> particles){
  std::vector<std::string> quarks;
    for (const std::string& str : particles) {
        if (!str.empty()) { // Make sure the string is not empty
	  if(str[0] == 'q' || str[0] == 'Q'){
            quarks.push_back(str);}
        }
    }
    return quarks;
}

std::map<std::string, int> Quarks_index(std::vector<std::string> quarks, std::map<std::string, int> particle_index){
    std::map<std::string, int> quark_index;
    for (size_t i = 0; i < quarks.size(); i++) {
      quark_index[quarks[i]] = particle_index[quarks[i]];
    }
    return quark_index;
}


void printParticles(std::string Type, std::vector<std::string> particletype) {
  std::string result;
  for (size_t i = 0; i < particletype.size(); ++i) {
    result += particletype[i];
    if (i < particletype.size() - 1) {
      result += ", ";
    }
  }
  std::cout << Type << result << std::endl;
}

void printColorFlows(std::vector<std::vector<std::string>> cfVectors) {
  for (size_t i = 0; i < cfVectors.size(); ++i) {
    const std::vector<std::string>& cf = cfVectors[i];
    std::string result;
    for (size_t i = 0; i < cf.size(); ++i) {
      result += cf[i];
      if (i < cf.size() - 1) {
	result += " -> ";
      }
    }
    std::cout << "color flow " << i+1 << ": " << result  << std::endl;	
  }
}

