/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <string>

namespace Arcade {

    /**
     * @brief The Rect struct give information on a sprite.
     * 
     */
    struct Rect {
        int x;
        int y;
        int width;
        int height;
    };

    /**
     * @brief The IComponent interface represents a game entity that can either
     * be displayed or played as a sound.
     */
    class IComponent {
        public:
            enum Type {
                OBJECT,
                SOUND,
                TEXT
            };
            virtual ~IComponent() = default;

            /**
             * @brief Get the component ID
             * The component ID is used to identify a component, which can be useful with user/component interaction
             * @return std::size_t
             */
            virtual std::size_t getId() const = 0;

            /**
             * @brief Get component type
             * Use it to know how component need to be displayed (OBJECT | SOUND | TEXT)
             * @return Type
             */
            virtual Type getType() const = 0;   // Get component type
            /**
             * @brief Get file associated with component
             * Use it to create textures, etc.
             * @return std::string
             */
            virtual std::string getFile() const = 0;
            /**
             * @brief Get X position of the component
             * Only works with Type (OBJECT/TEXT). Will throw an exception if Type = SOUND
             * @return intP
             */
            virtual int getX() const = 0;
            /**
             * @brief Get Y position of the component
             * Only works with Type (OBJECT/TEXT). Will throw an exception if Type = SOUND
             * @return int
             */
            virtual int getY() const = 0;
            /**
             * @brief Get animated sprite rect
             * #THROW if no rect or Type != OBJECT
             * @return Rect
             */
            /**
             * @brief Get text from the component
             * Only works with Type (TEXT). Will throw an exception if Type != TEXT
             * @return std::string
             */
            virtual std::string getText() const = 0;
            /**
             * @brief Get animated sprite rect
             * #THROW if no rect or Type != OBJECT
             * @return Rect
             */
            virtual Rect getRect() const = 0;
            /**
             * @brief Get width of the OBJECT/TEXT Component
             * 
             * @return int
             */
            virtual int getWidth() const = 0;
            /**
             * @brief Get height of the OBJECT/TEXT Component
             * 
             * @return int
             */
            virtual int getHeight() const = 0;
            /**
             * @brief Get the font size of the TEXT Component
             * 
             * @return int 
             */
            virtual int getFontSize() const = 0;
            /**
             * @brief Set the X value of the Component
             * 
             * @param x 
             */
            virtual void setX(std::size_t const x) = 0;
            /**
             * @brief Set the Y value of the Component
             * 
             * @param y 
             */
            virtual void setY(std::size_t const y) = 0;

                        /**
             * @brief Set the X value of the Component
             * 
             * @param x 
             */
            virtual void setWidth(const int width) = 0;
            /**
             * @brief Set the Y value of the Component
             * 
             * @param y 
             */
            virtual void setHeight(const int height) = 0;
            /**
             * @brief Set the text of the Component
             * 
             * @param text 
             */
            virtual void setText(std::string const text) = 0;
            /**
             * @brief Set the Rect of the OBJECT Component
             * 
             * @param rect 
             */
            virtual void setRect(Rect const rect) = 0;
    };
}

#endif /* !ICOMPONENT_HPP */
