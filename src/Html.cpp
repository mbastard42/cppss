#include "cppss.hpp"

CPPSS::Html::Html() {

    _width = 0;
    _height = 0;
    _drawingFunction = nullptr;
    _head = nullptr;
}

CPPSS::Html::Html(const Html & html) { *this = html; }

CPPSS::Html::~Html() {

    for (size_t i = 0; i < _elems.size(); i++)
        delete _elems[i];
    _elems.clear();
}

const CPPSS::Html & CPPSS::Html::operator=(const Html & html) {

    _width = html._width;
    _height = html._height;
    _ids = html._ids;
    _classes = html._classes;
    _cssFiles = html._cssFiles;
    _drawingFunction = html._drawingFunction;
    _head = html._head;

    return *this;
}

void CPPSS::Html::size(int width, int height) {

    _width = width;
    _height = height;
}

void CPPSS::Html::setDrawingFunction(DrawingFunction drawingFunction) {

    _drawingFunction = drawingFunction;
}

void CPPSS::Html::addCssFile(const std::string & path) {

    _cssFiles[path] = CssFile(path);
}

void CPPSS::Html::addCssFile(const CssFile & file) {

    _cssFiles[file.getPath()] = file;
}

void CPPSS::Html::body(DomElem * head) { _head = head; }

CPPSS::DomElem * CPPSS::Html::div(std::string ids, std::string classes, std::vector<DomElem *> elems) {
    
    DomElem * elem = new DomElem(ids, classes, elems);

    _elems.push_back(elem);
    return elem;
}

void CPPSS::Html::draw() {

    // if (_drawingFunction) {

        const DomElem * elem = _head;

        while (elem) {

            elem->draw();
            logger.log(elem->_ids);
            if (elem->_parent)
                logger.log(elem->_parent->_ids);
            logger.log("\n");
            elem = elem->getChild() ? elem->getChild() : elem->getNext();
        }
    // }
}