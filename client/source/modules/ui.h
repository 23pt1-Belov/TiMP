#ifndef UI_H
#define UI_H

#include "io.h"
#include "network.h"
#include "exceptions.h"
#include <string>
#include <vector>

/**
 * @file ui.h
 * @brief Определения классов для пользовательского интерфейса.
 * @details Этот файл содержит определения классов для обработки пользовательского ввода и управления интерфейсом.
 * @date 19.11.2024
 * @version 1.0
 * @authors Белов А. Р.
 * @copyright ИБСТ ПГУ
 */

/**
 * @brief Класс для управления пользовательским интерфейсом.
 */
class UserInterface
{
public:
    /**
     * @brief Конструктор класса UserInterface.
     * @throw ArgsDecodeException, InputOutputManager, NetworkManager
     * @param argc Количество аргументов командной строки.
     * @param argv Аргументы командной строки.
     */
    UserInterface(int argc, char *argv[]);

    /**
     * @brief Деструктор класса UserInterface.
     */
    ~UserInterface();

    /**
     * @brief Метод для запуска интерфейса.
     */
    void run();

private:
    std::string address;        ///< Адрес сервера.
    uint16_t port;              ///< Порт сервера.
    std::string input_path;     ///< Путь к входному файлу.
    std::string output_path;    ///< Путь к выходному файлу.
    std::string config_path;    ///< Путь к файлу конфигурации.
    InputOutputManager *io_man; ///< Менеджер ввода-вывода.
    NetworkManager *net_man;    ///< Менеджер сетевого взаимодействия.
    bool help_flag;             ///< Флаг для отображения справки.

    /**
     * @brief Вспомогательный метод для разбора аргументов командной строки.
     * @throw ArgsDecodeException
     * @param argc Количество аргументов командной строки.
     * @param argv Аргументы командной строки.
     */
    void parseArgs(int argc, char *argv[]);

    /**
     * @brief Метод для отображения справки.
     */
    void showHelp();
};

#endif // UI_H
