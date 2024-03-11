#include "cppss.hpp"

CPPSS::DomElem::DomElem() {

    _next = nullptr;
    _prev = nullptr;
    _child = nullptr;
    _parent = nullptr;
}

CPPSS::DomElem::DomElem(std::string ids, std::string classes, std::vector<DomElem *> elems) {

    _ids = ids;
    _next = nullptr;
    _prev = nullptr;
    _child = nullptr;
    _parent = nullptr;

    if (!elems.size())
        return;

    _child = elems.front();
    _child->_parent = this;

    for (size_t i = 1; i < elems.size(); i++) {

        elems[i - 1]->_next = elems[i];
        elems[i]->_prev = elems[i - 1];
        elems[i]->_parent = this;
    }
}

CPPSS::DomElem::DomElem(const DomElem & elem) { *this = elem; }

CPPSS::DomElem::~DomElem() {
    
}

const CPPSS::DomElem & CPPSS::DomElem::operator=(const DomElem & elem) {
    
    _drawingFunction = elem._drawingFunction;
    _ids = elem._ids;
    _next = elem._next;
    _prev = elem._prev;
    _child = elem._child;
    _parent = elem._parent;

    return *this;
}

void CPPSS::DomElem::draw() const {
    
    // if (_drawingFunction) {
        
    //     _drawingFunction(0, 0, 0, 0, 0, 0);
    // }
}

const CPPSS::DomElem * CPPSS::DomElem::getNext() const { return _next; }
const CPPSS::DomElem * CPPSS::DomElem::getPrev() const { return _prev; }
const CPPSS::DomElem * CPPSS::DomElem::getChild() const { return _child; }
const CPPSS::DomElem * CPPSS::DomElem::getParent() const { return _parent; }

