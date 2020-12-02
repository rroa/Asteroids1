#pragma once

#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

// Asteroids
#include "Vector2.hpp"
#include <vector>

namespace Engine
{    
    class App;
    class GameObject
    {        
        public:  
            /* ==========================
            * PUBLIC FUNCTIONS
            * ==========================*/
            GameObject(float mass, float angle, float rotation);
            void Update(App* world, float deltaTime);
            void Render();
            void ApplyImpulse(Engine::Math::Vector2 impulse, float angle);
            void Teleport(float _x, float _y);
        protected:                        
            /* ==========================
            * MEMBERS
            * ==========================*/
            std::vector<Engine::Math::Vector2> m_points;
            Engine::Math::Vector2 m_position;
            Engine::Math::Vector2 m_velocity;
            float m_angle;
            float m_mass;
            float m_rotation;
    };
}

#endif