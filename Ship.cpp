#include "Ship.hpp"

#include <gl\GL.h>

// STL
#include <iostream>
#include <cmath>

namespace Engine
{
    // TODO: RR: Move this to a lib
    const float PI = 3.141592653;

    // TODO: RR: Get this out of here!
    inline float wrap(float x, float min, float max)
    {
        if(x < min) return max - (min - x);
        if(x > max) return min + (x - max);
        return x;
    }

    Ship::Ship()
        : m_position(Math::Vector2::Origin)   
        , m_velocity(Math::Vector2::Origin)  
        , m_angle(120.0f)     
        , m_rotation(120.0f)
        , m_mass(1.0f)              
    {
        // TODO: RR: Modify init values to match proper ship rotation  
        // TODO: RR: Pass parent object pointer      
        std::cout << "Construction of ship\n";
        ChangeShip();
    }

    Ship::Ship(float _x, float _y)
        : m_position(_x, _y)        
    {
        std::cout << "Construction of ship\n";
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::MoveUp()
    {
        ApplyImpulse(Math::Vector2(3000.f));
    }

    void Ship::RotateLeft( float deltaTime )
    {
        // TODO: RR: Rotation doesn't seem to be happening
        m_angle -= m_rotation * deltaTime;
    }

    void Ship::RotateRight( float deltaTime )
    {
        // TODO: RR: Rotation doesn't seem to be happening
        m_angle += m_rotation * deltaTime;
    }


    void Ship::ApplyImpulse(Math::Vector2 impulse)
    {
        if(m_mass > 0)
        {
            m_velocity.x += (impulse.x / m_mass) * std::cos((m_angle) * (PI / 180));
            m_velocity.y += (impulse.x / m_mass) * std::sin((m_angle) * (PI / 180));
        }
    }

    void Ship::Update(float deltaTime)
    {
        // TODO: RR: Limit velocity to a max value
        // TODO: RR: Apply drag
        // TODO: RR: Reinstate wrap

        // float speed = 
        //     std::fabs(m_velocity.Length());

        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;
    }

    void Ship::ChangeShip()
    {
        m_points.push_back(Math::Vector2(0.0f, 20.0f));
		m_points.push_back(Math::Vector2(12.0f, -10.0f));
		m_points.push_back(Math::Vector2(6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-12.0f, -10.0f));
    }

    void Ship::Render()
    {
        glLoadIdentity();
        glTranslatef(m_position.x, m_position.y, 0.0);
        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
            std::vector<Math::Vector2>::iterator it = m_points.begin();
            for(; it != m_points.end(); ++it)
            {
                glVertex2f((*it).x, (*it).y);
            }
        glEnd();
    }
} // namespace Engine