/*********************
Name: Odelya Yaakowich
ID: 207346784
**********************/


#include "Zoo.h"


void Zoo::stop(int index) 
{
    animals[index]->stop();
}

void Zoo::move(int index) 
{
    animals[index]->move();
}

void Zoo::step() 
{
    for (int i = 0; i < animals.size(); ++i) {
        animals[i]->step();
    }
}

void Zoo::print_list() 
{
    std::cout << "List of Animal in the Zoo:\n";
    for (int i = 0; i < animals.size(); ++i) {
        std::cout << i << ": ";
        animals[i]->printDetails();
    }
}

void Zoo::create(char type, std::string name) 
{
    int row = rand() % ROWS;
    int col = rand() % COLS;

    switch (type) {
    case 'L':
        animals.push_back(std::make_unique<Lion>(name, Location(row, col)));
        break;
    case 'M':
        animals.push_back(std::make_unique<Monkey>(name, Location(row, col)));
        break;
    case 'D':
        animals.push_back(std::make_unique<Dog>(name, Location(row, col)));
        break;
    default:
        std::cout << "Invalid operation";
        break;
    }
}

void Zoo::del(int index) 
{
    animals.erase(animals.begin() + index);
}

void Zoo::delAll(char type) 
{
    for (int i = 0; i < animals.size(); ++i) {
        if (animals[i]->getInitial() == type) {
            del(i);
            i--;
        }
    }
}

void Zoo::print_map() 
{
    std::cout << "map:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bool is_valid = true;
            for (std::unique_ptr<Animal>& t : animals) {
                if (t->getLocation() == Location(i, j)) {
                    if (is_valid)
                        std::cout << t->getInitial();
                    is_valid = false;
                }
            }
            if (is_valid)
                std::cout << "*";
        }
        std::cout << "\n";
    }
}

void Zoo::help()
{
    std::cout << "Choose 'help' to see the options.\n"

        << "Choose '.' to get all the animals to be step.\n"

        << "Choose 'stop' to get animal to be stop.\n"

        << "Choose 'move' to get animal to be move.\n"

        << "Choose 'create' to create a new animal from a type that you want.\n"

        << "Choose 'del' to delete a spesific animal.\n"

        << "Choose 'delAll' to delete all animals from the type that you chose.\n"

        << "Choose 'exit' to exit.\n";
}

void Zoo::run() 
{
    std::string command;
    std::string name;
    int index;
    char type;

    print_list();
    print_map();
    help();

    std::cin >> command;

    while (command != "exit") 
    {
        if (command == ".") 
        {
            step();
        }
        else if ("stop" == command) 
        {
            std::cout << "Enter the animal's index: \n";
            std::cin >> index;
            if (index >= animals.size())
                std::cout << "ERROR!! index out of range!";
            else 
            {
                stop(index);
                step();
            }
        }
        else if ("move" == command) 
        {
            std::cout << "Enter the animal's index: \n";
            std::cin >> index;
            if (index >= animals.size())
                std::cout << "ERROR!! index out of range!";
            else 
            {
                move(index);
                step();
            }
        }
        else if ("create" == command) {
            std::cout << "Enter L for Lion, M for Monkey, and D for Dog: \n";
            std::cin >> type;
            if (type == 'M' || type == 'L' || type == 'D') {
                std::cout << "Choose animal's name:\n";
                std::cin >> name;
                create(type, name);
                step();
            }
            else
                std::cout << "ERROR!! there is'nt such type of animal in the zoo!!";
        }
        else if ("del" == command) {
            std::cout << "Enter the animal's index:\n";
            std::cin >> index;
            if (index >= animals.size())
                std::cout << "ERROR!! index out of range!";
            else {
                del(index);
                step();
            }
        }
        else if ("delAll" == command) {
            std::cout << "Enter L for Lion, M for Monkey, and D for Dog:\n";
            std::cin >> type;
            if (type != 'M' && type != 'L' && type != 'G')
                std::cout << "ERROR!! there is'nt such type of animal in the zoo!!";
            else {
                delAll(type);
                step();
            }
        }
        else if ("help" == command)
            help();
        else
            std::cout << "There isn't such option!!" << std::endl;

        print_list();
        print_map();

        std::cin >> command;
    }
}




















