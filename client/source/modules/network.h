#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <vector>
#include <cstdint>

/** 
* @file network.h
* @brief Определения классов для управления сетевым взаимодействием.
* @details Этот файл содержит определения классов для управления сетевыми подключениями и передачей данных.
* @date 19.11.2024
* @version 1.0
* @authors Белов А. Р.
* @copyright ИБСТ ПГУ
*/

/** 
* @brief Класс для управления сетевым подключением и взаимодействием.
*/
class NetworkManager {
public:
    /**
    * @brief Конструктор класса NetworkManager.
    * @param address Адрес сервера.
    * @param port Порт сервера.
    */
    NetworkManager(const std::string& address, uint16_t port);

    /**
    * @brief Метод для установления сетевого подключения.
    * @throw NetworkException
    */
    void conn();

    /**
    * @brief Метод для аутентификации пользователя.
    * @throw AuthException
    * @param username Имя пользователя.
    * @param password Пароль.
    */
    void auth(const std::string& username, const std::string& password);

    /**
    * @brief Метод для передачи данных и получения результата.
    * @throw NetworkException
    * @param data Данные для обработки.
    * @return Результаты обработки данных.
    */
    std::vector<uint64_t> calc(const std::vector<std::vector<uint64_t>>& data);

    /**
    * @brief Метод для закрытия сетевого подключения.
    */
    void close();

private:
    int socket; ///< Сокет подключения.
    std::string address; ///< Адрес сервера.
    uint16_t port; ///< Порт сервера.
};

#endif // NETWORK_H
