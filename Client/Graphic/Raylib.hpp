/*
** EPITECH PROJECT, 2024
** Raylib.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <raylib.h>
#include <vector>
#include <memory>

#include "Client/Interface/I2dEntities.hpp"
#include "Client/Interface/I3dEntities.hpp"
#include "Client/Interface/IGraphic.hpp"
#include "Client/Interface/IText.hpp"
#include "Client/Interface/IMusic.hpp"
#include "Client/Interface/ISound.hpp"
#include "Client/Interface/IShader.hpp"
#include "Client/Interface/KeyMap.hpp"

class RayLib : IGraphic
{
    ~IGraphic() = default;

    void Init() override;

    void Update() override;

    void Destroy() override;

    KEY_MAP GetKey() override;

    void Draw() override;

    void Clear() override;

    void DrawTexts() override;

    bool HasText() override;

    void PlaySounds() override;

    bool HasSound() override;

    void PlayMusics() override;

    bool HasMusic() override;

    void Draw3DEntities() override;

    bool Has3DEntity() override;

    void Draw2DEntities() override;

    bool Has2DEntity() override;

    void DrawTextures() override;

    bool HasTexture() override;

    void DrawShaders() override;

    bool HasShader() override;

    void AddText(std::shared_ptr<IText> text) override;

    void AddSound(std::shared_ptr<ISound> sound) override;

    void AddMusic(std::shared_ptr<IMusic> music) override;

    void Add3DEntity(std::shared_ptr<I3DEntity> entity) override;

    void Add2DEntity(std::shared_ptr<I2DEntity> entity) override;

    void AddTexture(std::shared_ptr<ITexture> texture) override;

    void AddShader(std::shared_ptr<IShader> shader) override;

private:
    std::vector<std::shared_ptr<I2DEntity>> _2dEntities;
    std::vector<std::shared_ptr<I3DEntity>> _3dEntities;
    std::vector<std::shared_ptr<IText>> _texts;
    std::vector<std::shared_ptr<IMusic>> _musics;
    std::vector<std::shared_ptr<ISound>> _sounds;
    std::vector<std::shared_ptr<IShader>> _shaders;
};
