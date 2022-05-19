/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanComponent
*/

#ifndef PACMANCOMPONENT_HPP_
#define PACMANCOMPONENT_HPP_

#include "IPacmanComponent.hpp"
#include <memory>
#include <vector>

namespace Arcade {

    using IPacCompUPtr = std::unique_ptr<IPacmanComponent>;
    using IPacCompUPtrVect = std::vector<std::unique_ptr<IPacmanComponent>>;

    class PacmanComponent : public IPacmanComponent {
        public:
            PacmanComponent(
                const std::size_t &id,
                const Type &type,
                const std::string &file
            );
            ~PacmanComponent();
            std::size_t getId() const;
            Type getType() const;
            virtual ComponentObjectType getComponentObjectType() const;
            virtual ComponentTextType getComponentTextType() const;
            std::string getFile() const;
            virtual void setX(std::size_t const x);
            virtual int getX() const override;
            virtual void setY(std::size_t const y);
            virtual int getY() const override;
            virtual void setWidth(const int width);
            virtual int getWidth() const override;
            virtual void setHeight(const int height);
            virtual int getHeight() const override;
            virtual void setRect(Rect const rect);
            virtual Rect getRect() const override;
            virtual void setFontSize(const int size);
            virtual int getFontSize() const override;
            virtual void setText(std::string const text);
            virtual std::string getText() const override;
            virtual void setObjectAnimation(const PacmanAnimType &type);
            virtual void setObjectCurrentAnimation(const PacmanAnimMove &move);
            virtual void animateObject();
            static IPacCompUPtr makePacmanComponent(
                const std::size_t &id,
                const Type &type,
                const std::string &file
            );

        protected:
            const std::size_t _id;
            const Type _type;
            const std::string _file;
    };
}

#endif /* !PACMANCOMPONENT_HPP_ */
