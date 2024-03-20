#include "../../inc/cppss.hpp"

cppss::Div::Div() : HtmlElem() {}

cppss::Div::Div(std::string id, std::string classes, std::vector<HtmlElem *> elems) : HtmlElem("div", id, classes, elems) {}

cppss::Div::Div(const Div & div) : HtmlElem(div) { (void)div; }

const cppss::Div & cppss::Div::operator=(const Div & div) { 
    
    HtmlElem::operator=(div);
    return *this;
}

cppss::Div::~Div() {}