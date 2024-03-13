#pragma once

#include <map>
#include <vector>
#include <string>

namespace cppss {

    class CssElem {

        //  VARIABLES

        protected:  std::string     _name;

        //  METHODS

        public:     CssElem();
        public:     CssElem(const CssElem & cssElem);
        public:     ~CssElem();

        //  OPERATORS

        public:     const CssElem & operator=(const CssElem & cssElem);

        public:     void    merge(const CssElem & cssElem);

        //  GETTERS

        public:     const std::string     getName() const;
    };

    std::ostream & operator<<(std::ostream & os, const CssElem & elem);

    typedef std::map<std::string, CssElem>      CssElems;

} // namespace cppss