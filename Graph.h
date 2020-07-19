#ifndef H_GRAPHS
#define H_GRAPHS
#include "Dot.h"
#include <list>
class Graph {
public:
	virtual ~Graph() {}

	virtual void AddArc(int from, int to) = 0;
	virtual bool DeleteArc(int from, int to) = 0;
	virtual bool HasArc(int from, int to) const = 0;
	virtual void AddV(int v) = 0;
	virtual bool DeleteVertex(int v) = 0;

	virtual int CountVertex() const = 0;

	virtual System::String^ getView() = 0;
	virtual void ToListbox(System::Windows::Forms::ListBox^ listbox) = 0;

};
#endif
