#ifndef NFD_DAEMON_TABLE_PTABLE_MANAGER_HPP
#define NFD_DAEMON_TABLE_PTABLE_MANAGER_HPP

#include "ptable.hpp"

namespace nfd {

class PTManager{

	static PTManager* pt_manager;
	Ptable p_table;

private:

	PTManager();

public:
	static PTManager* getInstance() {
		if(!pt_manager)
			pt_manager = new PTManager();
		return pt_manager;
	}

	void insert_pentry(const ndn::Name& name);

	void insert_pentry(const ndn::Name& name, int privacy_count);

	PEntry* find_pentry(const Name& name);

	bool isNamePrivate(const ndn::Name& name);

	void dec_privacy_count(const Name& name);

	void remove_entry(const Name& name);
};

} // nfd
#endif