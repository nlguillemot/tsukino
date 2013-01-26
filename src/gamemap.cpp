#include "gamemap.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

namespace heart
{

bool GameMap::load_from_file(const std::string& filename)
{
    std::ifstream ifs(filename);
    if (!ifs)
    {
        return false;
    }

    std::vector<Platform> platforms;
    std::vector<Collectible> collectibles;
    std::vector<SpawnPoint> spawnpoints;

    std::string line;

    while (std::getline(ifs,line))
    {
        std::stringstream ss;
        ss << line;

        std::string type;
        ss >> type;

        if (type == "platform")
        {
            Platform plat;

            ss >> plat.asset_name;
            ss >> plat.position.x;
            ss >> plat.position.y;

            platforms.push_back(plat);
        }
        else if (type == "collectible")
        {
            Collectible coll;

            ss >> coll.type;
            ss >> coll.position.x;
            ss >> coll.position.y;

            collectibles.push_back(coll);
        }
        else if (type == "spawnpoint")
        {
            SpawnPoint spawn;

            ss >> spawn.name;
            ss >> spawn.position.x;
            ss >> spawn.position.y;

            spawnpoints.push_back(spawn);
        }
        else
        {
            std::cout << "Unknown type: " << type << std::endl;
        }
    }

    platform_list_.swap(platforms);
    collectible_list_.swap(collectibles);
    spawnpoint_list_.swap(spawnpoints);

    return true;
}

const GameMap::SpawnPoint* GameMap::spawnpoint(const std::string& name)
{
    for (const SpawnPoint& sp : spawnpoint_list_)
    {
        if (sp.name == name)
        {
            return &sp;
        }
    }

    return nullptr;
}

const std::vector<GameMap::Platform>& GameMap::platforms() const
{
    return platform_list_;
}

}
