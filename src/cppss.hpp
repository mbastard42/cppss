#pragma once

#include <map>
#include <string>
#include <iostream>
#include <functional>
#include <initializer_list>

#include "logger.hpp"

namespace CPPSS {

    class CssElem {

        //  VARIABLES

        protected:  std::string     _name;

        //  METHODS

        public:     CssElem();
        public:     ~CssElem();

    };

    typedef CssElem                             CssId;
    typedef CssElem                             CssClass;
    typedef std::map<std::string, CssId>        CssIds;
    typedef std::map<std::string, CssClass>     CssClasses;

    class CssFile {

        //  VARIABLES

        std::string     _path;

        CssIds          _ids;
        CssClasses      _classes;

        //  METHODS

        public:     CssFile();
        public:     CssFile(const std::string & path);
        public:     CssFile(const CssFile & file);
        public:     ~CssFile();

        public:     const CssFile & operator=(const CssFile & file);

        //  GETTERS

        public:     const std::string & getPath() const;

    };

    typedef std::function<void(int xpos, int ypos, unsigned char r, unsigned char g, unsigned char b, unsigned char a)> DrawingFunction;
    
    class DomElem {

        //  VARIABLES

        DrawingFunction         _drawingFunction;

        // CssIds              _ids;
        // CssClasses          _classes;
        public: std::string         _ids;
        CssElem                 _style;

        DomElem *               _next;
        DomElem *               _prev;
        DomElem *               _child;
        DomElem *               _parent;

        //  METHODS

        public:     DomElem();
        public:     DomElem(const DomElem & elem);
        public:     DomElem(std::string ids, std::string classes, std::vector<DomElem *> elems = {});
        public:     ~DomElem();

        public:     const DomElem & operator=(const DomElem & elem);

        public:     void    draw() const;

        //  SETTERS

        // public:     void    next(DomElem next);

        //  GETTERS

        public:     const DomElem * getNext() const;
        public:     const DomElem * getPrev() const;
        public:     const DomElem * getChild() const;
        public:     const DomElem * getParent() const;
    };

    typedef std::map<std::string, CssFile>       CssFiles;

    class Html {

        //  VARIABLES

        int                     _width;
        int                     _height;

        CssIds                  _ids;
        CssClasses              _classes;
        CssFiles                _cssFiles;
        DrawingFunction         _drawingFunction;

        DomElem *               _head;
        std::vector<DomElem *>  _elems;

        //  METHODS

        public:     Html();
        public:     Html(const Html & html);
        public:     ~Html();

        public:     const Html & operator=(const Html & html);

        public:     void    size(int width, int height);
        public:     void    setDrawingFunction(DrawingFunction drawingFunction);

        public:     void    addCssFile(const CssFile & file);
        public:     void    addCssFile(const std::string & path);
        // public:     void    addCssId(const CssId & cssId);
        // public:     void    addCssClass(const CssClass & cssClass);

        public:     void        body(DomElem * head);
        public:     DomElem *   div(std::string ids, std::string classes, std::vector<DomElem *> elems = {});

        public:     void    draw();
    };

    std::ostream & operator<<(std::ostream & os, const CssElem & elem);
    std::ostream & operator<<(std::ostream & os, const CssFile & file);
    std::ostream & operator<<(std::ostream & os, const DomElem & elem);
    std::ostream & operator<<(std::ostream & os, const Html & html);

} // namespace CPPSS
