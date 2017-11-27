#ifndef NFD_DAEMON_TABLE_PTABLE_HPP
#define NFD_DAEMON_TABLE_PTABLE_HPP

//#include "core/common.hpp"
#include "ptable_entry.hpp"

#define DEFAULT_PRIVACY_COUNT 1 
#define DEFAULT_TABLE_SIZE 5

namespace nfd {
//namespace cs {

class Ptable : noncopyable {
private:
	PEntry* table;
	int p_size;
	int capacity;

public:
	Ptable();

	// insert PEntry with DEFAULT_PRIVACY_COUNT
	void insert(const Name& name);

	// insert PEntry with provided privacy sount;
	void insert(const Name& name, int privacy_count);

	// insert PEntry;
	void insert(PEntry pe);

	// check if the PEntry with name has privacy_count bigger than 0
	bool isPrivate(const Name& name) const;

	// return the privacy count of PEntry with name
	int get_pcount(const Name& name) const;

	// return the privacy count of PEntry with name string
	int get_pcount(std::string name) const;

	// return the PEntry with name
	PEntry* find_entry(const Name& name);

	// decrement the privacy of pentry with name;
	void dec_count(const Name& name);

};
//}	// ns cs
}   // ns nfd

#endif