#pragma once

#include <map>
#include <string>
#include <iostream>
#include <functional>

#include "CssFile.hpp"
#include "CssElem.hpp"
#include "HtmlElem.hpp"

namespace cppss {

    typedef std::function<void(int xpos, int ypos, unsigned char r, unsigned char g, unsigned char b, unsigned char a)> DrawingFunction;

    class HtmlPage {

        //  VARIABLES

        int                 _width, _height;
        int                 _startX, _startY;
        int                 _hoverX, _hoverY;

        CssElems            _ids, _classes;
        CssFiles            _cssFiles;
        DrawingFunction     _drawPixel;

        HtmlElem *          _head;
        Childs              _elems;

        //  METHODS
        
        public:     HtmlPage();
        public:     HtmlPage(int width, int height, DrawingFunction drawingPixelFunction);
        public:     HtmlPage(const HtmlPage & htmlPage);
        public:     ~HtmlPage();              

        //  OPERATORS

        public:     const HtmlPage & operator=(const HtmlPage & htmlPage);

        //  INITIALIZERS (must be set before body() and draw() are called)

        public:     void    size(int width, int height);
        public:     void    setDrawingFunction(DrawingFunction drawingPixelFunction);
        private:    void    passDown(const HtmlPage & page);

        //  OPTIONAL INITIALIZERS (can be set before or after body() and draw() are called)

        public:     void    addCssFile(const CssFile & file);
        public:     void    addCssFile(const std::string & path);
        public:     void    addCssId(const CssElem & cssId);
        public:     void    addCssClass(const CssElem & cssClass);

        //  DOM BUILDING METHODS

        public:     void        body(HtmlElem * head);
        public:     HtmlElem *  div(std::string ids, std::string classes, Childs elems = {});

        //  UPDATE AND DRAWING METHOD

        public:     void    scrollUp(int pixels);
        public:     void    scrollDown(int pixels);
        public:     void    scrollLeft(int pixels);
        public:     void    scrollRight( int pixels);
        public:     void    hover(int xpos, int ypos);
        public:     void    click(int xpos, int ypos);

        public:     void    draw() const;

        //  GETTERS

        public:     int         getWidth() const;
        public:     int         getHeight() const;
        public:     int         getStartX() const;
        public:     int         getStartY() const;
        public:     int         getHoverX() const;
        public:     int         getHoverY() const;
        public:     HtmlElem *  getHead() const;

    };

    std::ostream & operator<<(std::ostream & os, const HtmlPage & htmlPage);

} // namespace cppss
