![R-Type Game](https://i.imgur.com/DnVU1l5.png)

![Linux](https://github.com/FppEpitech/R-Type/actions/workflows/checks.yml/badge.svg?branch=main&event=push&label=Linux&os=ubuntu-latest)
![Windows](https://github.com/FppEpitech/R-Type/actions/workflows/checks.yml/badge.svg?branch=main&event=push&label=Windows&os=windows-latest)

# From Noware: The Team Behind the Madness

**Welcome to the world of From Noware**, where darkness meets code and innovation is forged in the fires of endless development. We are a team of 5 brave developers, each wielding our own unique abilities to bring forth chaotic order into the realm of game development. Together, we craft experiences that defy logic, with a dash of the absurd, but always with a deep love for our craft. Meet the architects of this digital madness:

You have already heard of our team by some of our games, such as:
- Eldritch Souls: Descent into the Nonsense Realm (2019)
- Sakura: Shadow die instantly (2021)
- BleedMore: Blood Never Enough (2023)
- Elder Sing: Karaoke of the Elden Lords (2024)

---

### **[Alban PERALTA](https://github.com/Peralban)** – *Master of Visual Sorcery*
**Role**: Graphics Enchanter and Client Architect  
From the darkest depths of the rendering engine, Alban weaves pixels into mesmerizing worlds. With his arcane knowledge of graphics, he conjures stunning visuals and ensures that every frame is a painting. On the client side, he stands as the gatekeeper, ensuring all interactions flow as smoothly as a well-timed dodge roll.

---

### **[Mathieu ROBERT](https://github.com/mathieurobert1)** – *Architect of Reality (or What's Left of It)*
**Role**: ECS Overlord and Keeper of Code Structure  
Mathieu commands the entity-component-system (ECS) architecture, where chaos and order collide. He builds the very foundation upon which the universe of our games stands. Like a dungeon master crafting intricate maps, he designs systems that bend but never break, ensuring that every piece of logic has its place in the abyss of complexity.

---

### **[Thomas BOUÉ](https://github.com/Thomaltarix)** – *Warden of Game Structure and Balance*
**Role**: Game Mechanic Architect  
Thomas is the keeper of the sacred scrolls of game design. He oversees the structure of the worlds we create, balancing gameplay mechanics like a seasoned warrior balances a sword. Whether it's combat flow, level progression, or difficulty curves that induce just the right amount of suffering, Thomas ensures that the experience is both brutal and rewarding.

---

### **[Axel FRADET](https://github.com/AxelF44)** – *The Phantom Weaver of Connections*
**Role**: Network Architect, Server/Client Whisperer  
Axel works in the shadows, unseen, yet his work ties everything together. He breathes life into the network, ensuring that players can invade, assist, or duel from distant realms. His intricate knowledge of server and client interactions ensures that the multiplayer experience is seamless until the lag strikes, and chaos reigns (by design, of course).

---

### **[Théophile Jérôme-Rocher](https://github.com/theophile-jr)** – *The Unseen Arbiter of Continuous Chaos*
**Role**: Master of Continuous Integration (CI)  
Théophile, the unseen force that ensures all runs smoothly behind the scenes, governs the automated realms of CI. Like a benevolent deity, he ensures that every piece of code we push undergoes relentless testing, only allowing the worthy to see the light of production. His role is thankless yet critical he is the watcher of all builds, the breaker of errors.

---

## **Together, We Are From Noware**

In the twilight between code and chaos, we form the pillars of From Noware, a studio driven by the desire to forge unforgettable, sometimes unforgiving, digital worlds. Our skills combine to create experiences that challenge, confuse, and occasionally amuse. We don't just build games we shape universes where the absurd and the epic coexist.

At From Noware, we embrace the challenge, thrive in the madness, and invite players to face the darkness with us.

Prepare yourself.


***


Multithreaded server and a graphical client for a well-known legacy video game called R-Type, using a game engine of our own design.

## How to build ? (Linux)
First, download the repository from GitHub, then compile it with:
```
git clone git@github.com:FppEpitech/R-Type.git
cmake -B build
cmake --build build/
```
Then to run the server:
```
./r-type_server
```
And the client:
```
./r-type_client
```
## How to launch tests ?
First, download the repository from Github, then compile it with:
```
git clone git@github.com:FppEpitech/R-Type.git
cmake -B build
cmake --build build/
```
Then, go to the **build/tests/** folder and run:
```
ctest
```

# Documentation
Here the project documentation: [SlimWiki](https://slimwiki.com/6fvu0f5pu/getting-started-nqdxve9qg-/welcome)
