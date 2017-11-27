#include "ptable.hpp"

namespace nfd {
namespace cs {


Ptable::Ptable() {
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
	if (p_size == 0) return false;

	std::cout<<"CHECKING PRIVACY "<< table.size() <<std::endl;
	std::set<PEntry>::iterator it;
	for (it = table.begin(); it != table.end(); it++) {
		Name target = (*it).getName();
		std::cout << "?? " << target << std::endl;
		if (target == name)
			return true;
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
	table.insert(pe);
	p_size++;
}

}
}