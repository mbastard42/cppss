#pragma once

#include <map>
#include <vector>
#include <string>

#include "properties/properties.hpp"

namespace cppss {

    class CssElem {

        //  VARIABLES

        std::string     _selector;

        //  COPLIEN FORM

        public:     CssElem();
        public:     CssElem(const std::string & selector);
        public:     CssElem(const std::string & selector, std::string properties);
        public:     CssElem(const CssElem & elem);
        public:     ~CssElem();

        public:     const CssElem & operator=(const CssElem & elem);

        //  METHODS

        private:    void    init();
        public:     void    merge(const CssElem & elem);

        //  SETTERS

        public:     void    setSelector(const std::string & selector);

        public:     void    width(std::string value);
        public:     void    height(std::string value);
        public:     void    margin(std::string value);
        public:     void    padding(std::string value);
        public:     void    border(std::string value);

        //  GETTERS

        public:     const std::string     getSelector() const;
    };

    std::ostream & operator<<(std::ostream & os, const CssElem & attribute);
    
} // namespace cppss
