#include "Ship.hpp"
#include "App.hpp"

#include <gl\GL.h>

// STL
#include <iostream>
#include <cmath>

namespace Engine
{
    // TODO: RR: Move this to a lib
    const float PI = 3.141592653;
    const float MAX_VELOCITY = 500.0f;
    const float THRUST = 15.0f;
    const float DRAG_FORCE = 0.999f;
    const float ANGLE_OFFSET = 90.0f;

    Ship::Ship(App* parent)
        : GameObject(1.0f, 0.0f, 250.0f)
        , m_parent(parent) // TODO: RR: Contemplate using a component based design approach
    {        
        std::cout << "Construction of ship\n";
        ChangeShip();
    }

    Ship::Ship(App* parent, float _x, float _y)
        : GameObject(1.0f, 0.0f, 250.0f)
        , m_parent(parent)
    {
        m_position = Math::Vector2(_x, _y);
        std::cout << "Construction of ship\n";
        ChangeShip();
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::MoveUp()
    {
        ApplyImpulse(Math::Vector2(THRUST), m_angle + ANGLE_OFFSET);
    }

    void Ship::RotateLeft( float deltaTime )
    {        
        m_angle += m_rotation * deltaTime;
    }

    void Ship::RotateRight( float deltaTime )
    {        
        m_angle -= m_rotation * deltaTime;
    }

    void Ship::ApplyDrag(Math::Vector2 force)
    {
        m_velocity.x *= force.x;
        m_velocity.y *= force.y;
    }

    void Ship::Update(float deltaTime)
    {
        // Calculate speed
        float speed = 
            std::fabs(m_velocity.Length());

        // Cap speed
        if(speed > MAX_VELOCITY)
        {
            m_velocity.x = (m_velocity.x / speed) * MAX_VELOCITY;
            m_velocity.y = (m_velocity.y / speed) * MAX_VELOCITY;
        }

        // Set new state
        m_currentSpeed = speed;
        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

        // Applies drag
        ApplyDrag(Math::Vector2(DRAG_FORCE));

        GameObject::Update(m_parent, deltaTime);
    }

    void Ship::ChangeShip()
    {
        m_points.push_back(Math::Vector2(0.0f, 20.0f));
		m_points.push_back(Math::Vector2(12.0f, -10.0f));
		m_points.push_back(Math::Vector2(6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-12.0f, -10.0f));
    }
} // namespace Engine