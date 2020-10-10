// © 2019 Joseph Cameron - All Rights Reserved

#ifndef GDK_GAMEPAD_GLFW_H
#define GDK_GAMEPAD_GLFW_H

#include <gdk/gamepad.h>

namespace gdk
{
    /// \brief gamepad implementation for GLFW3
    /// \attention update method be called to update gamepad state. This is not handled by glfwPollEvents
    class gamepad_glfw : public gamepad
    {
    private:
        //! glfw index for this joystick
        int m_JoystickIndex;

        //! Buffer containing name of device
        std::string m_Name;
        
        //! Buffer containing most recent button states
        std::vector<unsigned char> m_Buttons;
       
        //! Buffer containing most recent axis states
        std::vector<float> m_Axes;

        //! Buffer containing the most recent hat states
        std::vector<unsigned char> m_Hats;

    public:
        //! updates the state of this gamepad
        /// \attention must be called periodically.
        void update();

        virtual float get_axis(index_type index) const override;
        
        virtual gamepad::button_state_type get_button_down(index_type index) const override;

        virtual gamepad::hat_state_type get_hat(index_type index) const override;

        virtual std::string_view get_name() const override;

		virtual button_collection_type get_buttons() const override;

        gamepad_glfw(const int joystickID);
    };
}

#endif

