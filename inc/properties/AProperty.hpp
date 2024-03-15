#pragma once

class AProperty {

    public:     AProperty();
    public:     AProperty(const AProperty & prop);
    public:     virtual ~AProperty() = 0;

    public:     const AProperty & operator=(const AProperty & prop);
};