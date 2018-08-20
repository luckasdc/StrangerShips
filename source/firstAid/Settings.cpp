
#include <fstream>
#include "Settings.h"
#include <algorithm>
#include "../controller/GameController.h"
#include "Exception.h"

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
    catch (...) {
        throw ex::ParserFileException(filename);
    }

    std::string entry;

    try {
        std::string entry;
        entry = "_width";
        _width = j["width"].get<int>();
        entry = "_height";
        _height = j["height"].get<int>();
        entry = "_azerty";
        _azerty = j["azerty"].get<bool>();
        entry = "_username";
        _username = j["username"].get<std::string>();

        entry = "_texture_playership";
        _texture_playership = j["texture_playership"].get<std::string>();
        entry = "_texture_secondplayership";
        _texture_secondplayership = j["texture_secondplayership"].get<std::string>();
        entry = "_texture_enemyship";
        _texture_enemyship = j["texture_enemyship"].get<std::string>();
        entry = "_texture_bossbird";
        _texture_bossbird = j["texture_bossbird"].get<std::string>();
        entry = "_texture_bullet";
        _texture_bullet = j["texture_bullet"].get<std::string>();
        entry = "_texture_sporadicobstacle";
        _texture_sporadicobstacle = j["texture_sporadicobstacle"].get<std::string>();
        entry = "_texture_heart";
        _texture_heart = j["texture_heart"].get<std::string>();
        entry = "_texture_background";
        _texture_background = j["texture_background"].get<std::string>();
        entry = "_texture_floor";
        _texture_floor = j["texture_floor"].get<std::string>();
        entry = "_texture_sky";
        _texture_sky = j["texture_sky"].get<std::string>();
        entry = "_texture_playbutton";
        _texture_playbutton = j["texture_playbutton"].get<std::string>();
        entry = "_texture_gameovertitle";
        _texture_gameovertitle = j["texture_gameovertitle"].get<std::string>();
        entry = "_texture_gameoverbody";
        _texture_gameoverbody = j["texture_gameoverbody"].get<std::string>();
        entry = "_texture_youwontitle";
        _texture_youwontitle = j["texture_youwontitle"].get<std::string>();
        entry = "_font";
        _font = j["font"].get<std::string>();
        entry = "level";

        for (auto &l : j["Levels"]) {
            Levelfile newlevel;
            newlevel.name = l["name"].get<std::string>();
            newlevel.file = l["file"].get<std::string>();
            _levels.push_back(newlevel);
        }
        entry = "highscores";

        for (auto &s : j["Highscores"]) {
            Highscore newscore;
            newscore.name = s["name"].get<std::string>();
            newscore.highscore = s["score"].get<int>();
            _highscores.push_back(newscore);
        }
    }
    catch (...) {
        throw ex::ParserEntryException(filename, entry);
    }

}

void Settings::append_score(Highscore highscore) {
    _highscores.push_back(highscore);
}

bool Settings::save(){
    json j;

    j["width"] = _width;
    j["height"] = _height;
    j["azerty"] = _azerty;
    j["username"] = _username;
    j["font"] = _font;

    j["texture_playership"] = _texture_playership;
    j["texture_bossbird"] = _texture_bossbird;
    j["texture_secondplayership"] = _texture_secondplayership;
    j["texture_enemyship"]= _texture_enemyship;
    j["texture_bullet"] = _texture_bullet;
    j["texture_sporadicobstacle"] = _texture_sporadicobstacle;
    j["texture_heart"] = _texture_heart;
    j["texture_background"] = _texture_background;
    j["texture_floor"] = _texture_floor;
    j["texture_sky"] = _texture_sky;
    j["texture_playbutton"] = _texture_playbutton;
    j["texture_gameovertitle"] = _texture_gameovertitle;
    j["texture_gameoverbody"] = _texture_gameoverbody;
    j["texture_youwontitle"] = _texture_youwontitle;

    for (uint i = 0; i<this->_levels.size(); i++) {
        j["Levels"][i]["name"] = _levels[i].name;
        j["Levels"][i]["file"] = _levels[i].file;
    }

    for (uint i = 0; i<this->_highscores.size(); i++) {
        j["Highscores"][i]["name"] = _highscores[i].name;
        j["Highscores"][i]["score"] = _highscores[i].highscore;
    }

    std::ofstream file("../config.json");
    file << std::setw(4) << j;

    return true;
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

const std::string &Settings::get_font() const {
    return _font;
}

const std::vector<Levelfile> &Settings::get_levels() const {
    return _levels;
}

const std::vector<Highscore> Settings::get_highscores() const {
    std::vector<Highscore> scores = _highscores;

    // use lambda functions to sort vector
    std::sort( scores.begin( ), scores.end( ), [ ]( const auto& lhs, const auto& rhs )
    {
        return lhs.highscore > rhs.highscore;
    });

    // return the first 10 elements
    scores.resize(10);

    return scores;
}

const std::string &Settings::get_username() const {
    return _username;
}

const std::string &Settings::get_texture_bossbird() const {
    return _texture_bossbird;
}


