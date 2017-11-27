#include "ptable.hpp"

namespace nfd {
//namespace cs {


Ptable::Ptable() {
	table = new PEntry[DEFAULT_TABLE_SIZE];
	capacity = DEFAULT_TABLE_SIZE;
	p_size = 0;

	Name n1 = Name("hello");
	Name n2 = Name("c++");
	Name n3 = Name("world");
	insert(n1);
	insert(n2);
	insert(n3);
	if(this->isPrivate(n1)){
		std::cout<<"HIT"<<std::endl;
	} else {
		std::cout<<"MISS"<<std::endl;		
	}
}

bool	
Ptable::isPrivate(const Name& name) const{
	if(!p_size) return false;
	for(int i = 0; i<capacity; i++) {
		if(table[i].isValid() && table[i].getName() == name) {
			return &table[i];
		}
	}
	return false;
}

void 
Ptable::insert(const Name& name, int privacy_count){
	PEntry pe = PEntry(name, privacy_count);
	insert(pe);
}

void 
Ptable::insert(const Name& name){
	insert(name,DEFAULT_PRIVACY_COUNT);
}

void 
Ptable::insert(PEntry pe){
	if(p_size == capacity)
		p_size = -1;
	table[p_size] = pe;
	p_size++;
}

PEntry*
Ptable::find_entry(const Name& name){
	if(!p_size) return NULL;
	for(int i = 0; i<capacity; i++) {
		if(table[i].isValid() && table[i].getName() == name) {
			return &table[i];
		}
	}
	return NULL;
}

void 
Ptable::dec_count(const Name& name){
	PEntry * pe = find_entry(name);
	if(pe)
		pe->dec_count();
}

//}
}