#include "../inc/cppss.hpp"

cppss::HtmlElem::HtmlElem() : _style("inline") { init(); }

cppss::HtmlElem::HtmlElem(std::string tag, std::string id, std::string classes, std::vector<HtmlElem *> elems) : _style("inline") {

    init();
    _tag = tag;
    _selectors.push_back("#" + ((id.find(' ') != std::string::npos) ? id.substr(0, id.find(' ')) : id));

    for (std::string classe = classes; !classe.empty();) {

        std::string::size_type space = classe.find(' ');
        if (classe.substr(0, space).size())
            _selectors.push_back("." + classe.substr(0, (space != std::string::npos) ? space : classe.size()));
        classe.erase(0, (space != std::string::npos) ? space + 1 : classe.size());
    }
    
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

cppss::HtmlElem::~HtmlElem() {}

const cppss::HtmlElem & cppss::HtmlElem::operator=(const HtmlElem & elem) {
    
    _tag = elem._tag;
    _next = elem._next;
    _prev = elem._prev;
    _child = elem._child;
    _parent = elem._parent;

    for (size_t i = 0; i < elem._selectors.size(); i++)
        _selectors.push_back(elem._selectors[i]);

    return *this;
}

void cppss::HtmlElem::init() {

    _tag = "";
    _next = nullptr;
    _prev = nullptr;
    _child = nullptr;
    _parent = nullptr;
    _bodyHeight = _bodyWidth = 0;
}

void cppss::HtmlElem::resize(int width, int height) {

    _bodyWidth = width;
    _bodyHeight = height;
}

void cppss::HtmlElem::draw(DrawingFunction drawPixel) const {
    
    (void)drawPixel;
}

const std::string & cppss::HtmlElem::getTag() const { return _tag; }
const std::vector<std::string> & cppss::HtmlElem::getSelectors() const { return _selectors; }

const cppss::HtmlElem * cppss::HtmlElem::getNext() const { return _next; }
const cppss::HtmlElem * cppss::HtmlElem::getPrev() const { return _prev; }
const cppss::HtmlElem * cppss::HtmlElem::getChild() const { return _child; }
const cppss::HtmlElem * cppss::HtmlElem::getParent() const { return _parent; }

std::ostream & cppss::operator<<(std::ostream & os, const HtmlElem & elem) {

    static int      depth = 0;
    std::string     indent = "  ";

    for (int i = 0; i <= depth; i++)
        indent += "  ";

    std::string id = elem.getSelectors().front();
    os << indent << "<" << elem.getTag() << " id=\"" << id.erase(0, 1) << "\" class=\"";

    for (size_t i = 1; i < elem.getSelectors().size(); i++) {

        std::string classe = elem.getSelectors()[i];
        os << classe.erase(0, 1);
        if (i < elem.getSelectors().size() - 1)
            os << " ";
    }
    os << "\">" << std::endl;
    
    if (elem.getChild()) {

        depth++;
        os << *elem.getChild();
        depth--;
    }

    os << indent << "</" << elem.getTag() << ">" << std::endl;
    
    if (elem.getNext())
        os << *elem.getNext();

    return os;
}
