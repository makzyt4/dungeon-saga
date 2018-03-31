#ifndef DS_SCREEN_HPP
#define DS_SCREEN_HPP

#include "Drawable.hpp"

namespace ds {
    class Screen
        : public Controllable,
          public Drawable,
          public Updatable {

    };
}

#endif
