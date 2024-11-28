#pragma once

#include <exception>
#include <string>


class BasicClientError : public std::exception
{
public:
    BasicClientError(const std::string &name, const std::string &message, const std::string &func);

    const char *what() const noexcept override;

protected:
    std::string name;            ///< Имя исключения.
    std::string func;            ///< Имя функции, в которой возникла ошибка.
    mutable std::string message; ///< Сообщение об ошибке.
};

class InputOutputError : public BasicClientError
{
public:
    InputOutputError(const std::string &message, const std::string &func);
};

class ArgsDecodeError : public BasicClientError
{
public:
    ArgsDecodeError(const std::string &message, const std::string &func);
};

class DataDecodeError : public BasicClientError
{
public:
    DataDecodeError(const std::string &message, const std::string &func);
};

class AuthError : public BasicClientError
{
public:
    AuthError(const std::string &message, const std::string &func);
};

class NetworkError : public BasicClientError
{
public:
    NetworkError(const std::string &message, const std::string &func);
};
