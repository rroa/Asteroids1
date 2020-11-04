#include "Ship.hpp"

#include <gl\GL.h>
#include <iostream>

namespace Engine
{
    inline float wrap(float x, float min, float max)
    {
        if(x < min) return max - (min - x);
        if(x > max) return min + (x - max);
        return x;
    }

    Ship::Ship()
        : m_position(Math::Vector2::Origin)   
        , m_velocity(Math::Vector2::Origin)  
        , m_angle(0.0f)     
        , m_rotation(1.0f)
        , m_mass(1.0f)              
    {
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

    void Ship::RotateLeft( float deltaTime )
    {
        m_angle -= m_rotation * deltaTime;
    }

    void Ship::RotateRight( float deltaTime )
    {
        m_angle += m_rotation * deltaTime;
    }

    void Ship::Update(float deltaTime)
    {

    }

    void Ship::ChangeShip()
    {
        m_points.push_back(Math::Vector2(0.0f, 20.0f));
		m_points.push_back(Math::Vector2(12.0f, -10.0f));
		m_points.push_back(Math::Vector2(6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-12.0f, -10.0f));
    }

    // void Ship::Move(float _x, float _y)
    // {
    //     float x = m_position.x + _x;
    //     float y = m_position.y + _y;

    //     // TODO: RR: Move this OUT!
    //     float width = 1136.0f;
    //     float height = 640.0f;

    //     float min_width = -width / 2.0f;
    //     float max_width = width / 2.0f;

    //     float min_height = -height / 2.0f;
    //     float max_height = height / 2.0f;

    //     m_position.x = wrap(x, min_width, max_width);
    //     m_position.y = wrap(y, min_height, max_height);
    // }

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