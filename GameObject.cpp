#include "GameObject.hpp"
#include "App.hpp"
#include <gl\GL.h>

#include <cstdlib>
#include <cmath>

namespace Engine
{
    // Move this out to a Math 
    const float PI = 3.141592653;

    inline float wrap(float x, float min, float max)
    {
        if(x < min) return max - (min - x);
        if(x > max) return min + (x - max);
        return x;
    }

    GameObject::GameObject(float mass, float angle, float rotation)
        : m_mass(mass)
        , m_angle(angle)
        , m_rotation(rotation)
        , m_position(Engine::Math::Vector2::Origin)
        , m_velocity(Engine::Math::Vector2::Origin)
    {}

    void GameObject::ApplyImpulse(Engine::Math::Vector2 impulse, float angle)
    {
        if(m_mass > 0)
        {            
            m_velocity.x += (impulse.x / m_mass) * cosf((angle) * (PI / 180));
            m_velocity.y += (impulse.y / m_mass) * sinf((angle) * (PI / 180));
        }
    }

    void GameObject::Update(App* world, float deltaTime)
    {
        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

        // Calculations for wrap around        
        float halfWidth = world->GetWidth() / 2.0f;
        float halfHeight = world->GetHeight() / 2.0f;

        float worldMinX = -halfWidth;
        float worldMaxX = halfWidth;

        float worldMinY = -halfHeight;
        float worldMaxY = halfHeight;

        m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
        m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
    }

    void GameObject::Render()
    {
        glLoadIdentity();
        glTranslatef(m_position.x, m_position.y, 0.f);
        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_LINE_LOOP);
            std::vector<Engine::Math::Vector2>::iterator it = m_points.begin();
            for(; it != m_points.end(); ++it)
            {
                glVertex2f((*it).x, (*it).y);
            }
        glEnd();
    }
}