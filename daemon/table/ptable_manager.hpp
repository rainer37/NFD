#ifndef NFD_DAEMON_TABLE_PTABLE_MANAGER_HPP
#define NFD_DAEMON_TABLE_PTABLE_MANAGER_HPP

#include "ptable.hpp"

namespace nfd {

class PTManager{

	static PTManager* pt_manager;
	std::vector<std::string> history_list(); 
	Ptable p_table;

private:

	PTManager();

public:
	// return the singleton
	static PTManager* getInstance() {
		if(!pt_manager)
			pt_manager = new PTManager();
		return pt_manager;
	}

	// insert PEntry.
	void insert_pentry(const ndn::Name& name, std::string nonce);

	void insert_pentry(std::string name, std::string nonce);

	void insert_pentry(const ndn::Name& name, int privacy_count, std::string nonce);

	// return the PEntry with matching name
	PEntry* find_pentry(const Name& name, std::string nonce);

	// check if the name is in table and is private.
	bool isNamePrivate(const ndn::Name& name, std::string nonce);

	// remove entry with name.
	void remove_entry(const Name& name);

	// print the content of the tabel;
	void print_table();

	// invalidate the pentry when the cache line has been evicted.
	void invalidate_pentry(const Name& name);

	bool wasPrivate(const Name& name);

	void invalidate_all(const Name& name);
};

} // nfd
#endif