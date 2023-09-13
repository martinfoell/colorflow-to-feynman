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
