#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

    public:

        static void convert(const std::string& literal);


    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);

        ~ScalarConverter();

        ScalarConverter& operator=(const ScalarConverter& other);


        enum LiteralType {
            Char,
            Int,
            Float,
            Double,
            Pseudo,
            Invalid
        };

        static LiteralType detect_type(const std::string& literal);

};


#endif
