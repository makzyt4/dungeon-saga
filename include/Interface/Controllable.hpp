#ifndef DS_INTERFACE_CONTROLLABLE_HPP
#define DS_INTERFACE_CONTROLLABLE_HPP

namespace ds {
    class Controllable {
    public:
        virtual void control() = 0;
    };
}

#endif // DS_INTERFACE_CONTROLLABLE_HPP
