#include "../inc/cppss.hpp"

cppss::CssElem::CssElem() { _init(); }

cppss::CssElem::CssElem(const std::string & selector) { 
    
    _init();
    _selector = selector;
}

cppss::CssElem::CssElem(const std::string & selector, std::string properties) {

    _init();
    _selector = selector;
    (void)properties;
}

cppss::CssElem::CssElem(const CssElem & CssElem) { *this = CssElem; }

cppss::CssElem::~CssElem() {}

const cppss::CssElem & cppss::CssElem::operator=(const CssElem & CssElem) {
    
    _selector = CssElem._selector;
    
    return *this;
}

void cppss::CssElem::_init() {

    _selector = "";
}

void cppss::CssElem::merge(const CssElem & CssElem) {

    (void)CssElem;   
}

void cppss::CssElem::setSelector(const std::string & selector) { _selector = selector; }

const std::string cppss::CssElem::getSelector() const { return _selector; }

std::ostream & cppss::operator<<(std::ostream & os, const cppss::CssElem & CssElem) {
    
    std::string indent = "  ";

    os << indent << indent << indent << CssElem.getSelector() << " {" << std::endl;

    os << indent << indent << indent  << "}" << std::endl;
    
    return os;
}
