#pragma once
#include "string"
#include "stdexcept"

class RepositoryException : public std::runtime_error
{
public:
    explicit RepositoryException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class ValidationException : public std::runtime_error
{
public:
    explicit ValidationException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class InputException : public std::runtime_error
{
public:
    explicit InputException(const std::string& msg)
        : std::runtime_error(msg) {}
};