#pragma once

#ifndef BULLET_HPP
#define BULLET_HPP

// Asteroids
#include "GameObject.hpp"

namespace Engine
{
    class Bullet : public GameObject
    {
        public:
            Bullet();
            void Update(float deltaTime);
            void Render();            
    };
}

#endif