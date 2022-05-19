/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ArcadeSfml
*/

#ifndef ARCADESFML_HPP_
#define ARCADESFML_HPP_

#include "GameDimension.hpp"
#include "IDisplay.hpp"
#include "ISfmlData.hpp"
#include "ISfmlComponent.hpp"
#include <SFML/Graphics.hpp>

namespace Arcade {

    using ICompUPtrVect = std::vector<std::unique_ptr<IComponent>>;
    using IEventUPtrVect = std::vector<std::unique_ptr<IEvent>>;
    using StrUPtrISfmlDataPair = std::pair<std::string,
    std::unique_ptr<ISfmlData>>;
    using ISfmlDataUPtrMap = std::map<std::string,
    std::unique_ptr<ISfmlData>>;
    using SizeUPtrISfmlCompPair = std::pair<std::size_t,
    std::unique_ptr<ISfmlComponent>>;
    using ISfmlCompUPtrMap = std::map<std::size_t,
    std::unique_ptr<ISfmlComponent>>;
    using ISfmlCompUPtrVect = std::vector<std::unique_ptr<ISfmlComponent>>;
    using ISfmlDataUPtrVect = std::vector<std::unique_ptr<ISfmlData>>;
    

    class ArcadeSfml : public IDisplay {
        public:
            ArcadeSfml();
            ~ArcadeSfml();
            void init();
            void stop();
            std::string getLibName() const;
            void display(ICompUPtrVect &components);
            IEventUPtrVect &getEvents();
            void clear();

        private:
            const std::string _name;
            sf::RenderWindow _window;
            IEventUPtrVect _events;
            ISfmlDataUPtrMap _data;
            ISfmlCompUPtrMap _components;
            ISfmlCompUPtrVect _basicComponents;
            ISfmlDataUPtrVect _basicData;
            void _checkData(ICompUPtrVect &components);
            void _updateData(std::unique_ptr<IComponent> &component);
            void _cleanData(ICompUPtrVect &components);
            
    };

}

#endif /* !ARCADESFML_HPP_*/
