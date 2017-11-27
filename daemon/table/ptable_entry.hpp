#ifndef NFD_DAEMON_TABLE_PTABLE_ENTRY_HPP
#define NFD_DAEMON_TABLE_PTABLE_ENTRY_HPP

namespace nfd {
//namespace cs {
class PEntry {
private:
	Name m_name;
	int pri_count;
	bool valid;

public:

	// default constructor;
	PEntry();

	// construct entry from a name and desired privacy count;
	PEntry(const Name& name, int init_count = 1);

	// turn the entry into invalid;
	void invalidate_myself();

	// return the name associated with entry;
	const Name& getName() const { return m_name; }

	// return current privacy count;
	int get_pri_count() { return pri_count; }

	// check if valid;
	bool isValid() { return valid; }

	// decrement the privacy count;
	void dec_count() { 
		std::cout << "Called lah" << std::endl;
		pri_count--; 
	}

	bool operator<(const PEntry& other) const;
};

//}
}

#endif