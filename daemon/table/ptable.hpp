#ifndef NFD_DAEMON_TABLE_PTABLE_HPP
#define NFD_DAEMON_TABLE_PTABLE_HPP

#include "ptable_entry.hpp"
//#include <time.h>

#define DEFAULT_PRIVACY_COUNT 1 
#define DEFAULT_TABLE_SIZE 5

namespace nfd {

class Ptable : noncopyable {
private:
	PEntry* table;
	int capacity;
	int next;
public:
	Ptable();

	// insert PEntry with DEFAULT_PRIVACY_COUNT
	void insert(const Name& name, std::string nonce);

	void insert(std::string name, std::string nonce);

	// insert PEntry with provided privacy sount;
	void insert(const Name& name, int privacy_count, std::string nonce);

	// insert PEntry;
	void insert(PEntry pe);

	// check if the PEntry with name has privacy_count bigger than 0
	bool isPrivate(const Name& name, std::string nonce);

	// return the privacy count of PEntry with name
	int get_pcount(const Name& name) const;

	// return the privacy count of PEntry with name string
	int get_pcount(std::string name) const;

	// return the PEntry with name
	PEntry* find_entry(const Name& name, std::string nonce);

	// print the content of table;
	void print();

	// invalidate the entry with name;
	void invalidate(const Name& name);

	PEntry* get(int index);

	int size();
};
}   // ns nfd

#endif