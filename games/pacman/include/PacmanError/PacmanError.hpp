/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanError
*/

#ifndef PACMANERROR_HPP_
#define PACMANERROR_HPP_

#include <string>
#include <exception>

namespace Arcade {
    class PacmanError : public std::exception {
        public:
            PacmanError(const std::string &message);
            ~PacmanError();
            const char *what() const noexcept override;

        protected:
            const std::string _message;
    };
}

#endif /* !PACMANERROR_HPP_ */
