#include "ptable_entry.hpp"
namespace nfd {
//namespace cs {

PEntry::PEntry(){
	m_name = Name();
	pri_count = 0;
	valid = false;
}

PEntry::PEntry(const Name& name, int init_count){
	m_name = name;
	pri_count = init_count;
	valid = true;
}

bool 
PEntry::operator<(const PEntry& other) const{
	return m_name < other.getName();
}

void 
PEntry::invalidate_myself(){
	valid = false;
}

//}
}