/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#pragma once

#include <memory>
#include <vector>

#include "../Ecs/Src/Registry.hpp"
#include "../Interface/IGraphic.hpp"
#include "../../Client/Src/Component/TextComponent.hpp"
#include "../../Client/Src/Component/ScaleComponent.hpp"
#include "../../Client/Src/Component/ColourComponent.hpp"
#include "../../Client/Src/Component/Size1DComponent.hpp"
#include "../../Client/Src/Component/ObjPathComponent.hpp"
#include "../../Client/Src/Component/FontPathComponent.hpp"
#include "../../Client/Src/Component/MusicPathComponent.hpp"
#include "../../Client/Src/Component/SoundPathComponent.hpp"
#include "../../Client/Src/Component/MusicPitchComponent.hpp"
#include "../../Client/Src/Component/Position2DComponent.hpp"
#include "../../Client/Src/Component/Position3DComponent.hpp"
#include "../../Client/Src/Component/SoundPitchComponent.hpp"
#include "../../Client/Src/Component/MaterialMapComponent.hpp"
#include "../../Client/Src/Component/MusicVolumeComponent.hpp"
#include "../../Client/Src/Component/SoundVolumeComponent.hpp"
#include "../../Client/Src/Component/TexturePathComponent.hpp"

/**
 * @brief This class aim to load graphical systems and components in a register.
 *
 */
class LoadGraphicalEcs {

    public:

        /**
         * @brief Destroy the load Graphical Ecs object.
         *
         */
        ~LoadGraphicalEcs() = default;

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
