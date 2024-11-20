#ifndef IO_H
#define IO_H

#include <string>
#include <vector>
#include <array>
#include "exceptions.h"

/** 
* @file io.h
* @brief Определения классов для управления вводом-выводом/чтением-записью.
* @details Этот файл содержит определения классов для работы с файлами ввода-вывода и конфигурационными данными.
* @date 19.11.2024
* @version 1.0
* @authors Белов А. Р.
* @copyright ИБСТ ПГУ
*/

/** 
* @brief Класс для управления вводом и выводом данных.
*/
class InputOutputManager {
public:
    /**
    * @brief Конструктор класса InputOutputManager.
    * @param path_to_conf Путь к файлу конфигурации.
    * @param path_to_in Путь к входному файлу.
    * @param path_to_out Путь к выходному файлу.
    */
    InputOutputManager(
        const std::string& path_to_conf, 
        const std::string& path_to_in, 
        const std::string& path_to_out
    );

    /**
    * @brief Метод для чтения конфигурационных данных.
    * @throw InputOutputException, DataDecodeException
    * @return Массив строк с конфигурационными данными.
    */
    std::array<std::string, 2> conf();

    /**
    * @brief Метод для чтения данных из файла.
    * @throw InputOutputException
    * @return Двумерный вектор с данными.
    */
    std::vector<std::vector<uint64_t>> read();

    /**
    * @brief Метод для записи данных в файл.
    * @throw InputOutputException
    * @param data Вектор данных для записи.
    */
    void write(const std::vector<uint64_t>& data);

private:
    std::string path_to_conf; ///< Путь к файлу конфигурации.
    std::string path_to_in; ///< Путь к входному файлу.
    std::string path_to_out; ///< Путь к выходному файлу.
};

#endif // IO_H
