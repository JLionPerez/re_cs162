#include "menu.hpp"

void Menu::end()
{
    do
    {
        cin.clear();
        cin.ignore(9999, '\n');

        cout << "\nDo you want to play again?" << endl;
        cout << "\t1) Yes" << endl;
        cout << "\t2) No" << endl;
        cout << "\nEnter: ";
        cin >> again;

        if (again < 1 || again > 2 || cin.fail())
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        else if (again == 2) { cout << "\nBye bye!" << endl; return; }

    } while(again < 1 || again > 2 || cin.fail());
    
    beginning();
}

void Menu::beginning()
{
    cout << "\nWelcome to Linen! A dream to wake from." << endl; 

    do
    {
        cout << "\nWould you like to play?" << endl;
        cout << "\t1) Yes" << endl;
        cout << "\t2) No" << endl;
        cout << "\nEnter: ";
        cin >> option;

        if (option < 1 || option > 2 || cin.fail())
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        else if (option == 2) { cout << "\nBye bye!" << endl; return; }

    } while(option < 1 || option > 2 || cin.fail());

    //proceed
    story();

    //starting room
    

    end();
}

void Menu::story()
{
    str = "\nYou've been having reoccurring dreams of a mystical place. \n\nA place comprised of a field of black \033[1;90mroses\033[0m,\na misty lavendar \033[1;35mforest\033[0m,\nan azure \033[1;94mbeach\033[0m with a glittering sea,\na viridian \033[1;92mcabin\033[0m in the middle of an open field,\na fiery scarlet \033[1;31mdesert\033[0m,\nand a cyan \033[1;36mlake\033[0m in the middle of a bleak land.";
    typewriter(str, 30);

    str = "\nHowever, this time there's an entity after you";
    typewriter(str, 30);
    sleep_for(seconds(1));  //dramatic pause
    str = "and you can't wake up from your dream.";
    typewriter(str, 60);

    cout << "\n\t\t* GOAL* " << endl;
    str = "\nYour task is to find a way to wake yourself up, by exploring each area of this mysterious dream.";
    typewriter(str, 30);

    str = "\nAs you explore, you will meet unique characters that reside in these areas.\nYou'll have to convince them to give you certain items,\neither by persuassion or by force.";
    typewriter(str, 30);

    str = "\nOnce you've gathered all the necessary items to defeat the final boss at the lake, you'll be able to wake up.\nBut, if your health is depleted during your journey\nyou will never wake up again.";
    typewriter(str, 30);

    layout();
}

void Menu::layout()
{
    cout << "\nHere's the layout of the dream:" << endl;
    cout << "           ------------" << endl;
    cout << "           |          |" << endl;
    cout << "           |   \033[1;94mBEACH\033[0m  |" << endl;
    cout << "           |          |" << endl;
    cout << "---------------------------------" << endl;
    cout << "|          |          |         |" << endl;
    cout << "|  \033[1;31mDESERT\033[0m  |  \033[1;35mFOREST\033[0m  |  \033[1;92mCABIN\033[0m  |" << endl;
    cout << "|          |          |         |" << endl;
    cout << "---------------------------------" << endl;
    cout << "           |          |" << endl;
    cout << "           |   \033[1;90mROSES\033[0m  |" << endl;
    cout << "           |          |" << endl;
    cout << "           ------------" << endl;
    cout << "           |          |" << endl;
    cout << "           |   \033[1;36mLAKE\033[0m   |" << endl;
    cout << "           |          |" << endl;
    cout << "           ------------" << endl;
}