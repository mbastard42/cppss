#pragma once

#include <map>
#include <string>

#include "CssElem.hpp"

namespace cppss {

        class CssFile {

        //  VARIABLES

        std::string     _path;

        CssElems        _ids;
        CssElems        _classes;

        //  METHODS

        public:     CssFile();
        public:     CssFile(const std::string & path);
        public:     CssFile(const CssFile & file);
        public:     ~CssFile();

        public:     const CssFile & operator=(const CssFile & file);

        public:     void    open(const std::string & path);

        //  GETTERS

        public:     const std::string & getPath() const;
    };
    
    std::ostream & operator<<(std::ostream & os, const CssFile & file);

    typedef std::map<std::string, CssFile>  CssFiles;

} // namespace cppss