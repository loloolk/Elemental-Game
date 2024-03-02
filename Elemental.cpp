#include <iostream>
#include <vector>
#include "mine.h"

struct element {
    std::string name, parent1, parent2, family;
};
std::string premade(std::string par1, std::string par2) {
    if (par1 == "Dirt") {
        if (par2 == "Dirt") {
            return "Land";
        }
        else if (par2 == "Land") {
            return "Continent";
        }
        else if (par2 == "Fire") {
            return "Lava";
        }
        else if (par2 == "Water") {
            return "Mud";
        }
        else if (par2 == "Energy") {
            return "Earthquake";
        }
        else if (par2 == "Lava") {
            return "Volcano";
        }
        else if (par2 == "Pressure") {
            return "Stone";
        }
        else if (par2 == "Metal") {
            return "Dirty Metal";
        }
    }
    else if (par1 == "Air") {
        if (par2 == "Air") {
            return "Pressure";
        }
        else if (par2 == "Dirt" || par2 == "Land") {
            return "Dust";
        }
        else if (par2 == "Fire") {
            return "Smoke";
        }
        else if (par2 == "Water") {
            return "Rain";
        }
        else if (par2 == "Steam") {
            return "Mist";
        }
        else if (par2 == "Pressure") {
            return "Wind";
        }
        else if (par2 == "Stone") {
            return "Sand";
        }
    }
    else if (par1 == "Water") {
        if (par2 == "Fire") {
            return "Steam";
        }
        else if (par2 == "Water") {
            return "Sea";
        }
        else if (par2 == "Lava") {
            return "Obsidian";
        }
        else if (par2 == "Water") {
            return "Rust";
        }
        else if (par2 == "Continent") {
            return "Earth";
        }
    }
    else if (par1 == "Fire") {
        if (par2 == "Ocean" || par2 == "Sea") {
            return "Salt";
        }
        else if (par2 == "Mud") {
            return "Brick";
        }
        else if (par2 == "Energy") {
            return "Light";
        }
        else if (par2 == "Fire") {
            return "Energy";
        }
        else if (par2 == "Dust") {
            return "Gunpowder";
        }
        else if (par2 == "Gunpowder") {
            return "Explosion";
        }
        else if (par2 == "Stone") {
            return "Metal";
        }
    }
    else if (par1 == "Sea") {
        if (par2 == "Sea") {
            return "Ocean";
        }
        else if (par2 == "Land") {
            return "Sealand";
        }
    }
    return "no";
}
std::vector<element> storage;  
std::vector<std::string> banned = {""};
std::vector<std::string> premake = {"Dirt", "Air", "Water", "Fire", "Preassure", "Dust", "Lava", "Volcano", "Dirty Metal",  
"Mud", "Earthquake", "Energy", "Rain", "Steam", "Light", "Sea", "Obsidian", "Brick", "Salt", "Continent", "Earth", 
"Smoke", "Gunpowder", "Explosion", "Mist", "Wind", "Stone", "Metal", "Rust", "Sand", "Ocean", "Land", "Sealand"};

void start() {
    element water, fire, dirt, air;
    water.name = "Water";
    water.parent1 = "NULL";
    water.parent2 = "NULL";
    water.family = "Water";
    dirt.name = "Dirt";
    dirt.parent1 = "NULL";
    dirt.parent2 = "NULL";
    dirt.family = "Dirt";
    fire.name = "Fire";
    fire.parent1 = "NULL";
    fire.parent2 = "NULL";
    fire.family = "Fire";
    air.name = "Air";
    air.parent1 = "NULL";
    air.parent2 = "NULL";
    air.family = "Air";
    storage.push_back(dirt);
    storage.push_back(air);
    storage.push_back(water);
    storage.push_back(fire);
}

int main() {
    start();

    std::string rename;
    bool same;
    int fred;
    element test;
    
    std::cout << "Welcome to elemental.\n";  
    std::cout << "You can combine elements, and create your own elements using the four basic elements of dirt, air water and fire.\n";
    std::cout << "At any time you can type in \"Archive\" to see a list of all the elements and the combinations you have made so far,\nand type \"end\" when you want to exit the program.\n\n";
    redo1:
    std::cout << "The elements that currently exist are :\n";
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].family == "Dirt") {
            std::cout << "-" << "\e[32m" << storage[i].name << "\e[0m\n";
        }
        else if (storage[i].family == "Air") {
            std::cout << "-" << "\e[96m" << storage[i].name << "\e[0m\n";
        }
        else if (storage[i].family == "Water") {
            std::cout << "-" << "\e[34m" << storage[i].name << "\e[0m\n";
        }
        else if (storage[i].family == "Fire") {
            std::cout << "-" << "\e[31m" << storage[i].name << "\e[0m\n";
        }
    }
    fta:

    std::cout << "\nPlease put in the first of the elements you want to combine.\n";
    std::getline(std::cin, test.parent1);
    
    test.parent1 = tidyText(test.parent1);

    if (test.parent1 == "Archive") {
        std::cout << "Welcome to the archive.\nHere you can see the elements you have crated and what you combined to make them.\n\n";
        for (int i = 0; i < storage.size(); i++) {
            std::cout << storage[i].name << " is created by " << storage[i].parent1 << " and " << storage[i].parent2 << "!\n";
        }
        goto fta;
    }
    else if (test.parent1 == "End") {
        std::cout << "Bye!";
        return 0;
    }
    
    same = false;
    for (int i = 0; i < storage.size(); i++) {
        if (test.parent1 == storage[i].name) {
            same = true;
        }
    }
    if (same == false) {
        std::cout << "\nThat is not an element that has been created yet. Please try again.\n\n";
        goto redo1;
    }

    redo2:
    std::cout << "Please put in the second of the elements you want to combine.\n";
    std::getline(std::cin, test.parent2);
    
    test.parent2 = tidyText(test.parent2);
    
    same = false;
    for (int i = 0; i < storage.size(); i++) {
        if (test.parent2 == storage[i].name) {
            same = true;
        }
    }
    if (same == false) {
        std::cout << "\nThat is not an element that has been created yet. please try again.\n\n";
        std::cout << "The elements that currently exist are :\n";
        for (int i = 0; i < storage.size(); i++) {
        if (storage[i].family == "Dirt") {
            std::cout << "-" << "\e[32m" << storage[i].name << "\e[0m\n";
        }
        else if (storage[i].family == "Air") {
            std::cout << "-" << "\e[96m" << storage[i].name << "\e[0m\n";
        }
        else if (storage[i].family == "Water") {
            std::cout << "-" << "\e[34m" << storage[i].name << "\e[0m\n";
        }
        else if (storage[i].family == "Fire") {
            std::cout << "-" << "\e[31m" << storage[i].name << "\e[0m\n";
        }
    }
        goto redo2;
    }

    //no same parents
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].parent1 == test.parent1 && storage[i].parent2 == test.parent2 || storage[i].parent1 == test.parent2 && storage[i].parent2 == test.parent1) {
            std::cout << "You have already combined these two elements.\nThey create " << storage[i].name << ".\n";
            std::cout << "Type \"rename\" if you want to rename it to " << test.name << "?\nIf not just click \"enter\"\n";
            std::cin >> rename;
            if (rename == "rename") {
                storage[i].name = test.name ;
            }
            goto redo1;
        }
    }

    redo3:
    std::cout << "Congradulations, you just created ";

    if (premade(test.parent1, test.parent2) != "no") {
        std::cout << premade(test.parent1, test.parent2) << "!\n\n";
        test.name = premade(test.parent1, test.parent2);
    }
    else if (premade(test.parent2, test.parent1) != "no") {
        std::cout << premade(test.parent2, test.parent1) << "!\n\n";
        test.name = premade(test.parent2, test.parent1);
    }
    else if (premade(test.parent1, test.parent2) == "no" && premade(test.parent2, test.parent1) == "no" ) {
        std::cout << "a new element!\nWhat will you call it? (type \"no\" to not create this element)\n";
        name:
        std::getline(std::cin, test.name);
        std::cout << std::endl;
        
        test.name = tidyText(test.name);
        if (test.name == "No") {
            goto redo1;
        }
        for (int i = 0; i < premake.size(); i++) {
            if (test.name == premake[i] || test.name == "End" || test.name == "Archive") {
                std::cout << "Sorry, that name has been taken.\nPlease put in a better name.\n";
                goto name;
            }
        }
        for (int i = 0; i < storage.size(); i++) {
            if (test.name == storage[i].name) {
                std::cout << "Sorry, that name has been taken.\nPlease put in a better name.\n";
                goto name;
            }
        }
        //Banned Names
        for (int i = 0; i < banned.size(); i++) {
            if (test.name.find(banned[i]) < test.name.length()) {
                std::cout << "Sorry, that name has been banned.\nPlease put in a REAL name.\n";
                goto name;
            }
        }
    }

    test.family = "nothing";
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].name == test.parent1) {
            if (storage[i].family == "Fire") {
                test.family = "Fire";
            }
            else if (storage[i].family == "Water") {
                if (test.family != "Fire") {
                    test.family = "Water";
                }
            }
            else if (storage[i].family == "Dirt") {
                if (test.family != "Fire" && storage[i].family != "Water") {
                    test.family = "Dirt";
                }
            }
            else if (storage[i].family == "Air") {
                if (test.family != "Fire" && test.family != "Water" && test.family != "Dirt") {
                    test.family = "Air";
                }
            }
        }
        if (storage[i].name == test.parent2) {
            if (storage[i].family == "Fire") {
                test.family = "Fire";
            }
            else if (storage[i].family == "Water") {
                if (test.family != "Fire") {
                    test.family = "Water";
                }
            }
            else if (storage[i].family == "Dirt") {
                if (test.family != "Fire" && test.family != "Water") {
                    test.family = "Dirt";
                }
            }
            else if (storage[i].family == "Air") {
                if (test.family != "Fire" && test.family != "Water" && test.family != "Dirt") {
                    test.family = "Air";
                }
            }
        }
    }

    storage.push_back(test);
    std::cout << test.name << ":\nA combination of " << test.parent1 << " and " << test.parent2 << "!\n\n";
    goto redo1;
}
