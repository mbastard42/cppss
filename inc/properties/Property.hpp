#pragma once

#include <string>

namespace cppss {

    class Property {

        //  VARIABLES

        bool        _set;

        //  COPLIEN FORM

        public:     Property();
        public:     Property(std::string value);
        public:     Property(const Property & property);
        public:     ~Property();

        public:     const Property & operator=(const Property & property);

        //  METHODS

        private:    void    init();
        public:     void    set(std::string value);
    };
}