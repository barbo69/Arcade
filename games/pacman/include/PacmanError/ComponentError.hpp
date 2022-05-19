/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentError
*/

#ifndef COMPONENTERROR_HPP_
#define COMPONENTERROR_HPP_

#include "PacmanError.hpp"

namespace Arcade {

    enum class ComponentErrorType {
        BAD_USAGE
    };

    class ComponentError : public PacmanError {
        public:
            ComponentError(const ComponentErrorType type);
            ~ComponentError();

        protected:
            std::string _basicErrorMessage(const ComponentErrorType type);

    };
}

#endif /* !COMPONENTERROR_HPP_ */
