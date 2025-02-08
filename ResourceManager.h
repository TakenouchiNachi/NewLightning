#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include<Novice.h>

class Resource {
public:
	virtual ~Resource(){}
};

class Texture : public Resource {
public:
    int textureID;

    Texture(std::string_view path) {
        std::cout << "Loading texture: " << path << std::endl;
        textureID = Novice::LoadTexture(path.data());
    }

    int GetID() const { return textureID; }
};
class Sound : public Resource {
public:
	Sound(const std::string& path) {
		std::cout << "Loading sound: " << path << std::endl;
	}
};

class ResourceManager
{
};

