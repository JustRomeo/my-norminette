/*
** EPITECH PROJECT, 2020
** clone_arcade
** File description:
** Exception
*/

#include "Exception.hpp"

Exception::Exception(const std::string &message): _message(message) {}
Exception::~Exception() {}

const char *Exception::what() const throw() {return (_message.c_str());}
std::string const &Exception::getComponent() const {return (this->_message);}