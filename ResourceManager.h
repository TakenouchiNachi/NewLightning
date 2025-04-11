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
private:
    int textureID;
    std::string filePath; // 画像のパス

public:
    Texture(std::string path) : filePath(path) {
        textureID = Novice::LoadTexture(filePath.c_str()); // 画像をロード
    }

    int GetTextureID() const { return textureID; }
};

class Sound : public Resource {
public:
	Sound(const std::string& path) {
		std::cout << "Loading sound: " << path << std::endl;
	}
};

class ResourceManager{
private:
    std::unordered_map<std::string, std::shared_ptr<Texture>> textureCache; // 画像のキャッシュ

public:
    // 画像をロード or キャッシュから取得
    std::shared_ptr<Texture> LoadTexture(const std::string& path) {
        if (textureCache.find(path) == textureCache.end()) {
            textureCache[path] = std::make_shared<Texture>(path); // 新しく読み込む
        }
        return textureCache[path]; // すでにある場合はキャッシュを返す
    }

    //実際にまとめて画像ファイルを読み込む関数
    void LoadResources() {
        LoadTexture("./NoviceResources./white1x1.png");
    }
};

