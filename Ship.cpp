#include "Ship.hpp"

#include <gl\GL.h>
#include <iostream>

namespace Engine
{
    Ship::Ship()
    {
        std::cout << "Construction of ship\n";
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::Render()
    {
        glBegin(GL_LINE_LOOP);
			glVertex2f(0.0, 20.0);
			glVertex2f( 12.0,  -10.0);
			glVertex2f( 6.0, -4.0);
			glVertex2f( -6.0, -4.0);
			glVertex2f( -12.0, -10.0);
		glEnd();
    }
}