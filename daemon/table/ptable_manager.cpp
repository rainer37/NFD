#include "ptable_manager.hpp"

namespace nfd {

PTManager* PTManager::pt_manager = 0;

PTManager::PTManager(){
	std::cout<<"PTable Manager Created..."<<std::endl;
}

void 
PTManager::insert_pentry(const Name& name){
	p_table.insert(name);
}

void 
PTManager::insert_pentry(const Name& name, int privacy_count){
	p_table.insert(name, privacy_count);
}

bool
PTManager::isNamePrivate(const Name& name){
	return p_table.isPrivate(name);
}

void 
PTManager::dec_privacy_count(const Name& name){
	p_table.dec_count(name);
}

PEntry*
PTManager::find_pentry(const Name& name){
	return p_table.find_entry(name);
}

}