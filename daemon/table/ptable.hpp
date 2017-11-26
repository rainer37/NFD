#ifndef NFD_DAEMON_TABLE_PTABLE_HPP
#define NFD_DAEMON_TABLE_PTABLE_HPP

//#include "core/common.hpp"

namespace nfd {
namespace cs {

class Ptable : noncopyable {
private:
	int a = 2;

public:
	Ptable(){}
	void insert(const Name& name, int privacy_count);
	bool isPrivate(const Name& name);
	int getA() { return a; }

};
}	// ns cs
}   // ns nfd

#endif