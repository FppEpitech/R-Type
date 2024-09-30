/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#pragma once

#include <memory>
#include <vector>

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

#ifdef _WIN32
    #define LIB_SUFFIX ".dll"
#else
    #define LIB_SUFFIX ".so"
#endif

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

        ColourComponent         _colourComponent;       //< Colour component.
        FontPathComponent       _fontPathComponent;     //< Font path component.
        MaterialMapComponent    _materialMapComponent;  //< Material map component.
        MusicPathComponent      _musicPathComponent;    //< Music path component.
        MusicPitchComponent     _musicPitchComponent;   //< Music pitch component.
        MusicVolumeComponent    _musicVolumeComponent;  //< Music volume component.
        ObjPathComponent        _objPathComponent;      //< OBJ path component.
        Position2DComponent     _position2DComponent;   //< Position 2D component.
        Position3DComponent     _position3DComponent;   //< Position 3D component.
        ScaleComponent          _scaleComponent;        //< Scale component.
        Size1DComponent         _size1DComponent;       //< Size 1D component.
        SoundPathComponent      _soundPathComponent;    //< Sound path component.
        SoundPitchComponent     _soundPitchComponent;   //< Sound pitch component.
        SoundVolumeComponent    _soundVolumeComponent;  //< Sound volume component.
        TextComponent           _textComponent;         //< Text component.
        TexturePathComponent    _texturePathComponent;  //< Texture path component.
};
