![Linux](https://github.com/FppEpitech/R-Type/actions/workflows/Linux.yml/badge.svg)
![Windows](https://github.com/FppEpitech/R-Type/actions/workflows/Windows.yml/badge.svg)

# Table of Contents

- [From Noware: The Team Behind the Madness](#from-noware-the-team-behind-the-madness)
    - [Alban PERALTA](#alban-peralta--master-of-visual-sorcery)
    - [Mathieu ROBERT](#mathieu-robert--architect-of-reality-or-whats-left-of-it)
    - [Thomas BOUÉ](#thomas-boue--warden-of-game-structure-and-balance)
    - [Axel FRADET](#axel-fradet--the-phantom-weaver-of-connections)
    - [Théophile Jérôme-Rocher](#théophile-jérôme-rocher--the-unseen-arbiter-of-continuous-chaos)
- [Together, We Are From Noware](#together-we-are-from-noware)
- [R-Type Game Presentation](#r-type-game-presentation)
  - [Overview](#overview)
  - [Game Features](#game-features)
      - [Engaging Gameplay](#engaging-gameplay)
      - [Unique Mechanics](#unique-mechanics)
      - [Stunning Visuals](#stunning-visuals)
      - [Sound and Music](#sound-and-music)
- [Technical Details](#technical-details)
    - [Development Tools](#development-tools)
- [Building Our Project: Development Mode and Plugin Setup](#building-our-project-development-mode-and-plugin-setup)
    - [Prerequisites](#prerequisites)
    - [Steps to Build the Project](#steps-to-build-the-project)
    - [Clone the Project Repository](#1-clone-the-project-repository)
    - [Install Dependencies](#2-install-dependencies)
    - [Build the Project](#3-build-the-project)
    - [Start Development](#4-start-development)
- [How to PLAY?](#how-to-play-)
- [How to launch tests?](#how-to-launch-tests)
- [Documentation](#documentation)

---

![Team Logo](https://i.imgur.com/DnVU1l5.png)

# From Noware: The Team Behind the Madness

**Welcome to the world of From Noware**, where darkness meets code and innovation is forged in the fires of endless development.
We are a team of 5 brave developers, each wielding our own unique abilities to bring forth chaotic order into the realm of game development.
Together, we craft experiences that defy logic, with a dash of the absurd, but always with a deep love for our craft.
Meet the architects of this digital madness:


### **[Alban PERALTA](https://github.com/Peralban)** – *Master of Visual Sorcery*
**Role**: Graphics Enchanter and Client Architect  
From the darkest depths of the rendering engine, Alban weaves pixels into mesmerizing worlds.
With his arcane knowledge of graphics, he conjures stunning visuals and ensures that every frame is a painting.
On the client side, he stands as the gatekeeper, ensuring all interactions flow as smoothly as a well-timed dodge roll.


### **[Mathieu ROBERT](https://github.com/mathieurobert1)** – *Architect of Reality (or What's Left of It)*
**Role**: ECS Overlord and Keeper of Code Structure  
Mathieu commands the entity-component-system (ECS) architecture, where chaos and order collide.
He builds the very foundation upon which the universe of our games stands.
Like a dungeon master crafting intricate maps, he designs systems that bend but never break, ensuring that every piece of logic has its place in the abyss of complexity.


### **[Thomas BOUÉ](https://github.com/Thomaltarix)** – *Warden of Game Structure and Balance*
**Role**: Game Mechanic Architect  
Thomas is the keeper of the sacred scrolls of game design.
He oversees the structure of the worlds we create, balancing gameplay mechanics like a seasoned warrior balances a sword.
Whether it's combat flow, level progression, or difficulty curves that induce just the right amount of suffering, Thomas ensures that the experience is both brutal and rewarding.


### **[Axel FRADET](https://github.com/AxelF44)** – *The Phantom Weaver of Connections*
**Role**: Network Architect, Server/Client Whisperer  
Axel works in the shadows, unseen, yet his work ties everything together.
He breathes life into the network, ensuring that players can invade, assist, or duel from distant realms. His intricate knowledge of server and client interactions ensures that the multiplayer experience is seamless until the lag strikes, and chaos reigns (by design, of course).


### **[Théophile Jérôme-Rocher](https://github.com/theophile-jr)** – *The Unseen Arbiter of Continuous Chaos*
**Role**: Master of Continuous Integration (CI)  
Théophile, the unseen force that ensures all runs smoothly behind the scenes, governs the automated realms of CI. Like a benevolent deity, he ensures that every piece of code we push undergoes relentless testing, only allowing the worthy to see the light of production. His role is thankless yet critical he is the watcher of all builds, the breaker of errors.


**You have already heard of our team by some of our games, such as:**
- Eldritch Souls: Descent into the Nonsense Realm (2019)
- Sakura: Shadow die instantly (2021)
- BleedMore: Blood Never Enough (2023)
- Elder Sing: Karaoke of the Elden Lords (2024)

## **Together, We Are From Noware**

In the twilight between code and chaos, we form the pillars of From Noware, a studio driven by the desire to forge unforgettable, sometimes unforgiving, digital worlds.
Our skills combine to create experiences that challenge, confuse, and occasionally amuse.
We don't just build games we shape universes where the absurd and the epic coexist.

At From Noware, we embrace the challenge, thrive in the madness, and invite players to face the darkness with us.

Prepare yourself.

***

# R-Type Game Presentation

## Overview

R-Type is a 2D action game that pays homage to classic side-scrolling shooters while introducing innovative gameplay mechanics and visually stunning graphics.
Developed using C++ and Raylib, the game showcases the team's commitment to delivering a thrilling gaming experience filled with intense action and captivating visuals.

## Game Features

### Engaging Gameplay
- **Classic Side-Scrolling Action**: Players navigate through beautifully designed levels, battling enemies and overcoming obstacles in a fast-paced environment.
- **Challenging Boss Fights**: Each level culminates in an epic boss battle that tests players' skills and strategies, providing a sense of accomplishment upon victory.

### Unique Mechanics
- **Power-Up System**: Collect various power-ups to enhance weapons and abilities, allowing players to customize their playstyle and adapt to different challenges.
- **Health and Lives**: Players have a limited number of lives, encouraging strategic play and careful navigation through enemy-infested levels.

### Stunning Visuals
- **2D Graphics**: The game features vibrant 2D graphics created with Raylib, utilizing a combination of hand-drawn sprites and animations to create an immersive experience.
- **Dynamic Environments**: Each level is uniquely themed, offering diverse settings and atmospheric backgrounds that enhance gameplay.

### Sound and Music
- **Original Soundtrack**: An engaging soundtrack complements the action, enhancing immersion and keeping players engaged.
- **Sound Effects**: Crisp sound effects provide audio feedback for player actions, adding to the overall experience.

And much more! R-Type is a labor of love that combines classic gameplay elements with modern design sensibilities, resulting in a game that is both nostalgic and fresh.

## Technical Details

### Development Tools
- **Raylib**: R-Type is built using Raylib, a simple and easy-to-use C library for learning game programming.
Raylib provides robust graphics rendering capabilities that allow for the creation of visually appealing 2D games.
- **C++**: The game is developed in C++, leveraging the language's performance and flexibility to create a responsive and efficient gameplay experience.
- **Entity-Component-System (ECS) Architecture**: The game employs an ECS architecture, facilitating the separation of game logic and entities for easier management and scalability.

***

# Building Our Project: Development Mode and Plugin Setup

Welcome to the development guide for our game!
To get started with building our project in development mode or as a plugin, follow these steps:

## Prerequisites

Before diving in, ensure you have the following tools installed on your system:

- **Git**: For cloning the project repository.
- **CMake**: For building the project.
- **A suitable IDE** (e.g., Visual Studio, VSCode, etc.) for editing the code.

## Steps to Build the Project

### 1. Clone the Project Repository

Begin by cloning our project's repository from GitHub.
Open your terminal or command prompt and run the following command:

```bash
git clone git@github.com:FppEpitech/R-Type.git
```
This command will create a local copy of the project on your machine.

### 2. Install Dependencies

To install the project dependencies, navigate to the project's root directory and run the following commands:

```bash
cd R-Type
```
Run the following command to install the dependencies:

- For linux:
```bash
cd tools
chmod +x install.sh   # Make the script executable
./install.sh           # Run the installation script
```

- For Windows:
```powershell
cd tools
.\install.bat     # Run the installation script
```

This script will handle all the necessary installations and prepare your environment for building the project.

### 3. Build the Project

Once the installation is complete, you can build the project. Execute the build script using one of the following commands:

- For linux:
```bash
cd tools
chmod +x build.sh   # Make the script executable
./build.sh           # Run the build script
```

- For Windows:
```powershell
cd tools
.\build.bat      # Run the build script
```

The build process will compile the project and generate the necessary files for both development mode and plugin usage.

### 4. Start Development

With the build complete, you are now ready to dive into the code!
You can modify the source files, add features, and create your own plugins as needed.
For more information on how add mod and pluggin, please refer to the [Developer Documentation](https://github.com/FppEpitech/R-Type/wiki/Dev-documentation).

---

## How to PLAY ?
First, download the repository from GitHub:
```
git clone git@github.com:FppEpitech/R-Type.git
```

After that, run the `install-linux.sh` or `install-windows.bat` script in the `tools`folder:
**For Linux:**
```bash
chmod +x ./tools/install-linux.sh
./tools/install-linux.sh
```

or 

**For Windows:**
```powershell
.\tools\install-windows.bat
```

Then after the installation, you can run the other scripts:

**For Linux:**
```bash
chmod +x ./tools/build-linux.sh
./tools/build-linux.sh
```

or

**For Windows:**
```powershell
.\tools\build-windows.bat
```

Once the build is done, you can go into our `Game folder` and run the server or the client:

```
cd Game
```

For the server:
```bash
./r-type_server #or .\r-type_server.exe
```

For the client:
```bash
./r-type_client #or .\r-type_client.exe
```

Once the client is launch, you will be front of the main menu, you can write an IP address and a port to connect to a server.
After that, you can click on the `Connect` button to join the server.

![Main Menu](https://imgur.com/7lYBMrh)

After that, you will be able to play the game with your friends.

![Playable](https://imgur.com/2yeC7fE)

## How to launch tests ?
First, download the repository from Github, then compile it with:
```
git clone git@github.com:FppEpitech/R-Type.git
./tools/build.sh
```
Then, go to the **build/tests/** folder and run:
```
ctest
```

# Documentation
Here the project documentation: [R-Type](https://github.com/FppEpitech/R-Type/wiki)
