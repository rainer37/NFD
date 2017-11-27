#include "ptable_manager.hpp"

namespace nfd {

PTManager* PTManager::pt_manager = 0;

void
PTManager::getA() {
	std::cout << count++ << std::endl;
}

PTManager::PTManager(){
	count = 0;
	std::cout<<"PTable Manager Created, current count "<< count <<std::endl;
}

void 
PTManager::insert_pentry(const ndn::Name& name){
	p_table.insert(name);
}

void 
PTManager::insert_pentry(const ndn::Name& name, int privacy_count){
	p_table.insert(name, privacy_count);
}

}