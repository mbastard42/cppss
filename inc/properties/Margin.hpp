#pragma once

#include <string>

#include "components/components.hpp"

namespace cppss {

    class Margin : public ASpacing {

        //  VARIABLES

        bool        _set;

        //  COPLIEN FORM

        public:     Margin();
        public:     Margin(std::string value);
        public:     Margin(const Margin & margin);
        public:     ~Margin();

        public:     const Margin & operator=(const Margin & margin);

        //  METHODS

        private:    void    init();
        public:     void    set(std::string value);
    };
}