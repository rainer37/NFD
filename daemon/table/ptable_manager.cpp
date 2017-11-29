#include "ptable_manager.hpp"

namespace nfd {

PTManager* PTManager::pt_manager = 0;

PTManager::PTManager(){
	//std::cout<<"PTable Manager Created..."<<std::endl;
}

void 
PTManager::insert_pentry(const Name& name, std::string nonce){
	p_table.insert(name, nonce);
}

void 
PTManager::insert_pentry(std::string name, std::string nonce){
	p_table.insert(name, nonce);
}

void 
PTManager::insert_pentry(const Name& name, int privacy_count, std::string nonce){
	p_table.insert(name, privacy_count, nonce);
}

bool
PTManager::isNamePrivate(const Name& name, std::string nonce){
	return p_table.isPrivate(name, nonce);
}

bool
PTManager::isNamePrivate(const Name& name){
	return p_table.isPrivate(name);
}

PEntry*
PTManager::find_pentry(const Name& name, std::string nonce){
	return p_table.find_entry(name, nonce);
}

void
PTManager::print_table() {
	p_table.print();
}

void 
PTManager::invalidate_all(const Name& name){
	for(int i = 0; i < p_table.size(); i++) {
		PEntry* pe = p_table.get(i);
		if(pe->getName() == name)
			pe->invalidate_myself();
	}
}

bool 
PTManager::peer_check(const Name& name, std::string nonce){
	return p_table.find_name_with_diff_nonce(name, nonce);
}


}