#include "Screen.hh"

	// member functions definition
	inline char
	Screen::get(pos r, pos c) const {
		pos row = r * width;		// compute row location
		return contents[row + c];	// return char at given column
	}

	inline Screen&
	Screen::set(char c) {
		contents[cursor] = c;	// set the new val at the current cursor locat
		return *this;			// return this object as an lvalue
	}

	inline Screen&
	Screen::set(pos r, pos col, char ch) {
		contents[r * width + col] = ch;	// set specified location to given val
		return *this;
	}

	inline Screen&
	Screen::move(pos r, pos c) {
		pos row = r * width;	// compute row location
		cursor = row + c;		// move cursor to the col within that row
		return *this;			// return this obj as lvalue (bc ref)
	}

	inline Screen&
	Screen::display(std::ostream &os)
		{ do_display(os); return *this; }

	inline const Screen&
	Screen::display(std::ostream &os) const
		{ do_display(os); return *this; }

	inline void
	Screen::some_member() const {
		++access_ctr;
	}
