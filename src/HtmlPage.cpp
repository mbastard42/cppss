#include "../inc/cppss.hpp"

cppss::HtmlPage::HtmlPage() {

    _width = 0;
    _height = 0;
    _startX = 0;
    _startY = 0;
    _hoverX = 0;
    _hoverY = 0;
    _drawPixel = nullptr;
    _head = nullptr;
}

cppss::HtmlPage::HtmlPage(int width, int height, DrawingFunction drawingPixelFunction) {

    _width = width;
    _height = height;
    _startX = 0;
    _startY = 0;
    _hoverX = 0;
    _hoverY = 0;
    _drawPixel = drawingPixelFunction;
    _head = nullptr;
    passDown(*this);
}

cppss::HtmlPage::HtmlPage(const HtmlPage & htmlPage) { *this = htmlPage; }

cppss::HtmlPage::~HtmlPage() {

    for (size_t i = 0; i < _elems.size(); i++)
        delete _elems[i];
    _elems.clear();
}

const cppss::HtmlPage & cppss::HtmlPage::operator=(const HtmlPage & htmlPage) {

    _width = htmlPage._width;
    _height = htmlPage._height;
    _ids = htmlPage._ids;
    _classes = htmlPage._classes;
    _cssFiles = htmlPage._cssFiles;
    _drawPixel = htmlPage._drawPixel;
    _head = htmlPage._head;

    return *this;
}

void cppss::HtmlPage::size(int width, int height) {

    _width = width;
    _height = height;
}

void cppss::HtmlPage::setDrawingFunction(DrawingFunction drawingPixelFunction) {

    _drawPixel = drawingPixelFunction;
    passDown(*this);
}

void cppss::HtmlPage::passDown(const HtmlPage & page) {

    (void)page;
}

void cppss::HtmlPage::addCssFile(const std::string & path) {

    _cssFiles[path] = CssFile(path);
}

void cppss::HtmlPage::addCssFile(const CssFile & file) {

    _cssFiles[file.getPath()] = file;
}

void cppss::HtmlPage::addCssId(const CssElem & cssId) {

    if (_ids.find(cssId.getName()) == _ids.end())
        _ids[cssId.getName()] = cssId;
    else
        _ids[cssId.getName()].merge(cssId);
}

void cppss::HtmlPage::addCssClass(const CssElem & cssClass) {

    if (_classes.find(cssClass.getName()) == _classes.end())
        _classes[cssClass.getName()] = cssClass;
    else
        _classes[cssClass.getName()].merge(cssClass);
}

void cppss::HtmlPage::body(HtmlElem * head) { _head = head; }

cppss::HtmlElem * cppss::HtmlPage::div(std::string ids, std::string classes, Childs elems) {
    
    HtmlElem * elem = new HtmlElem("div", ids, classes, elems);

    _elems.push_back(elem);
    return elem;
}

void cppss::HtmlPage::scrollUp(int pixels) { _startY -= pixels; }
void cppss::HtmlPage::scrollDown(int pixels) { _startY += pixels; }
void cppss::HtmlPage::scrollLeft(int pixels) { _startX -= pixels; }
void cppss::HtmlPage::scrollRight(int pixels) { _startX += pixels; }

void cppss::HtmlPage::hover(int x, int y) {

    _hoverX = x;
    _hoverY = y;
}

void cppss::HtmlPage::click(int x, int y) {

    (void)x;
    (void)y;
}

void cppss::HtmlPage::draw() const {

    if (_drawPixel)
        for (size_t i = 0; i < _elems.size(); i++)
            _elems[i]->draw(_drawPixel);
}

int cppss::HtmlPage::getWidth() const { return _width; }
int cppss::HtmlPage::getHeight() const { return _height; }
int cppss::HtmlPage::getStartX() const { return _startX; }
int cppss::HtmlPage::getStartY() const { return _startY; }
int cppss::HtmlPage::getHoverX() const { return _hoverX; }
int cppss::HtmlPage::getHoverY() const { return _hoverY; }
cppss::HtmlElem * cppss::HtmlPage::getHead() const { return _head; }

std::ostream & cppss::operator<<(std::ostream & os, const HtmlPage & htmlPage) {

    os << "<!DOCTYPE html>" << std::endl;
    os << "<html>" << std::endl;

    os << "<head>" << std::endl;
    // styles
    os << "</head>" << std::endl; 

    os << "<body>" << std::endl;
    if (htmlPage.getHead())
        os << *htmlPage.getHead();
    os << "</body>" << std::endl;

    os << "</html>" << std::endl;

    return os;
}
