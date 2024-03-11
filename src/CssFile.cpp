#include "cppss.hpp"

CPPSS::CssFile::CssFile() {
    
    _path = "";
}

CPPSS::CssFile::CssFile(const std::string & path) {
    
    _path = path;
}

CPPSS::CssFile::CssFile(const CssFile & file) { *this = file; }

CPPSS::CssFile::~CssFile() {
    
}

const CPPSS::CssFile & CPPSS::CssFile::operator=(const CssFile & file) {
    
    _path = file._path;
    _ids = file._ids;
    _classes = file._classes;
    
    return *this;
}

const std::string & CPPSS::CssFile::getPath() const { return _path; }
