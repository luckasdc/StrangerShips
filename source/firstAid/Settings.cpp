//
// Created by Luckas Declerck on 14/08/18.
//

#include <fstream>
#include "Settings.h"
#include "../controller/GameController.h"

using json = nlohmann::json;


Settings::Settings(std::string filename) {
    this->parseSettings(filename);
}

void Settings::parseSettings(std::string filename) {

    json j;
    try {
        std::ifstream i (filename);
        i >> j;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error loading file: " << e.what() << std::endl;
    }

    try {

        _width = j["width"].get<int>();
        _height = j["height"].get<int>();
        _azerty = j["azerty"].get<bool>();

        _texture_playership = j["texture_playership"].get<std::string>();
        _texture_secondplayership = j["texture_secondplayership"].get<std::string>();
        _texture_enemyship = j["texture_enemyship"].get<std::string>();
        _texture_bullet = j["texture_bullet"].get<std::string>();
        _texture_sporadicobstacle = j["texture_sporadicobstacle"].get<std::string>();
        _texture_heart = j["texture_heart"].get<std::string>();
        _texture_background = j["texture_background"].get<std::string>();
        _texture_floor = j["texture_floor"].get<std::string>();
        _texture_sky = j["texture_sky"].get<std::string>();
        _texture_playbutton = j["texture_playbutton"].get<std::string>();
        _texture_gameovertitle = j["texture_gameovertitle"].get<std::string>();
        _texture_gameoverbody = j["texture_gameoverbody"].get<std::string>();
        _texture_youwontitle = j["texture_youwontitle"].get<std::string>();

        for (auto &l : j["Levels"]) {
            Levelfile newlevel;
            newlevel.name = l["name"].get<std::string>();
            newlevel.file = l["file"].get<std::string>();
            _levels.push_back(newlevel);
        }

        for (auto &s : j["Highscores"]) {
            Highscore newscore;
            newscore.name = s["name"].get<std::string>();
            newscore.highscore = s["score"].get<int>();
            _highscores.push_back(newscore);
        }



    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error parsing values in file: " << e.what() << std::endl;
    }

}

int Settings::get_width() const {
    return _width;
}

int Settings::get_height() const {
    return _height;
}

bool Settings::is_azerty() const {
    return _azerty;
}

const std::string &Settings::get_texture_playership() const {
    return _texture_playership;
}

const std::string &Settings::get_texture_secondplayership() const {
    return _texture_secondplayership;
}

const std::string &Settings::get_texture_enemyship() const {
    return _texture_enemyship;
}

const std::string &Settings::get_texture_bullet() const {
    return _texture_bullet;
}

const std::string &Settings::get_texture_sporadicobstacle() const {
    return _texture_sporadicobstacle;
}

const std::string &Settings::get_texture_heart() const {
    return _texture_heart;
}

const std::string &Settings::get_texture_background() const {
    return _texture_background;
}

const std::string &Settings::get_texture_floor() const {
    return _texture_floor;
}

const std::string &Settings::get_texture_sky() const {
    return _texture_sky;
}

const std::string &Settings::get_texture_playbutton() const {
    return _texture_playbutton;
}

const std::string &Settings::get_texture_gameovertitle() const {
    return _texture_gameovertitle;
}

const std::string &Settings::get_texture_youwontitle() const {
    return _texture_youwontitle;
}

const std::string &Settings::get_texture_gameoverbody() const {
    return _texture_gameoverbody;
}

const std::vector<Levelfile> &Settings::get_levels() const {
    return _levels;
}

const std::vector<Highscore> &Settings::get_highscores() const {
    return _highscores;
}
