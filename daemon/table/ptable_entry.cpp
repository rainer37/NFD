#include "ptable_entry.hpp"
namespace nfd {
namespace cs {

PEntry::PEntry(){
	m_name = Name();
	pri_count = 0;
	valid = false;
	std::cout<< "hello im default pentry" << std::endl;
}

PEntry::PEntry(const Name& name, int init_count){
	m_name = name;
	pri_count = init_count;
	valid = true;
	std::cout<< "hello im pentry" << std::endl;
}

bool 
PEntry::operator<(const PEntry& other) const{
	return m_name < other.getName();
}

void 
PEntry::invalidate_myself(){
	valid = false;
}

}
}