#include "../inc/cppss.hpp"

cppss::HtmlElem::HtmlElem() {

    _tag = "";
    _id = "";
    _classes = "";

    _style = {};

    _next = nullptr;
    _prev = nullptr;
    _child = nullptr;
    _parent = nullptr;
}

cppss::HtmlElem::HtmlElem(std::string tag, std::string id, std::string classes, std::vector<HtmlElem *> elems) {

    _tag = tag;
    _id = id;
    _classes = classes;

    _style = {};

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

cppss::HtmlElem::HtmlElem(const HtmlElem & elem) { *this = elem; }

cppss::HtmlElem::~HtmlElem() {
    
}

const cppss::HtmlElem & cppss::HtmlElem::operator=(const HtmlElem & elem) {
    
    _tag = elem._tag;
    _id = elem._id;
    _classes = elem._classes;

    _next = elem._next;
    _prev = elem._prev;
    _child = elem._child;
    _parent = elem._parent;

    return *this;
}

void cppss::HtmlElem::draw(DrawingFunction drawPixel) const {
    
    (void)drawPixel;
}

const std::string & cppss::HtmlElem::getTag() const { return _tag; }
const std::string & cppss::HtmlElem::getId() const { return _id; }
const std::string & cppss::HtmlElem::getClasses() const { return _classes; }

const cppss::HtmlElem * cppss::HtmlElem::getNext() const { return _next; }
const cppss::HtmlElem * cppss::HtmlElem::getPrev() const { return _prev; }
const cppss::HtmlElem * cppss::HtmlElem::getChild() const { return _child; }
const cppss::HtmlElem * cppss::HtmlElem::getParent() const { return _parent; }

std::ostream & cppss::operator<<(std::ostream & os, const HtmlElem & elem) {

    static int depth = 0;
    std::string indent = "  ";

    for (int i = 0; i < depth; i++)
        indent += indent;

    std::cout << indent << "<" << elem.getTag() << " id=\"" << elem.getId() << "\" class=\"" << elem.getClasses() << "\">" << std::endl;
    
    for (const HtmlElem * head = elem.getChild(); head; head = head->getChild()) {
        
        depth++;
        os << *head;
    }
    
    std::cout << indent << "</" << elem.getTag() << ">" << std::endl;

    if (elem.getNext())
        os << *elem.getNext();
        
    depth--;
    return os;
}
