#include <iostream>
#include <string>
#include <map>
using namespace std;

class Player {
public:
    string currentRoom;
    string inventory;
};

int main() {
    Player player;
    player.currentRoom = "entrance";
    player.inventory = "";

    map<string, string> rooms;
    rooms["entrance"] = "You find yourself at the entrance of the Enchanted Forest.";
    rooms["north"] = "You venture deeper into the forest's verdant embrace.";
    rooms["south"] = "You backtrack to a clearing, seeking a new path.";
    rooms["east"] = "You follow a narrow trail into a sun-dappled glade.";
    rooms["west"] = "You hear a babbling brook as you step into a serene meadow.";
    rooms["treasure"] = "Congratulations! You've found the hidden treasure, a chest filled with jewels and ancient artifacts.";

    map<string, string> items;
    items["gemstone"] = "a mysterious gemstone";
    items["key"] = "a rusty old key";

    map<string, string> interactions;
    interactions["north"] = "You encounter a wise owl who challenges you with a riddle.\nSolve the riddle to proceed.";
    interactions["south"] = "A mischievous sprite blocks your path, demanding a shiny offering.";
    interactions["east"] = "A river blocks your way. You need something to build a bridge.";
    interactions["west"] = "You stumble upon an ancient tree with a keyhole at its base.";

    bool hasKey = false;
    bool hasGemstone = false;

    string input;
    while (true) {
        cout << rooms[player.currentRoom] << endl;
        if (!player.inventory.empty()) {
            cout << "Inventory: " << player.inventory << endl;
        }
        if (player.currentRoom == "treasure") {
            cout << "Congratulations! You've won the game." << endl;
            break;
        }
        cout << "What will you do? ";
        getline(cin, input);

        if (input == "quit") {
            break;
        } else if (input == "move north" && player.currentRoom == "entrance") {
            player.currentRoom = "north";
            cout << interactions["north"] << endl;
        } else if (input == "move south" && player.currentRoom == "entrance") {
            player.currentRoom = "south";
            cout << interactions["south"] << endl;
        } else if (input == "move east" && player.currentRoom == "entrance") {
            player.currentRoom = "east";
            cout << interactions["east"] << endl;
        } else if (input == "move west" && player.currentRoom == "entrance") {
            player.currentRoom = "west";
            cout << interactions["west"] << endl;
        } else if (input == "solve riddle" && player.currentRoom == "north") {
            cout << "You ponder the riddle and answer correctly.\nThe owl allows you to pass." << endl;
            player.currentRoom = "treasure";
        } else if (input == "offer gemstone" && player.currentRoom == "south" && hasGemstone) {
            cout << "The sprite gleefully accepts the gemstone and lets you continue." << endl;
            player.currentRoom = "treasure";
        } else if (input == "build bridge" && player.currentRoom == "east" && player.inventory == items["gemstone"]) {
            cout << "You use the gemstone to magically create a bridge across the river." << endl;
            player.inventory = "";
            player.currentRoom = "treasure";
        } else if (input == "unlock tree" && player.currentRoom == "west" && player.inventory == items["key"]) {
            cout << "The ancient tree creaks open, revealing a hidden passage to the treasure room." << endl;
            player.currentRoom = "treasure";
        } else if (input == "take gemstone" && player.currentRoom == "north") {
            player.inventory = items["gemstone"];
            hasGemstone = true;
            cout << "You take the gemstone from its resting place." << endl;
        } else if (input == "take key" && player.currentRoom == "west") {
            player.inventory = items["key"];
            hasKey = true;
            cout << "You take the rusty old key from the hollow in the tree." << endl;
        } else {
            cout << "Your actions are unclear in this mystical realm." << endl;
        }
    }

    return 0;
}

