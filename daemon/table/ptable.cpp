#include "ptable.hpp"

namespace nfd {

Ptable::Ptable() {
	table = new PEntry[DEFAULT_TABLE_SIZE];
	capacity = DEFAULT_TABLE_SIZE;
	next = 0;
	Name n1 = Name("hello");
	Name n3 = Name("world");
	insert(n1);
	insert(n3);
	if(isPrivate(n1)){
		std::cout<<"HIT"<<std::endl;
	} else {
		std::cout<<"MISS"<<std::endl;		
	}
}

bool	
Ptable::isPrivate(const Name& name) {
	PEntry * p = find_entry(name);
	if(p)
		return p->get_pri_count() > 0;
	return false;
}

void 
Ptable::insert(const Name& name, int privacy_count){
	PEntry pe = PEntry(name, privacy_count);
	insert(pe);
}

void 
Ptable::insert(std::string name) {
	Name n = Name(name);
	insert(name, DEFAULT_PRIVACY_COUNT);
}


void 
Ptable::insert(const Name& name){
	insert(name,DEFAULT_PRIVACY_COUNT);
}

void 
Ptable::insert(PEntry pe){
	PEntry * p = find_entry(pe.getName());
	if(!p){
		if(next == capacity){
			next = 0;
		}
		table[next++] = pe;
	}
}

PEntry*
Ptable::find_entry(const Name& name){
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
	if(pe){
		std::cout << "Found lah" << std::endl;
		pe->dec_count();
	}
	else
		std::cout << "Cannot find lah" << std::endl;
}

void
Ptable::print() {
	for(int i = 0; i<capacity; i++) {
		//if(table[i].get_pri_count() !=0) {
			std::cout<<table[i].getName() << " " << table[i].get_pri_count() << " " << table[i].isValid() << std::endl;
		//}
	}
}
}