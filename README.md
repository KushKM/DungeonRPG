# Labyrinth Looter
 
 Authors: 
 [Jackson](https://github.com/JMarolt), 
 [Kush](https://github.com/KushKM), 
 [Julian](https://github.com/jgonz671), 
 [Daniel](https://github.com/drodr211)
 
 ![BADGE](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/actions/workflows/c-cpp.yml/badge.svg)
 
## Project Description
* Text-based RPG game with rougelite elements, where you fight through rooms to defeat monsters and earn currency to permanently upgrade your character.
* We will be using C++ with VSCode. We will be using Git/Github to share, save, edit, and finalize our code as a group. We will also be using Cmake/make allowing us to compile and run much easier. We will use Valgrind to detect whether we had any memory leaks within our code. Finally, we will use Googletest framework to test our functions/code to ensure that they work.
* The inputs will asked for through the command line interface (names, option numbers, etc.) and the outputs will be printed to the terminal using cout. We will ask the user every turn what they want to do(Attack, Run...). After each choice, the output will include(User health, monster health, user stats, the room they are in, whether there even is a monster or not). 
* Features:
  * Turn-based gameplay. This means that at the beginning of each turn, we can choose between attacking or going to a different room. If the user chooses a different room, then they will attempt to go into the room of their choice(if they have one) and if they fail, they will be attacked by the monster and lose their turn. If the user decides to attack, the entity(user or monster) with higher speed will attack first. If the user defeats the monster(s) within the room, they will forever be dead. They also have a chance to drop items and some form of currency. If the user dies, they will lose their stats and coins and be reset to the beginning. (Currently thinking on making multiple layers).
  * Increasingly difficult rooms and better rewards. As the user progresses further into the game, the monsters will have higher stats(Health, Attack Damage, Speed, and other things) making it harder to go through. As the user gets closer to the end, they will start to encounter bosses with different styles of gameplay. Once they defeat the bosses, they can advance and may receive items that the bosses were holding.
  * There will be a final boss. Once the player defeats it, they will complete the game or floor(whatever we are choosing). They can then go shopping with what they have and enter the same level or a harder level.
  * Pick a class that suits your fighting style at the start of the game. Currently, there are Cleric(Has a chance to heal itself), Wizard(Chance to inflict more damage), Rogue(Has a chance to dodge an attack), Brute(As it has less health, it does more damage).
  * Unless the player dies, they will be able to upgrade stats and buy items at a shop outside the level.
 

## User Interface Specification
[User Interface Specification](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/screen.pdf)

## Navigation Diagram
![Nav Diagram](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/navdiagram.png)

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/umldiagram.drawio.png)

Above is the Class Diagram for our game: Labyrinth Looter. The program starts in Game class where the user will select a character in a function called createCharacter() where inside it creates a chracter(extended from entity class) of the type the user wants. Character is an abstract class and only provides universal functions for the classes that extend it(Cleric, Wizard, Brute, Rogue). At the end of the function, we create a list of room objects where each room holds a monster(if it has one) and an item(s) if it has any. This will be random(about 10-20 rooms) and based on how many rooms the user has gone through, the monsters will be stronger and the possible loot will be better. Since the player has no money, we can call startRun() and enter the first room in the list. Here we set the currRoom to be the room we are in. After entering a room, we output the options a player has with outputPlayerMenu() where we will also take in an input on what the user wants to do which includes attacking, running, or viewing inventory. If the player enters a boss room(The boss class extends the monster class and the monster class extends entity). It will inherit all of the methods and variables that monster and entity has but will have extra parts of it), they will not be allowed to leave as the boss will not let them leave until they have defeated it or have died. Once the player has reached the final room(indicated by reaching the end of the list of rooms), they will face the last boss. If they successfully defeat the boss without dying, they receive a large reward and are kicked back to the main menu where they can shop for items/stat boosts or go into the next level.

Game mechanics: When the player chooses to attack, they will call the attack() function within character. This will attempt to attack the monster within the currRoom. Either the user or monster(whichever has a higher speed stat) will attack first and inflict a certain amount of damage to the other entity. If that entity then dies, the other attack does not happen. As for item mechanics, there can be two types. The first type is usable which means it is a one-time use to give temporary buffs such as higher damage or health regeneration. There are also permanent items the user can hold and these effects will last the entire time but have much less effect than the useable items. When the user is done, they have the option to save where they are, save their inventories, and save their stats. This will be done in a text file just holding basic information about the player and can be reloaded when the player launches the game at a different time.
 
# SOLID
We included some new SOLID design principles within our code since phase II. We firstly applied the S, Single Responsibility, by moving all methods that output information outside of the game class and into their own class. This is because game is supposed to have the one responsibility of running our game. Now, instead of running our game and worrying about menu printing, we have a separate class that can print out everything for the game class now. We plan on using this more for different classes such as the room class, monster class, and character class. Next, we used the L, Liskov Substitution, by allowing the ability to pass any type of sub class into a method and not have it break. We can see this when passing in an entity type object into attackEnemy function and it works. It makes the code much simpler than making multiple methods to do basically the same thing. We implemented D, dependency inversion principle, by creating multiple interfaces to allow for multiple classes to use the same code instead of just relying entirely on classes . We did this by using two abstract classes, Entity and Item which can be used by its subclasses. 

 
> ## Final deliverable
> All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
> Before the demo, you should do the following:
> * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
> * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
> * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
## Screenshots

#### Main Menu and Shop
![Main Menu](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/mainmenu.png)
![Shop](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/shop.png)

#### Gameplay 
<img src="https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/classpick.png" style="width:80%">

![travel](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/traveltodungeon.png)
![fight](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/fight.png)
![win](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/win.png)


## Installation
> You will need `cmake` and `make` to be installed for this to work.

 You have 2 options to install:
  1. Clone this repo
  2. Download this repo in a ZIP file.

To clone:
  - On your local machine, navigate to the directory where you would like to clone this project (Ex. `C:\Users\MY_USER\Documents`)
  - Open a terminal in this folder
  - Do `git clone https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671` (make sure you have git installed)
  - Should now be ready to use!

To download:
  - Click on the green Code button at the top of this repo, then click download ZIP
  - Extract that zip in any folder you'd like (Ex. `C:\Users\MY_USER\Documents`).
  - Should now be ready to use!

## Usage
To begin the program to play the game:
  - While in the root project folder, in the terminal do:
      
        user@local$ cmake .
        user@local$ make 
        user@local$ ./main 
    - This will begin the game
  - During the game, after statements and asking for inputs, the program will seem to stop. Please press `Enter` to continue. This is to allow the user time to read and continue when ready.

## Testing
> How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
