#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <functional>

#include "CssElem.hpp"
#include "HtmlElem.hpp"
#include "tags/tags.hpp"

namespace cppss {

    typedef std::function<void(int xpos, int ypos, unsigned char r, unsigned char g, unsigned char b, unsigned char a)> DrawingFunction;

    class HtmlPage {

        //  VARIABLES

        int                             _width, _height;
        int                             _startX, _startY;
        int                             _hoverX, _hoverY;
        DrawingFunction                 _draw;
        std::vector<HtmlElem *>         _elems;
        std::map<std::string, CssElem>  _selectors;

        //  COPLIEN FORM

        public:     HtmlPage();
        public:     HtmlPage(int width, int height, DrawingFunction drawingPixelFunction);
        public:     HtmlPage(const HtmlPage & page);
        public:     ~HtmlPage();              

        public:     const HtmlPage & operator=(const HtmlPage & page);

        //  INITIALIZERS (must be set before body() and draw() are called)

        private:    void    init();
        public:     void    size(int width, int height);
        public:     void    setDrawingFunction(DrawingFunction drawingPixelFunction);
        private:    void    passDown() const;

        //  OPTIONAL INITIALIZERS (can be set before or after body() and draw() are called)

        public:     void    addCssFile(const std::string & path);
        public:     void    addCssElem(const CssElem * elem);

        //  DOM BUILDING METHODS

        public:     void        body(HtmlElem * head);
        public:     HtmlElem *  div(std::string id, std::string classes, std::vector<HtmlElem *> elems = {});

        //  UPDATE AND DRAWING METHOD

        public:     void    scrollUp(int pixels);
        public:     void    scrollDown(int pixels);
        public:     void    scrollLeft(int pixels);
        public:     void    scrollRight( int pixels);
        public:     void    hover(int xpos, int ypos);
        public:     void    hold(int xpos, int ypos);
        public:     void    release(int xpos, int ypos);
        public:     void    click(int xpos, int ypos);

        public:     void    draw() const;

        //  GETTERS

        public:     int     getWidth() const;
        public:     int     getHeight() const;
        public:     int     getStartX() const;
        public:     int     getStartY() const;
        public:     int     getHoverX() const;
        public:     int     getHoverY() const;

        public:     HtmlElem *                              getHead() const;
        public:     const std::map<std::string, CssElem> &  getSelectors() const;
    };

    std::ostream & operator<<(std::ostream & os, const cppss::HtmlPage & page);

} // namespace cppss
