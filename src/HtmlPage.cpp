#include "../inc/cppss.hpp"

cppss::HtmlPage::HtmlPage() { init(); }

cppss::HtmlPage::HtmlPage(int width, int height, DrawingFunction drawingPixelFunction) {

    init();
    size(width, height);
    setDrawingFunction(drawingPixelFunction);
}

cppss::HtmlPage::HtmlPage(const HtmlPage & page) { *this = page; }

cppss::HtmlPage::~HtmlPage() {

    for (size_t i = 0; i < _elems.size(); i++)
        delete _elems[i];
    _elems.clear();
    _selectors.clear();
}

const cppss::HtmlPage & cppss::HtmlPage::operator=(const HtmlPage & page) {

    size(page._width, page._height);
    setDrawingFunction(page._draw);
    return *this;
}

void cppss::HtmlPage::init() {

    _draw = nullptr;
    _width = _height = _startX = _startY = _hoverX = _hoverY = 0;
}

void cppss::HtmlPage::size(int width, int height) {

    if (_width != width || _height != height) {

        _width = width;
        _height = height;
        for (size_t i = 0; i < _elems.size(); i++)
            _elems[i]->resize(width, height);
    }
}

void cppss::HtmlPage::setDrawingFunction(DrawingFunction drawingPixelFunction) { _draw = drawingPixelFunction; }

void cppss::HtmlPage::passDown() const {

    for (size_t i = 0; i < _elems.size(); i++) {

        
    }
}

void cppss::HtmlPage::addCssFile(const std::string & path) {

    std::ifstream file(path);

    if (file.is_open()) {
            
        std::string line, name, params;
        while (std::getline(file, line)) {
            
            while (!line.find(' ') || !line.find('\t'))
                line.erase(0, 1);
                
            if (line.size() && !name.empty())
                params += line + '\n';

            if (params.empty()) {

                name = line;
                if (name.find(' ') != std::string::npos)
                    name.erase(name.find(' '), name.size());
                if (name.find('\t') != std::string::npos)
                    name.erase(name.find('\t'), name.size());
                if (name.find('{') != std::string::npos)
                    name.erase(name.find('{'), name.size());
            }

            if (line.find('}') != std::string::npos) {
                
                params.erase(params.find('}'), params.size());
                if (params[params.size() - 1] == '\n')
                    params.erase(params.size() - 1, 1);

                if (_selectors.find(name) == _selectors.end())
                    _selectors[name] = CssElem(name, params);
                else
                    _selectors[name].merge(CssElem(name, params));

                params.clear();
                name.clear();
            }
        }

        file.close();
        passDown();

    } else  
        std::cerr << "cppss::HtmlPage::addFile(" << path << "): Could not open file" << std::endl;
}

void cppss::HtmlPage::addCssElem(const CssElem * elem) {

    std::string selector = elem->getSelector();

    if (_selectors.find(selector) == _selectors.end())
        _selectors[selector] = *elem;
    else
        _selectors[selector].merge(*elem);

    passDown();
}

void cppss::HtmlPage::body(HtmlElem * head) { _elems.push_back(new HtmlElem(*head)); }

cppss::HtmlElem * cppss::HtmlPage::div(std::string id, std::string classes, std::vector<HtmlElem *> elems) {
    
    _elems.push_back(new Div(id, classes, elems));
    return _elems.back();
}

void cppss::HtmlPage::scrollUp(int pixels) { _startY -= pixels; }
void cppss::HtmlPage::scrollDown(int pixels) { _startY += pixels; }
void cppss::HtmlPage::scrollLeft(int pixels) { _startX -= pixels; }
void cppss::HtmlPage::scrollRight(int pixels) { _startX += pixels; }

void cppss::HtmlPage::hover(int x, int y) {

    _hoverX = x;
    _hoverY = y;
}

void cppss::HtmlPage::hold(int x, int y) {

    (void)x;
    (void)y;
}

void cppss::HtmlPage::release(int x, int y) {

    (void)x;
    (void)y;
}

void cppss::HtmlPage::click(int x, int y) {

    hold(x, y);
    release(x, y);
}

void cppss::HtmlPage::draw() const {

    if (!_draw)
        std::cerr << "Drawing function not set" << std::endl;
    else
        for (size_t i = 0; i < _elems.size(); i++)
            _elems[i]->draw(_draw);
}

int cppss::HtmlPage::getWidth() const { return _width; }
int cppss::HtmlPage::getHeight() const { return _height; }
int cppss::HtmlPage::getStartX() const { return _startX; }
int cppss::HtmlPage::getStartY() const { return _startY; }
int cppss::HtmlPage::getHoverX() const { return _hoverX; }
int cppss::HtmlPage::getHoverY() const { return _hoverY; }

cppss::HtmlElem * cppss::HtmlPage::getHead() const { return _elems.back(); }
const std::map<std::string, cppss::CssElem> & cppss::HtmlPage::getSelectors() const { return _selectors; }

std::ostream & cppss::operator<<(std::ostream & os, const HtmlPage & HtmlPage) {

    std::string indent = "  ";

    os << "<!DOCTYPE html>" << std::endl;
    os << "<html>" << std::endl;

    os << indent << "<head>" << std::endl;
    os << indent << indent << "<style>" << std::endl;
    for (const auto & it : HtmlPage.getSelectors())
        os << it.second;
    os << indent << indent << "</style>" << std::endl;
    os << indent << "</head>" << std::endl;
    os << indent << "<body>" << std::endl;
    if (HtmlPage.getHead())
        os << *HtmlPage.getHead();
    os << indent << "</body>" << std::endl;
    os << "</html>" << std::endl;

    return os;
}
