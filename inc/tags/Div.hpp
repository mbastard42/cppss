#pragma once

#include "../HtmlElem.hpp"

namespace cppss {

    class Div : public HtmlElem {

        public:     Div();
        public:     Div(std::string id, std::string classes, std::vector<HtmlElem *> elems = {});
        public:     Div(const Div & div);
        public:     ~Div();

        public:     const Div & operator=(const Div & div);
    };

} // namespace cppss
