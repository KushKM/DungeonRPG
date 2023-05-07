[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10950862&assignment_repo_type=AssignmentRepo)
# {TITLE HERE}
 
 Authors: 
 [Jackson](https://github.com/JMarolt), 
 [Kush](https://github.com/KushKM), 
 [Julian](https://github.com/jgonz671), 
 [Daniel](https://github.com/drodr211)
 
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
https://docs.google.com/document/d/1ycGBIsks2ziMhPCVEsG74GltEmhe5tnghvWlB2OEPqw/edit?usp=sharing

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-jmaro005-drodr211-kmoma001-jgonz671/blob/master/docs/rpg_class_diagram.png)
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
