#pragma once

#include <string>
#include <vector>
#include <functional>

#include "CssElem.hpp"

namespace cppss {

    typedef std::function<void(int xpos, int ypos, unsigned char r, unsigned char g, unsigned char b, unsigned char a)> DrawingFunction;

    class HtmlElem {

        //  VARIABLES

        std::string         _tag, _id, _classes;
        CssElems            _style;
        
        HtmlElem *          _next;
        HtmlElem *          _prev;
        HtmlElem *          _child;
        HtmlElem *          _parent;

        //  METHODS

        public:     HtmlElem();
        public:     HtmlElem(const HtmlElem & elem);
        public:     HtmlElem(std::string tag, std::string id, std::string classes, std::vector<HtmlElem *> elems = {});
        public:     ~HtmlElem();

        //  OPERATORS

        public:     const HtmlElem & operator=(const HtmlElem & elem);

        public:     void    draw(DrawingFunction) const;

        //  SETTERS

        //  GETTERS

        public:     const std::string & getTag() const;
        public:     const std::string & getId() const;
        public:     const std::string & getClasses() const;

        public:     const HtmlElem * getNext() const;
        public:     const HtmlElem * getPrev() const;
        public:     const HtmlElem * getChild() const;
        public:     const HtmlElem * getParent() const;
    };
    
    std::ostream & operator<<(std::ostream & os, const HtmlElem & elem);

    typedef std::vector<HtmlElem *> Childs;

} // namespace cppss