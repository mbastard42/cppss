#pragma once

#include <string>
#include <vector>
#include <functional>

#include "CssElem.hpp"

namespace cppss {

    typedef std::function<void(int xpos, int ypos, unsigned char r, unsigned char g, unsigned char b, unsigned char a)> DrawingFunction;

    class HtmlElem {

        //  VARIABLES

        int                         _bodyWidth, _bodyHeight;
        HtmlElem                    *_next, *_prev, *_child, *_parent;
        CssElem                     _style;
        std::string                 _tag;
        std::string                 _id;
        std::vector<std::string>    _classes;

        //  COPLIEN FORM

        public:     HtmlElem();
        public:     HtmlElem(const HtmlElem & elem);
        public:     HtmlElem(std::string tag, std::string id, std::string classes, std::vector<HtmlElem *> elems = {});
        public:     ~HtmlElem();

        public:     const HtmlElem & operator=(const HtmlElem & elem);

        //  METHODS

        private:    void    init();
        public:     void    resize(int width, int height);
        public:     void    draw(DrawingFunction drawPixel) const;

        //  GETTERS

        public:     const HtmlElem *    getNext() const;
        public:     const HtmlElem *    getPrev() const;
        public:     const HtmlElem *    getChild() const;
        public:     const HtmlElem *    getParent() const;

        public:     const std::string &                 getTag() const;
        public:     const std::string &                 getId() const;
        public:     const std::vector<std::string> &    getClasses() const;
    };
    
    std::ostream & operator<<(std::ostream & os, const HtmlElem & elem);

} // namespace cppss
