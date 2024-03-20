#pragma once

#include <string>

#include "components.hpp"

namespace cppss {

    class ASpacing {

        //  VARIABLES

        bool        _set;

        //  COPLIEN FORM

        public:     ASpacing();
        public:     ASpacing(std::string value);
        public:     ASpacing(const ASpacing & spacing);
        public:     ~ASpacing();

        public:     const ASpacing & operator=(const ASpacing & spacing);

        //  METHODS

        private:    void    init();
        public:     void    set(std::string value);
    };
}