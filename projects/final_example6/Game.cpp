/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/20/2017
 **
 ** Description: The core class for running the finalproject program.
 **              Handles the execution of a single game where the
 **              object is to navigate a computer network with the
 **              ultimate goal of bringing down the University of
 **              Oregon web server. Players must collect various files
 **              to accomplish this goal. The game ends when the player
 **              runs out of 'hops' (representing the ability to
 **              perform actions) or successfully completes the mission.
 *********************************************************************/

#include "Game.hpp"

using std::cout;
using std::endl;


/*********************************************************************
 ** Description: Default constructor. Sets up the game by initializing
 **              the network devices via the various utility functions.
 **              Also sets the starting location.
 **
 ** Arguments: N/A.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
Game::Game() {
    std::srand(std::time(NULL));
    playing = true;
    wonGame = false;
    hopsLeft = 30;
    inventoryLimit = 5;
    DeviceFile tempFile;

    networkMap.push_back(new iPhone("Andrea\'s iPhone"));   // 0 -- Phone1
    networkMap.push_back(new iPhone("Tyler\'s iPhone"));    // 1 -- Phone2
    networkMap.push_back(new DesktopPC("Lab 1"));           // 2 -- Lab1
    networkMap.push_back(new DesktopPC("Lab 2"));           // 3 -- Lab2
    networkMap.push_back(new DesktopPC("Lab 3"));           // 4 -- Lab3
    networkMap.push_back(new DesktopPC("Admin"));           // 5 -- Admin
    networkMap.push_back(new Server("server03.uoregon.edu")); // 6 -- Server1
    networkMap.push_back(new Server("mail.uoregon.edu"));     // 7 -- Server2
    networkMap.push_back(new WebServer("web.uoregon.edu"));   // 8 -- WebServer

    initializeNetworkConnections();
    setNetworkDeviceDescriptions();
    setNetworkDeviceDifficulty();
    addFilesToDevices();

    // Set starting location
    currentLocation = networkMap[0];
    previousLocation = nullptr;
}


/*********************************************************************
 ** Description: Destructor. Ensures each Space is deleted before the
 **              program exits to prevent memory leaks.
 **
 ** Arguments: N/A.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
Game::~Game() {
    for (auto p : networkMap) {
        delete p;
    }
}


/*********************************************************************
 ** Description: The primary method of the Game class. Displays the
 **              intro splash screen with instructions and then falls
 **              into the main game loop. Exits upon either success
 **              or failure to complete the game's mission in the
 **              number of hops given.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::play() {
    int selection = 0;

    clearScreen();
    cout << "       __                   __  __" << endl;
    cout << "  ____/ /___ _____ ___     / /_/ /_  ___" << endl;
    cout << " / __  / __ `/ __ `__ \\   / __/ __ \\/ _ \\" << endl;
    cout << "/ /_/ / /_/ / / / / / /  / /_/ / / /  __/" << endl;
    cout << "\\__,_/\\__,_/_/ /_/ /_/   \\__/_/ /_/\\___/" << endl;
    cout << "       ____  __  __________ _______" << endl;
    cout << "      / __ \\/ / / / ____/ //_/ ___/" << endl;
    cout << "     / / / / / / / /   / ,<  \\__ \\" << endl;
    cout << "    / /_/ / /_/ / /___/ /| |___/ /" << endl;
    cout << "   /_____/\\____/\\____/_/ |_/____/" << endl << endl;
    
    
    cout << "             ___" << endl;
    cout << "           .=\"   \"=._.---." << endl;
    cout << "         .\"         c ' Y'`p" << endl;
    cout << "        /   ,       `.  w_/" << endl;
    cout << "        |   '-.   /     /" << endl;
    cout << "  _,..._|      )_-\\ \\_=.\\" << endl;
    cout << " `-....-'`------)))`=-'\"`'\"" << endl
         << endl << endl;

    cout << "You are B-v0rZ.exe, a vicious computer virus created by a\n"
            "well-meaning but misguided OSU Computer Science student.\n"
            "Your sole purpose is to reach the University of Oregon\n"
            "webserver (web.uoregon.edu) and bring it down! That will\n"
            "teach those disgusting ducks. Thankfully for you, their\n"
            "network is poorly secured, and its users are chronically\n"
            "incompetent." << endl;
    
    cout << endl << "PRESS ENTER TO CONTINUE..." << endl;
    std::getchar();
    clearScreen();

    cout << "You must hop from device to device across the network,\n"
            "exploiting them to progress, towards your ultimate goal: the\n"
            "web server. An exploit is not guaranteed, and you may need\n"
            "several attempts to exploit a device. This is especially true\n"
            "of hardened devices, such as school servers and lab computers."
            << endl << endl;
    
    cout << "Some devices will have files containing passwords you can use\n"
            "to increase your chances of exploiting a device. To attempt\n"
            "exploitation of the web server, you will need at least *3* of\n"
            "these password files. So keep an eye out, and pick up anything\n"
            "that might prove useful. You will not know which files contain\n"
            "passwords until you read their contents (though you can guess\n"
            "based on their file names). Once you have read a file, it will\n"
            "have an asterisk next to its file name if it contains passwords."
            << endl;
    
    cout << endl << "PRESS ENTER TO CONTINUE..." << endl;
    std::getchar();
    clearScreen();

    cout << "But… Don’t dilly-dally! You only have 30 hops before your time-\n"
            "to-live is out and you fail. The following actions take one hop:\n\n"
            "   - Moving between devices\n"
            "   - Viewing the contents of a file\n"
            "   - Stealing a file" << endl << endl;
    
    cout << "In addition, you are a small virus with limited internal storage\n"
            "space. You can only collect up to *5* files along the way, so\n"
            "choose wisely. You are not complex enough to swap files, so once\n"
            "you have collected 5 files, that’s it!" << endl;

    cout << endl << "PRESS ENTER TO CONTINUE..." << endl;
    std::getchar();
    clearScreen();
    cout << endl << "NETWORK MAP FROM INITIAL RECONNAISSENCE:"
         << endl << endl << endl;
    printMap();

    while (playing) {
        // Print game map
        cout << endl << "PRESS ENTER TO CONTINUE..." << endl;
        std::getchar();
        clearScreen();
        printMap();
        cout << endl << "============================================================" << endl;
        cout << "CURRENT LOCATION: " << currentLocation->getName();
        if (currentLocation->getExploited()) {
            cout << "  --  EXPLOITED\n" << endl;
        } else {
            cout << "  -- NOT EXPLOITED\n" << endl;
        }
        cout << "DEVICE DESCRIPTION:\n" << currentLocation->getDescription() << endl << endl;
        cout << "HOPS REMAINING: " << hopsLeft << endl;
        cout << "============================================================" << endl;
        if (currentLocation->getExploited()) {
            // Print exploited options
            selection = menu::getValidInt("CHOOSE AN ACTION\n"
                                          "[1] Move\n[2] View Files\n[3] Steal Files\n"
                                          "[4] Show Player Inverntory\n",
                                          "Invalid! Must enter 1 - 4\n",
                                          1, 4);

            switch (selection) {
                case 1:
                    clearScreen();
                    move();
                    break;
                case 2:
                    clearScreen();
                    printFile();
                    break;
                case 3:
                    clearScreen();
                    stealFile();
                    break;
                case 4:
                    clearScreen();
                    printInventory();
                    break;
            }
        } else {
            // Print non-exploited options
            selection = menu::getValidInt("CHOOSE AN ACTION\n"
                                          "[1] Exploit Device\n"
                                          "[2] Return to Previous Device\n"
                                          "[3] Show Player Inventory\n",
                                          "Invalid! Must enter 1 - 3\n",
                                          1, 3);
            switch (selection) {
                case 1:
                    clearScreen();
                    exploitCurrentDevice();
                    break;
                case 2:
                    clearScreen();
                    returnToPrevious();
                    break;
                case 3:
                    clearScreen();
                    printInventory();
                    break;
            }
        }

        if (hopsLeft <= 0) {
            playing = false;
        }
    }

    if (wonGame) {
        cout << endl << "YOU HAVE BROUGHT DOWN THE DUCKS!" << endl << endl;
        cout << "   _____  ____    ____  ______     __      ________ _____   _____ _ " << endl;
        cout << "  / ____|/ __ \\  |  _ \\|  ____|   /\\ \\    / /  ____|  __ \\ / ____| |" << endl;
        cout << " | |  __| |  | | | |_) | |__     /  \\ \\  / /| |__  | |__) | (___ | |" << endl;
        cout << " | | |_ | |  | | |  _ <|  __|   / /\\ \\ \\/ / |  __| |  _  / \\___ \\| |" << endl;
        cout << " | |__| | |__| | | |_) | |____ / ____ \\  /  | |____| | \\ \\ ____) |_|" << endl;
        cout << "  \\_____|\\____/  |____/|______/_/    \\_\\/   |______|_|  \\_\\_____/(_)" << endl;
        cout << endl << endl;
    } else {
        cout << endl << "YOU HAVE RUN OUT OF TIME!" << endl << endl;
        cout << "   _____          __  __ ______    ______      ________ _____" << endl;
        cout << "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\" << endl;
        cout << " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |" << endl;
        cout << " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /" << endl;
        cout << " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\" << endl;
        cout << "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\" << endl;
        cout << endl << endl;
    }
}


/*********************************************************************
 ** Description: A convenience function that reduces the hop count
 **              by one.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::decrementHop() {
    hopsLeft--;
}


/*********************************************************************
 ** Description: Connects the network devices according to the game
 **              map.
 **
 ** Arguments: None.
 **
 ** Preconditions: Assumes that the networkMap has been initialized and
 **                is in the proper order.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::initializeNetworkConnections() {
    // Phone1 is only connected to Server1
    networkMap[0]->setRight(networkMap[6]);

    // Phone2 is only connected to Server
    networkMap[1]->setTop(networkMap[6]);

    // Lab1 is only connected to Lab2
    networkMap[2]->setRight(networkMap[3]);

    // Lab2 is connected to Lab1, Lab3, and Server1
    networkMap[3]->setLeft(networkMap[2]);
    networkMap[3]->setRight(networkMap[4]);
    networkMap[3]->setBottom(networkMap[6]);

    // Lab3 is connected to Lab2 and Server2
    networkMap[4]->setLeft(networkMap[3]);
    networkMap[4]->setBottom(networkMap[7]);

    // Admin is only connected to Server2
    networkMap[5]->setTop(networkMap[7]);

    // Server1 is connected to Pnone1, Phone2, and Lab2
    networkMap[6]->setLeft(networkMap[0]);
    networkMap[6]->setBottom(networkMap[1]);
    networkMap[6]->setTop(networkMap[3]);

    // Server2 is connected to Lab3, Admin, and WebServer
    networkMap[7]->setTop(networkMap[4]);
    networkMap[7]->setBottom(networkMap[5]);
    networkMap[7]->setRight(networkMap[8]);

    // WebServer is only connected to Server2
    networkMap[8]->setLeft(networkMap[7]);
}


/*********************************************************************
 ** Description: Gives the appropriate description to each network
 **              device.
 **
 ** Arguments: None.
 **
 ** Preconditions: Assumes that the networkMap has been initialized and
 **                is in the proper order.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::setNetworkDeviceDescriptions() {
    networkMap[0]->setDescription("The iPhone of a typical, conformist UO student.");
    networkMap[1]->setDescription("Hey brah, this is muh phone, brah.");
    networkMap[2]->setDescription("A graffitti-coved hulk. Once promising, now a sad\n"
                                  "husk of wasted potential. Kinda like most UO students.");
    networkMap[3]->setDescription("A stained and battered machine. If you listen closely\n"
                                  "to its whirring hard-drive, it whispers, \"Kill me...\"");
    networkMap[4]->setDescription("A brand new, state of the art computer. Sparkling clean\n"
                                  "and untouched, as no one at UO has figured out how to\n"
                                  "use it.");
    networkMap[5]->setDescription("Covered in neckbeard hair, the filth that surrounds this\n"
                                  "computer is matched only by what resides on its hard drive.");
    networkMap[6]->setDescription("A server filled with improperly used memes. Like the kind\n"
                                  "your Aunt posts on Facebook years after they have gone out\n"
                                  "of fashion. You suppress a gag reflex.");
    networkMap[7]->setDescription("This server used to serve a purpose, but no one knows what\n"
                                  "anymore. Currently, it is so bloated with malware that all\n"
                                  "it does is mine Bitcoins for the Russian Mafia.");
    networkMap[8]->setDescription("The world's only surviving website hosted using AOL software.");
}


/*********************************************************************
 ** Description: Adds the appropriate files to each network device.
 **
 ** Arguments: None.
 **
 ** Preconditions: Assumes that the networkMap has been initialized and
 **                is in the proper order.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::addFilesToDevices() {
    networkMap[0]->addFile(DeviceFile("Test Answers.doc",
                                      "1: A\n"
                                      "2: B\n"
                                      "3: A\n"
                                      "4: C\n"
                                      "5: D\n"
                                      "6: B\n",
                                      false));

    networkMap[0]->addFile(DeviceFile("Cheating Links.txt",
                                      "www.testanswers.com\n"
                                      "ftp.uoregon.edu/cs101/~reilly/answers2017\n"
                                      "www.lazyfrosh.biz\n",
                                      false));

    networkMap[0]->addFile(DeviceFile("Passwds n stuff.txt",
                                      "12345\n"
                                      "password\n"
                                      "opensesame\n"
                                      "asdf\n",
                                      true));

    networkMap[1]->addFile(DeviceFile("SMS_LOG.txt",
                                      "-hey mom need mor money\n"
                                      " No travis, not until your grades improve –\n"
                                      "- but maaaaaaaaaaaaahhhhhhmmmmm!!!!\n"
                                      " Ok. But this is the LAST time! – \n",
                                      false));
   
    networkMap[1]->addFile(DeviceFile("Archived Emails.rar",
                                      "RE: Reset Password\n"
                                      "FW: FW: fw: fw: FW: LOL FUNNY KITTEN PLAYS THE BONGOS\n"
                                      "Slam Poetry Fest ‘17\n",
                                      true));
   
    networkMap[1]->addFile(DeviceFile("Playbook.pdf",
                                      "Quack-Quack-99:\n"
                                      "     X   X    X\n"
                                      "X      X X X X      X X\n"
                                      "O      O O O O      O O\n"
                                      "          O\n"
                                      "          O  O---->\n",
                                      false));

    networkMap[2]->addFile(DeviceFile("Falsified Lab Results.doc",
                                      "Student IQ Results:\n"
                                      "78,87,32,55,90,23,34,53,12,75,79,30,23,24,40\n"
                                      "NOTE: We cannot make these public! Keep sampling\n"
                                      "until we get the results we want. Pollsters do\n"
                                      "it all the time – it’s called statistics.\n",
                                      false));
   
    networkMap[2]->addFile(DeviceFile("~x0X-Mathematica_pirated-X0x~.zip",
                                      "46696C652844657669636546696C6528\n"
                                      "224172636869766564456D61696C732E\n"
                                      "726172222C2022222C20747275652929\n"
                                      "3B206E6574776F726B4D61705B315D2D\n"
                                      "3E61646446696C652844657669636546\n"
                                      "696C652822506C6179626F6F6B2E7064\n"
                                      "66222C2022222C2066616C736529293B\n"
                                      "20206E6574776F726B4D61705B325D2D\n"
                                      "3E61646446696C652844657669636546\n"
                                      "696C65282246616C7369666965644C61\n"
                                      "62526573756C74732E646F63222C2022\n"
                                      "222C2066616C736529293B206E657477\n"
                                      "6F726B4D61705B325D2D3E6164644669\n",
                                      false));
   
    networkMap[2]->addFile(DeviceFile("D&D Character Sheet.doc",
                                      "Name: Ander Dundragon \n"
                                      "STR: 17\n"
                                      "CHR: 13\n"
                                      "CON: 15\n"
                                      "Background: Born on the fjords of Morlayi’li’iku,\n"
                                      "in the ancestral village of the Darvisher-und-Dragon\n"
                                      "clan, Ander was drawn to the dark arts at an early age…\n",
                                      false));

    networkMap[3]->addFile(DeviceFile("Idiot's Guide to Computer Science",
                                      "Just hire an OSU grad.",
                                      false));
   
    networkMap[3]->addFile(DeviceFile("Best of John Tesh.wav",
                                      "03C2B7C3BFC3B401E280A2C3BF1001C2\n"
                                      "AFC3BF6320C39BC3BFC397C3BF182075\n"
                                      "C3BF74205BC3BFC39220E2809DC3BF08\n"
                                      "01C3AAC3BFC39B20262020201220C3A4\n"
                                      "C3BEE280A0C3BF5CC3BD7EC3BEC3ADC3\n"
                                      "BB3FC3BDC3BAC3BA5CC3BCC2B0C3BA32\n"
                                      "C3BC10C3BBC2AFC3BCC3AAC3BBC692C3\n"
                                      "BDC3B4C3BC5FC3BE06C3BE14C3BF0EC3\n"
                                      "BFC5BDC3BFC3B9C3BFC39AC3BFC38620\n"
                                      "1520C29D014420E2809C024620C2B103\n",
                                      false));
   
    networkMap[3]->addFile(DeviceFile("web_log.txt",
                                      "www.stackoverflow.com/?q=what-is-a-c++\n"
                                      "www.reddit.com/mylittlepony4life\n"
                                      "www.stackoverflow.com/?q=how-many-bytes-in-an-internet\n"
                                      "www.match.com/faq/amitoouglyforlove\n",
                                      true));

    networkMap[4]->addFile(DeviceFile("admin_correspondence.pst",
                                      "RE: User Passwords\n"
                                      "RE:RE:RE:No such thing as groot access\n"
                                      "FW:FW:php <3\n",
                                      true));
   
    networkMap[4]->addFile(DeviceFile("Nike-Vatican Fraud Allegations.pdf",
                                      "Mauris eget quam eu orci scelerisque tincidunt at in lorem. In\n"
                                      "vitae tincidunt tortor. Cras fringilla, sem et finibus viverra,\n"
                                      "sem tortor vestibulum augue, eu auctor velit turpis at orci.\n"
                                      "Cras condimentum lacinia neque vel interdum. Pellentesque posuere\n"
                                      "mauris metus, sed hendrerit mi ultrices vulputate. Pellentesque\n"
                                      "suscipit lacinia lacus, sit amet tincidunt neque semper id.\n",
                                      false));
   
    networkMap[4]->addFile(DeviceFile("LibraryAccessLog.txt",
                                      "Head First Phrenology\n"
                                      "Fungal Infection Self-Care\n"
                                      "Notes from the 34th Annual Conference on the Spatial\n"
                                      "  Dynamics of Subterranean Parental-Domesticity Among\n"
                                      "  College-Age Residents of Central Oregon\n",
                                      false));

    networkMap[5]->addFile(DeviceFile("Fan Letter.doc",
                                      "Dear Mr. Nimoy,\n"
                                      "Or should I say, Mr. Spock? Hah! First of all: may the force be\n"
                                      "with you. Hah! As you can see, I’m a pretty hilarious guy. I know\n"
                                      "you sometimes write poetry, and I think we could work together\n"
                                      "well. Our combination of logic and humor could be ‘out of this\n"
                                      "world.’ Hah!\n",
                                      false));
   
    networkMap[5]->addFile(DeviceFile("Neckbeard Grooming 101.pdf",
                                      "The primary advantage that the neckbeard connoisseur has over his\n"
                                      "fellow man is freedom. The total absence of loved ones and social\n"
                                      "connections is both freeing and empowering. This enables you to\n"
                                      "focus your time and effort on your favorite things: a refined sense\n"
                                      "of superiority and that glorious tuft of excellence clinging to\n"
                                      "your Adam’s apple.\n",
                                      false));
   
    networkMap[5]->addFile(DeviceFile("HTML for Kids: Tags, Tags, Tags!",
                                      "<like><angle><brackets><?>\n"
                                      "<you><will><love><this><book><!>\n"
                                      "</!></book></this></love></will></you>\n"
                                      "</?></brackets></angle></like>\n",
                                      false));

    networkMap[6]->addFile(DeviceFile("StudentProject.cpp",
                                      "#include <standardi/o>\n"
                                      "Integer main() {\n"
                                      "    // WHY THIS NO WORK!?!?!?!?!\n"
                                      "    Print “cout”\n"
                                      "    Print “<<”\n"
                                      "    Print “Hello, World!”\n"
                                      "    Print “<<”\n"
                                      "    Print “endl”\n"
                                      "}\n",
                                      false));
   
    networkMap[6]->addFile(DeviceFile("grade_gpa_2017.txt",
                                      "C,C-,B-,D,D,F,1.2\n"
                                      "F,F,F,D,F,D-,F,0.2\n"
                                      "C-,D,C-,D-,F,F,0.9\n",
                                      false));
   
    networkMap[6]->addFile(DeviceFile("login_attempts.txt",
                                      "admin!QAZ2wsx\n"
                                      "root1234!@#$\n"
                                      "bobbybS3crEtP455w0RD\n",
                                      true));

    networkMap[7]->addFile(DeviceFile("Linux for Dummies.pdf",
                                      "Open-source Linux is a popular alternative to Microsoft Windows,\n"
                                      "and if you choose to use this low-cost or free operating system,\n"
                                      "you need to know some basic Linux commands to configure, operate,\n"
                                      "and interact with your system smoothly.\n",
                                      false));
   
    networkMap[7]->addFile(DeviceFile("Secrets of Pheremones: Even you can find a mate!.pdf",
                                      "Smell has long been the enemy of the bachelor. Now, let it become\n"
                                      "your ally! With our patented, scientific, proven system, you will\n"
                                      "be the most popular person at your next LARPing session.\n",
                                      false));
   
    networkMap[7]->addFile(DeviceFile("admin_log.txt",
                                      "/de/var/log/lastlog\n"
                                      "TCP    192.168.1.103:53639    209.107.220.181:https  ESTABLISHED\n"
                                      "TCP    192.168.1.103:55142    54.34.26.255:https    ESTABLISHED\n"
                                      "/var/log/messages\n"
                                      "TCP    192.168.1.103:55160    x33-199-5-89:http     CLOSE_WAIT\n"
                                      "/var/log/wtmpv/null\n",
                                      true));
}


/*********************************************************************
 ** Description: Prints out the name of each file in the player's
 **              inventory.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::printInventory() {
    if (inventory.size()) {
        cout << endl << "Your Files:" << endl;
        for (auto f : inventory) {
            cout << f.getName();
            // If the player has read the file, indicate
            // if passwords are present
            if (f.getRead() && f.getContainsPasswords()) {
                cout << "*" << endl;
            } else {
                cout << endl;
            }
        }
    } else {
        cout << endl << "Inventory empty!" << endl;
    }
}


/*********************************************************************
 ** Description: Attempts to exploit the current device where the
 **              player is located. Rolls a number 1-100 and adds
 **              a bonus for each password file the user has in their
 **              inventory. If the player's roll is higher than the
 **              difficulty of the device, it is considered exploited
 **              and the player can then access its network iterfaces
 **              and files.
 **
 ** Arguments: N/A.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
void Game::exploitCurrentDevice() {
    decrementHop();

    cout << endl << "[!] ATTEMPTING TO EXPLOIT " << currentLocation->getName()
         << endl << endl;

    std::chrono::seconds pause(1);
    std::this_thread::sleep_for(pause);

    int roll = menu::getRandomIntInRange(1, 100);
    int numPasswords = 0;

    // Increase the odds of success based on
    // password files picked up from devices
    for (auto f : inventory) {
        if (f.getContainsPasswords()) {
            numPasswords++;
        }
    }

    // 10% increase per password file
    roll += numPasswords * 10;

    if (roll > currentLocation->getDifficulty()) {
        if (currentLocation == networkMap[8]) {
            // Only allow the final server to be exploited
            // if the player has at least 3 password files
            if (numPasswords > 2) {
                currentLocation->exploit();
                hackingAnimation();

                cout << "[!] EXPLOIT SUCCESSFUL" << endl;

                wonGame = true;
                playing = false;
            } else {
                cout << "[!] MORE PASSWORD FILES NEEDED TO HACK SERVER" << endl;
            }
        } else {
            currentLocation->exploit();
            hackingAnimation();

            cout << "[!] EXPLOIT SUCCESSFUL" << endl;
        }
    } else {
        if (currentLocation == networkMap[8] && numPasswords < 3) {
            hackingAnimation();

            cout << "[!] MORE PASSWORD FILES NEEDED TO HACK SERVER" << endl;
        } else {
            hackingAnimation();

            cout << "[!] EXPLOIT FAILED -- TRY AGAIN" << endl;
        }
    }
}


/*********************************************************************
 ** Description: Prints out the name of each file on the current device
 **              in a menu format that allows the player to select one
 **              to steal it and put it in their own inventory.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::stealFile() {
    int subSelection = 0;
    std::vector<DeviceFile> files;

    cout << endl << endl << "CHOOSE FILE TO STEAL:" << endl;

    files = currentLocation->getFiles();
    
    for (size_t i = 0; i < files.size(); ++i) {
        cout << i + 1 << "> " << files[i].getName();
        // If the player has read the file, indicate
        // if passwords are present
        if (files[i].getRead() && files[i].getContainsPasswords()) {
            cout << "*" << endl;
        } else {
            cout << endl;
        }
    }

    cout << files.size() + 1 << "> Return" << endl;

    subSelection = menu::getValidInt("", "Invlaid! Must choose a file or return",
                                     1, files.size() + 1);

    if (static_cast<size_t>(subSelection) != files.size() + 1) {
        if (inventory.size() < inventoryLimit) {
            decrementHop();
            fileTransferAnimation();

            cout << endl << "[!] FILE TRANSFER SUCCESSFUL" << endl;

            inventory.push_back(currentLocation->takeFile(subSelection - 1));
        } else {
            cout << endl << "[!] CANNOT STEAL -- INVENTORY AT CAPACITY" << endl;
        }
    }
}


/*********************************************************************
 ** Description: Prints out the name of each file on the current device
 **              in a menu format that allows the player to select one
 **              to view its contents.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::printFile() {
    int subSelection = 0;
    std::vector<DeviceFile> files;
    cout << endl << endl << "CHOOSE FILE TO VIEW CONTENTS:" << endl;
    files = currentLocation->getFiles();
    
    for (size_t i = 0; i < files.size(); ++i) {
        cout << i + 1 << "> " << files[i].getName();
        // If the player has read the file, indicate
        // if passwords are present
        if (files[i].getRead() && files[i].getContainsPasswords()) {
            cout << "*" << endl;
        } else {
            cout << endl;
        }
    }

    cout << files.size() + 1 << "> Return" << endl;

    subSelection = menu::getValidInt("", "Invlaid! Must choose a file or return",
                                     1, files.size() + 1);

    if (static_cast<size_t>(subSelection) != files.size() + 1) {
        decrementHop();
        cout << files[subSelection - 1].getContents() << endl;
        currentLocation->setFileAsRead(subSelection - 1);
    }
}


/*********************************************************************
 ** Description: Prints out the connections of the current device and
 **              allows the player to select a device to move to.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::move() {
    int subSelection = 0;
    std::vector<Space *> tempConnections;
    
    printMap();
    cout << endl << "========================================================" << endl;
    cout << "CURRENT LOCATION: " << currentLocation->getName();

    if (currentLocation->getExploited()) {
        cout << "  --  EXPLOITED" << endl;
    } else {
        cout << "  -- NOT EXPLOITED" << endl;
    }

    cout << "DEVICE DESCRIPTION:\n" << currentLocation->getDescription() << endl;
    cout << "HOPS REMAINING: " << hopsLeft << endl;
    cout << "========================================================" << endl;

    tempConnections.clear();
    tempConnections.push_back(currentLocation->getTop());
    tempConnections.push_back(currentLocation->getBottom());
    tempConnections.push_back(currentLocation->getLeft());
    tempConnections.push_back(currentLocation->getRight());

    cout << endl << "Choose an interface to transmit to another device:" << endl;

    for (size_t i = 0; i < tempConnections.size(); ++i) {
        if (tempConnections[i]) {
            cout << i + 1 << " => " << tempConnections[i]->getName() << endl;
        } else {
            cout << i + 1 << " => NULL -- *NO CONNECTION EXISTS*" << endl;
        }
    }
    cout << 5 << ". Return" << endl;

    subSelection = menu::getValidInt("", "Invalid! Must be 1 - 5", 1, 5);

    if (subSelection == 5) {
        // Do nothing to return to previous menu
    } else if (static_cast<size_t>(subSelection) <= tempConnections.size()) {
        if (tempConnections[subSelection - 1]) {
            decrementHop();
            clearScreen();
            cout << "[!] TRANSMITTING TO "
                 << tempConnections[subSelection - 1]->getName()
                 << endl << endl;

            std::chrono::seconds pause(1);
            std::this_thread::sleep_for(pause);

            transmissionAnimation();

            Space *temp = currentLocation;
            currentLocation = tempConnections[subSelection - 1];
            previousLocation = temp;
        } else {
            cout << "No connection on that interface" << endl;
        }
    } else {
        cout << "No connection in that direction!" << endl;
    }
}


/*********************************************************************
 ** Description: Allows a player to move back to the last device they
 **              were on.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::returnToPrevious() {
    if (previousLocation) {
        decrementHop();

        cout << "[!] RETURNING TO " << previousLocation->getName() << endl << endl;

        std::chrono::seconds pause(1);
        std::this_thread::sleep_for(pause);

        transmissionAnimation();

        Space *temp = currentLocation;
        currentLocation = previousLocation;
        previousLocation = temp;
    } else {
        cout << endl << "[!] CANNOT MOVE BACK: STARTED @ THIS DEVICE" << endl;
    }
}


/*********************************************************************
 ** Description: Prints the entire network out to aid the player with
 **              planning and navigation.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::printMap() {
    cout << "  +-----+          +-----+           +-----+" << endl;
    cout << "  |~$   |          |~$   |           |~$   |" << endl;
    cout << "  |     +----------+     +-----------+     |" << endl;
    cout << "  \\-----/          \\-----/           \\-----/" << endl;
    cout << "[=========]      [=========]       [=========]"<< endl;
    cout << "[=========]      [=========]       [=========]"<< endl;
    cout << "   Lab 1            Lab 2             Lab 3" << endl;
    cout << "                      +                  +" << endl;
    cout << "                      |                  |" << endl;
    cout << "                      |                  |" << endl;
    cout << "   +-=-+          +---+--+            +--+---+            +------+" << endl;
    cout << "   || ||          | ==== |            | ==== |            | ==== |" << endl;
    cout << "   ||_||          +------+            +------+            +------+" << endl;
    cout << "   | o +----------+ ==== |            | ==== +------------+ ==== |" << endl;
    cout << "   +---+          +------+            +------+            +------+" << endl;
    cout << "  Andrea's        | ==== |            | ==== |            | ==== |" << endl;
    cout << "   iPhone         +------+            +------+            +------+" << endl;
    cout << "            server03.uoregon.edu   mail.uoregon.edu   web.uoregon.edu" << endl;
    cout << "                     +                    +" << endl;
    cout << "                     |                    |" << endl;
    cout << "                   +-=-+               +--+--+" << endl;
    cout << "                   || ||               |~$   |" << endl;
    cout << "                   ||_||               |     |" << endl;
    cout << "                   | o |               \\-----/" << endl;
    cout << "                   +---+             [=========]"<< endl;
    cout << "                  Tyler's            [=========]"<< endl;
    cout << "                   iPhone               Admin" << endl;
    cout << endl << endl << endl;
}


/*********************************************************************
 ** Description: Sets the individual difficulty of each network
 **              device.
 **
 ** Arguments: None.
 **
 ** Preconditions: Assumes that networkMap has been properly initialized.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::setNetworkDeviceDifficulty() {
    networkMap[0]->setDifficulty(20);
    networkMap[1]->setDifficulty(20);
    networkMap[2]->setDifficulty(40);
    networkMap[3]->setDifficulty(50);
    networkMap[4]->setDifficulty(60);
    networkMap[5]->setDifficulty(80);
    networkMap[6]->setDifficulty(70);
    networkMap[7]->setDifficulty(70);
    networkMap[8]->setDifficulty(90);
}


/*********************************************************************
 ** Description: Prints 100 blank lines to effectively clear the screen.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::clearScreen() {
    cout << std::string(100, '\n') << endl;
}


/*********************************************************************
 ** Description: Prints a random range of Matrix-like hacking
 **              animation. Adapted from the code at:
 **              https://helloacm.com/the-matrix-printing-animation-in-c/
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::hackingAnimation() {
    int temp = menu::getRandomIntInRange(15, 40);
    for (int i = 0; i < temp; ++i) {
        for (int j = 0; j < 80; ++j) {
            cout << generateRandomChar();
        }
        cout << endl;
        std::chrono::milliseconds pause(50);
        std::this_thread::sleep_for(pause);
    }
    cout << endl << endl;
}


/*********************************************************************
 ** Description: Prints a binary animation for file transfers.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::fileTransferAnimation() {
    int temp = menu::getRandomIntInRange(30, 50);
    for (int i = 0; i < temp; ++i) {
        for (int j = 0; j < 80; ++j) {
            cout << menu::getRandomIntInRange(0, 1);
        }
        cout << endl;
        std::chrono::milliseconds pause(20);
        std::this_thread::sleep_for(pause);
    }
    cout << endl << endl;
}


/*********************************************************************
 ** Description: Returns a random character for use in creating various
 **              animations. Adapted from the code at:
 **              https://helloacm.com/the-matrix-printing-animation-in-c/
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
char Game::generateRandomChar() {
    int temp = menu::getRandomIntInRange(1, 4);
    int value;

    switch (temp) {
        case 1:
            value = 48 + rand() % 10;
            break;
        case 2:
            value = 97 + rand() % 26;
            break;
        case 3:
            value = 32;
            break;
        case 4:
            value = 65 + rand() % 26;
            break;
    }

    return static_cast<char>(value);
}


/*********************************************************************
 ** Description: Prints a bunch of random IP address to simulate
 **              transmission between network devices.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Game::transmissionAnimation() {
    int temp = menu::getRandomIntInRange(3, 10);
    for (int i = 0; i < temp; ++i) {
        cout << rand() % 256 << "."
             << rand() % 256 << "."
             << rand() % 256 << "."
             << rand() % 256
             << "\t*\t" << rand() % 65535
             << "\t->\t"
             << rand() % 65535 << "\t*\t"
             << rand() % 256 << "."
             << rand() % 256 << "."
             << rand() % 256 << "."
             << rand() % 256 << endl;
        std::chrono::milliseconds pause(300);
        std::this_thread::sleep_for(pause);
    }
    cout << endl << "[!] TRANSMISSION COMPLETE" << endl;
}
