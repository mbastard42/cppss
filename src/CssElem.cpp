#include "../inc/cppss.hpp"

cppss::CssElem::CssElem() {
    
}

cppss::CssElem::CssElem(const CssElem & cssElem) { *this = cssElem; }

cppss::CssElem::~CssElem() {
    
}

const cppss::CssElem & cppss::CssElem::operator=(const CssElem & cssElem) {
    
    _name = cssElem._name;
    
    return *this;
}

void cppss::CssElem::merge(const CssElem & cssElem) {

    (void)cssElem;   
}

const std::string cppss::CssElem::getName() const {
    
    return _name;
}

std::ostream & cppss::operator<<(std::ostream & os, const cppss::CssElem & elem) {
    
    os << elem.getName();
    
    return os;
}