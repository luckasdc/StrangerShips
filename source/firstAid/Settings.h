//
// Created by Luckas Declerck on 14/08/18.
//

#ifndef STRANGERSHIPS_SETTINGS_H
#define STRANGERSHIPS_SETTINGS_H

#include "json.hpp"
#include <string>
#include <vector>

typedef struct {
    std::string name;
    int highscore;
} Highscore;

typedef struct {
    std::string name;
    std::string file;
} Levelfile;

class Settings {

public:



    /**
     * @brief This constructor will call the parseSettings()-function to instantiate
     * everything based on the given filename (of a settings.json file)
     * @param filename
     */
    Settings(std::string filename);

    /**
    * @brief this will read a level.json file and parses it, will throw errors
    * if something went wrong.
    * @param filename
    */
    void parseSettings(std::string filename);


private:

    int _width;
    int _height;
    bool _azerty;

    std::string _texture_playership{};
    std::string _texture_secondplayership{};
    std::string _texture_enemyship{};
    std::string _texture_bullet{};
    std::string _texture_sporadicobstacle{};
    std::string _texture_heart{};
    std::string _texture_background{};
    std::string _texture_floor{};
    std::string _texture_sky{};
    std::string _texture_playbutton{};
    std::string _texture_gameovertitle{};
    std::string _texture_youwontitle{};
    std::string _texture_gameoverbody{};

    std::vector<Levelfile> _levels;

    std::vector<Highscore> _highscores;


public:

    int get_width() const;

    int get_height() const;

    bool is_azerty() const;

    const std::string &get_texture_playership() const;

    const std::string &get_texture_secondplayership() const;

    const std::string &get_texture_enemyship() const;

    const std::string &get_texture_bullet() const;

    const std::string &get_texture_sporadicobstacle() const;

    const std::string &get_texture_heart() const;

    const std::string &get_texture_background() const;

    const std::string &get_texture_floor() const;

    const std::string &get_texture_sky() const;

    const std::string &get_texture_playbutton() const;

    const std::string &get_texture_gameovertitle() const;

    const std::string &get_texture_youwontitle() const;

    const std::string &get_texture_gameoverbody() const;

    const std::vector<Levelfile> &get_levels() const;

    const std::vector<Highscore> &get_highscores() const;
};


#endif //STRANGERSHIPS_SETTINGS_H
