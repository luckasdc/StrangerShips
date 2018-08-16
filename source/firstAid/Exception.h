
#ifndef STRANGERSHIPS_EXCEPTION_H
#define STRANGERSHIPS_EXCEPTION_H

#include <exception>
#include <string>
#include <utility>

namespace ex {

    class Exception : public std::exception {

    public:
        /**
         * @brief override the basic what()-function
         */
        const char* what() const noexcept override {
            return (_errorMsg + _filename).c_str();
        };

    protected:
        /**
          * @brief default Base-constructor for the custom Exception-class
          * @param msg
          */
        Exception(std::string msg, std::string filename) : _errorMsg(std::move(msg)), _filename(std::move(filename)){};

    private:
        std::string _errorMsg;
        std::string _filename;

    };

    class ParserFileException : public Exception {
    public:

        explicit ParserFileException(std::string filename) : Exception("The Config-parser could not open or find file ", filename) {};


    };

    class ParserEntryException : public Exception {
    public:

        explicit ParserEntryException(std::string filename, std::string field) : Exception("The Config-parser could not read field " + field + " of file ", filename) {};


    };

    class LevelFileException : public Exception {
    public:

        explicit LevelFileException(std::string filename) : Exception("The Level-parser could not open or find levelfile ", filename) {};



    };

    class LevelEntryException : public Exception {
    public:

        explicit LevelEntryException(std::string filename, std::string field) : Exception("The Level-parser could not read field " + field + " of file ", filename) {};


    };


    class ResourceException : public Exception {
    public:

        explicit ResourceException(std::string filename) : Exception("We could not find or read file ", filename) {};


    };



}



#endif //STRANGERSHIPS_EXCEPTION_H
