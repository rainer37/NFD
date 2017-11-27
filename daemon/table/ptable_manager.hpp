#ifndef NFD_DAEMON_TABLE_PTABLE_MANAGER_HPP
#define NFD_DAEMON_TABLE_PTABLE_MANAGER_HPP

#include "ptable.hpp"
namespace nfd {
//namespace cs {

class PTManager{
	static PTManager* pt_manager;
	int count;
	Ptable p_table;
private:
	PTManager();
public:
	static PTManager* getInstance() {
		if(!pt_manager)
			pt_manager = new PTManager();
		return pt_manager;
	}

	void getA();

	void insert_pentry(const ndn::Name& name);

	void insert_pentry(const ndn::Name& name, int privacy_count);

	bool isNamePrivate(const ndn::Name& name);

};

//}
}
#endif