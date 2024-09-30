/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#pragma once

#include <memory>
#include "IGraphic.hpp"
#include "Registry.hpp"


#include "ColourComponent.hpp"
#include "FontPathComponent.hpp"
#include "MaterialMapComponent.hpp"
#include "MusicPathComponent.hpp"
#include "MusicPitchComponent.hpp"
#include "MusicVolumeComponent.hpp"
#include "ObjPathComponent.hpp"
#include "Position2DComponent.hpp"
#include "Position3DComponent.hpp"
#include "ScaleComponent.hpp"
#include "Size1DComponent.hpp"
#include "SoundPathComponent.hpp"
#include "SoundPitchComponent.hpp"
#include "SoundVolumeComponent.hpp"
#include "TextComponent.hpp"
#include "TexturePathComponent.hpp"

#include <vector>

/**
 * @brief Get the Graphical Library object.
 *
 * @return std::shared_ptr<IGraphic>
 */
std::shared_ptr<IGraphic> getGraphicalLibrary();

/**
 * @brief This class aim to load graphical systems and components in a register.
 *
 */
class loadGraphicalEcs {

    public:

        /**
         * @brief Construct a new load Graphical Ecs object.
         *
         */
        loadGraphicalEcs() = default;

        /**
         * @brief Destroy the load Graphical Ecs object.
         *
         */
        ~loadGraphicalEcs() = default;

        /**
         * @brief Load all graphical systems and components int a register.
         *
         * @param registry Register to fill with systems ad components.
         */
        void loadInRegister(ECS::Registry registry);

    private:

        std::vector<std::reference_wrapper<IComponent>> _components {
            _colourComponent,
            _fontPathComponent,
            _materialMapComponent,
            _musicPathComponent,
            _musicPitchComponent,
            _musicVolumeComponent,
            _objPathComponent,
            _position2DComponent,
            _position3DComponent,
            _scaleComponent,
            _size1DComponent,
            _soundPathComponent,
            _soundPitchComponent,
            _soundVolumeComponent,
            _textComponent,
            _texturePathComponent
        }; //< List of graphical components.

        ColourComponent         _colourComponent;
        FontPathComponent       _fontPathComponent;
        MaterialMapComponent    _materialMapComponent;
        MusicPathComponent      _musicPathComponent;
        MusicPitchComponent     _musicPitchComponent;
        MusicVolumeComponent    _musicVolumeComponent;
        ObjPathComponent        _objPathComponent;
        Position2DComponent     _position2DComponent;   //< Position 2D component.
        Position3DComponent     _position3DComponent;
        ScaleComponent          _scaleComponent;
        Size1DComponent         _size1DComponent;       //< Size 1D component.
        SoundPathComponent      _soundPathComponent;
        SoundPitchComponent     _soundPitchComponent;
        SoundVolumeComponent    _soundVolumeComponent;
        TextComponent           _textComponent;         //< Text component.
        TexturePathComponent    _texturePathComponent;
};
