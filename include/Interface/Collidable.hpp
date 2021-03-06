#ifndef DS_INTERFACE_COLLIDABLE_HPP
#define DS_INTERFACE_COLLIDABLE_HPP

namespace ds {
    class Collidable {
    public:
        virtual bool isCollidable() const = 0;
    };
}

#endif // DS_INTERFACE_COLLIDABLE_HPP
