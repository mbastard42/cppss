#include "../inc/cppss.hpp"

cppss::CssFile::CssFile() {
    
    _path = "";
}

cppss::CssFile::CssFile(const std::string & path) {
    
    open(path);
}

cppss::CssFile::CssFile(const CssFile & file) { *this = file; }

cppss::CssFile::~CssFile() {
    
}

const cppss::CssFile & cppss::CssFile::operator=(const CssFile & file) {
    
    _path = file._path;
    _ids = file._ids;
    _classes = file._classes;
    
    return *this;
}

void cppss::CssFile::open(const std::string & path) {
    
    _path = path;
}

const std::string & cppss::CssFile::getPath() const { return _path; }

std::ostream & cppss::operator<<(std::ostream & os, const cppss::CssFile & file) {
    
    os << "CSS FILE: " << file.getPath() << std::endl;
    
    return os;
}