# Demon House 

A text-based horror adventure game built in C++ where players explore a haunted house, battle demons, collect weapons and coins, and solve mysteries.

## Game Overview

Demon House is an interactive console-based game that combines elements of horror, adventure, and RPG gameplay. Players navigate through a haunted house filled with supernatural creatures, collect valuable items, and engage in combat with various demonic entities.

## Features

### Core Gameplay
- **Character System**: Create and customize your player character
- **Combat System**: Battle various demonic creatures with different abilities
- **Inventory Management**: Collect and manage weapons, coins, and special items
- **Random Events**: Encounter unexpected challenges and rewards
- **Save System**: Save your progress and resume your adventure

### Demon Types
- **Black Devil**: A powerful demonic entity
- **Vampire**: Classic blood-sucking creature
- **Hungry Skeleton**: Undead warrior
- **Evil Spirit**: Ethereal supernatural being
- **Shadow**: Mysterious dark entity

### Weapons
- **Handgun**: Basic ranged weapon
- **Revolver**: Improved handgun variant
- **Rifle**: High-powered long-range weapon
- **Shotgun**: Close-combat weapon with spread damage

### Currency System
- **Silver Coins**: Basic currency
- **Gold Coins**: Valuable currency
- **Platinum Coins**: Premium currency

### Game Elements
- **Mysteries**: Solve puzzles and uncover secrets
- **Riddles**: Challenge your wit with brain teasers
- **Dungeons**: Explore dark underground areas
- **Creepy Walls**: Navigate through haunted architecture
- **Weeping Well**: Discover hidden locations

### Technical Details

### Requirements
- **Compiler**: C++ compatible compiler (GCC, Clang, MSVC)
- **Platform**: Windows (uses Windows-specific headers)
- **Dependencies**: Standard C++ libraries

### Project Structure
```
demon-house/
├── GamePlay.cpp          # Main game loop and logic
├── Player.h/.cpp         # Player character system
├── Demons.h/.cpp         # Demon base class and implementations
├── Weapons.h/.cpp        # Weapon system
├── Coins.h/.cpp          # Currency system
├── Mysteries.h/.cpp      # Mystery solving mechanics
├── Riddles.h/.cpp        # Riddle system
├── Puzzles.h/.cpp        # Puzzle mechanics
├── Dungeons.h/.cpp       # Dungeon exploration
├── Various demon files   # Individual demon implementations
├── Various weapon files  # Individual weapon implementations
├── Various coin files    # Individual coin implementations
└── Text files           # ASCII art and game content
```

## How to Run

### Compilation
```bash
# Compile the main game file
g++ -o demon-house GamePlay.cpp *.cpp

# Or compile with specific flags
g++ -std=c++11 -o demon-house GamePlay.cpp *.cpp
```

### Execution
```bash
# Run the game
./demon-house
```

## How to Play

1. **Start the Game**: Launch the executable to begin your adventure
2. **Enter Your Name**: Create your character identity
3. **Choose Actions**:
   - `[a]` Random Play: Encounter random events (demons, coins, etc.)
   - `[b]` Fight Demon: Engage in direct combat
   - `[c]` Save & Pause: Save your progress
   - `[d]` Quit: Exit the game

### Game Mechanics
- **Power & Visibility**: Your character has power and visibility stats that affect gameplay
- **Lives System**: Manage your health and avoid death
- **Equipment**: Collect special items like silver armor, earmuffs, blue torch, knife, and sword
- **Combat**: Engage in turn-based combat with various demonic creatures

## Visual Elements

The game features ASCII art for:
- Game title and branding
- Player character representation
- Various demon types
- Death screen
- Environmental elements

## File Descriptions

- **GamePlay.cpp**: Main game engine and user interface
- **Player.h/.cpp**: Player character class with stats and inventory
- **Demons.h/.cpp**: Base demon class with polymorphic implementations
- **Weapons.h/.cpp**: Weapon system with different weapon types
- **Coins.h/.cpp**: Currency collection and management
- **Mysteries.h/.cpp**: Mystery solving mechanics
- **Text files**: ASCII art and game content for visual appeal

## Development Notes

- Built using object-oriented programming principles
- Implements polymorphism for demon and weapon types
- Uses file I/O for save/load functionality
- Includes Windows-specific audio capabilities
- Features random event generation for replayability

## Future Enhancements

Potential improvements could include:
- Cross-platform compatibility
- Enhanced graphics and UI
- More demon types and weapons
- Multiplayer support
- Sound effects and music
- Extended storyline and quests

## License

This project is open source. Feel free to modify and distribute according to your needs.

---
