#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;

void gameMenu();
void avengersLists();
void selectYourAvenger(int avenger);
void villainAppear();
void captainVsThanos(int avenger);
void thorVsThanos(int avenger);
void ironmanVsThanos(int avenger);
void thanosAttack(int avenger);
void thorSkills();
void captainSkills();
void ironmanSkills();
void lifeStatus();
void matchResult();

int skill, computer, playerLife = 100, thanosLife = 100;

int main()
{
    int choice, avenger;
    char fight;

    system("Color F4");

    menu:
    gameMenu();

    cout << "\t\t\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            select:
            avengersLists();

            cout << "\t\t\t\t\t\t\t\tChoose your avenger: ";
            cin >> avenger;
            selectYourAvenger(avenger);

            choose:
            cout << "\t\t\t\t\t\t\t\tChoose [F/f] - to fight or [B/b] - to change your avenger: ";
            cin >> fight;

            if(fight == 'F' || fight == 'f'){
                villainAppear();
                system("CLS");

                if(avenger == 1){
                    while(playerLife > 0 && thanosLife > 0){
                        captainVsThanos(avenger);
                    }
                }

                else if(avenger == 2){
                    while(playerLife > 0 && thanosLife > 0){
                        thorVsThanos(avenger);
                    }
                }

                else if(avenger == 3){
                    while(playerLife > 0 && thanosLife > 0){
                        ironmanVsThanos(avenger);
                    }
                }
            }

            else if(fight == 'B' || fight == 'b'){
                goto select;
            }

            else{
                system("CLS");
                goto choose;
            }
            break;

        case 2:
            return 0;
            break;

        default:
            system("CLS");
            goto menu;
    }
    system("CLS");
    cout << "\n\n\n";
    matchResult();
}

void gameMenu(){
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t+---------------------------------------+\n";
    cout << "\t\t\t\t\t\t\t\t|   A V E N G E R S  M I N I  G A M E   |\n";
    cout << "\t\t\t\t\t\t\t\t+---------------------------------------+\n\n\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t[1] - S T A R T\n\n";
    cout << "\t\t\t\t\t\t\t\t\t[2] - E X I T\n\n\n\n\n";
}

void avengersLists(){
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t[1] - C A P T A I N  A M E R I C A\n\n";
    cout << "\t\t\t\t\t\t\t\t[2] - T H O R\n\n";
    cout << "\t\t\t\t\t\t\t\t[3] - I R O N  M A N\n\n\n\n\n";
}

void selectYourAvenger(int avenger){
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n";
    switch(avenger){
        case 1:
            cout << "\t\t\t\t\t\t\t\tYou have chosen Captain America\n\n\n\n\n";
            break;

        case 2:
            cout << "\t\t\t\t\t\t\t\tYou have chosen Thor\n\n\n\n\n";
            break;

        case 3:
            cout << "\t\t\t\t\t\t\t\tYou have chosen Ironman\n\n\n\n\n";
            break;
    }
}

void villainAppear(){
    system("CLS");
    Sleep(5000);

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\tT H A N O S  H A S  A P P E A R E D\n\n\n\n\n";
    system("PAUSE");
}

void captainVsThanos(int avenger){
    skillA:
    captainSkills();

    lifeStatus();

    cout << "\t\t\t\t\t\t\t\tChoose a skill: ";
    cin >> skill;
    cout << "\n\n";

    if(skill == 1){
        cout << "\t\t\t\t\t\t\t\tCaptain America used THROW SHIELD\n";

        if(computer == 2){
            thanosLife = thanosLife - (25 - 10);
            cout << "\t\t\t\t\t\t\t\t>> Low damage, Thanos activated Higher Resistance <<\n";
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 25;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else if(skill == 2){
        cout << "\t\t\t\t\t\t\t\tCaptain America used THROW KICK\n";

        if(computer == 2){
            thanosLife = thanosLife - (20 - 10);
            cout << "\t\t\t\t\t\t\t\t>> Low damage, Thanos activated Higher Resistance <<\n";
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 20;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else if(skill == 3){
        cout << "\t\t\t\t\t\t\t\tCaptain America used SHIELD\n";
        cout << "\t\t\t\t\t\t\t\t>> Immune to next attack <<\n";

        if(computer == 2){
            thanosLife -= 0;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 0;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else{
        system("CLS");
        goto skillA;
    }

    Sleep(2000);
    thanosAttack(avenger);
    Sleep(2000);
}

void thorVsThanos(int avenger){
    skillB:
    thorSkills();
    lifeStatus();
    cout << "\t\t\t\t\t\t\t\tChoose a skill: ";
    cin >> skill;
    cout << "\n\n";

    if(skill == 1){
        cout << "\t\t\t\t\t\t\t\tThor used LIGHTNING STRIKE\n";

        if(computer == 2){
            thanosLife = thanosLife - (30 - 10);
            cout << "\t\t\t\t\t\t\t\t>> Low damage, Thanos activated Higher Resistance <<\n";
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 30;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else if(skill == 2){
        cout << "\t\t\t\t\t\t\t\tThor used STORM BREAKER SLASH\n";

        if(computer == 2){
            thanosLife = thanosLife - (20 - 10);
            cout << "\t\t\t\t\t\t\t\t>> Low damage, Thanos activated Higher Resistance <<\n";
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 20;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else if(skill == 3){
        cout << "\t\t\t\t\t\t\t\tThor used FLY\n";
        cout << "\t\t\t\t\t\t\t\t>> Lesser Damage Will be Taken <<\n";

        if(computer == 2){
            thanosLife -= 0;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 0;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else{
        system("CLS");
        goto skillB;
    }

    Sleep(2000);
    thanosAttack(avenger);
    Sleep(2000);
}

void ironmanVsThanos(int avenger){
    skillC:
    ironmanSkills();
    lifeStatus();
    cout << "\t\t\t\t\t\t\t\tChoose a skill: ";
    cin >> skill;
    cout << "\n\n";

    if(skill == 1){
        cout << "\t\t\t\t\t\t\t\tIronman used BEAM\n";

        if(computer == 2){
            thanosLife = thanosLife - (20 - 10);
            cout << "\t\t\t\t\t\t\t\t>> Low damage, Thanos activated Higher Resistance <<\n";
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 20;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else if(skill == 2){
        cout << "\t\t\t\t\t\t\t\tIronman used MEASILES\n";

        if(computer == 2){
            thanosLife = thanosLife - (20 - 10);
            cout << "\t\t\t\t\t\t\t\t>> Low damage, Thanos activated Higher Resistance <<\n";
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }

        else{
            thanosLife -= 20;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else if(skill == 3){
        cout << "\t\t\t\t\t\t\t\tIronman used SUIT REGENARATION\n";
        cout << "\t\t\t\t\t\t\t\t>> Iron man's HP will be Added by 10 <<\n";

        if(playerLife > 90){
            if(computer == 2){
                playerLife = 100;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << endl;
                thanosLife -= 0;
                cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
            }

            else{
                playerLife = 100;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << endl;
                thanosLife -= 0;
                cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
            }
        }

        else{
            playerLife += 10;
            cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << endl;
            thanosLife -= 0;
            cout << "\t\t\t\t\t\t\t\tThanos Life -> " << thanosLife << "\n\n";
        }
    }

    else{
        system("CLS");
        goto skillC;
    }

    Sleep(2000);
    thanosAttack(avenger);
    Sleep(2000);
}

void thanosAttack(int avenger){
    srand(time(NULL));
    computer = 1 + (rand() % 3);

    if(avenger == 1){
        if(computer == 1){
            cout << "\t\t\t\t\t\t\t\tThanos used PUNCH\n";

            if(skill == 3){
                playerLife -= 0;
                cout << "\t\t\t\t\t\t\t\t>> No damage, Captain America is immune <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 20;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }

        else if(computer == 2){
            cout << "\t\t\t\t\t\t\t\tThanos used INFINITY GAUTLET\n";
            cout << "\t\t\t\t\t\t\t\t>> Passive: Higher Resistance Activated <<\n";

            if(skill == 3){
                playerLife -= 0;
                cout << "\t\t\t\t\t\t\t\t>> No damage, Captain America is immune <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 30;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }

        else{
            cout << "\t\t\t\t\t\t\t\tThanos used DRAW SWORD\n";

            if(skill == 3){
                playerLife -= 0;
                cout << "\t\t\t\t\t\t\t\t>> No damage, Captain America is immune <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 10;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }
    }

    else if(avenger == 2){
        if(computer == 1){
            cout << "\t\t\t\t\t\t\t\tThanos used PUNCH\n";

            if(skill == 3){
                playerLife -= 0;
                cout << "\t\t\t\t\t\t\t\t>> No damage, Thor is flying <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 20;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }

        else if(computer == 2){
            cout << "\t\t\t\t\t\t\t\tThanos used INFINITY GAUTLET\n";
            cout << "\t\t\t\t\t\t\t\t>> Passive: Higher Resistance Activated <<\n";

            if(skill == 3){
                playerLife = playerLife - (30 - 15);
                cout << "\t\t\t\t\t\t\t\t>> Lesser Damage, Thor is flying <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 30;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }

        else{
            cout << "\t\t\t\t\t\t\t\tThanos used DRAW SWORD\n";

            if(skill == 3){
                playerLife -= 0;
                cout << "\t\t\t\t\t\t\t\t>> No damage, Thor is flying <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 10;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }
    }

    else{
        if(computer == 1){
            cout << "\t\t\t\t\t\t\t\tThanos used PUNCH\n";

            if(skill == 3){
                playerLife -= 20;
                cout << "\t\t\t\t\t\t\t\t>> Ironman used Suit Regeneration <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 20;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }

        else if(computer == 2){
            cout << "\t\t\t\t\t\t\t\tThanos used INFINITY GAUTLET\n";
            cout << "\t\t\t\t\t\t\t\t>> Passive: Higher Resistance Activated <<\n";

            if(skill == 3){
                playerLife -= 30;
                cout << "\t\t\t\t\t\t\t\t>> Ironman used Suit Regeneration <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 30;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }

        else{
            cout << "\t\t\t\t\t\t\t\tThanos used DRAW SWORD\n";

            if(skill == 3){
                playerLife -= 10;
                cout << "\t\t\t\t\t\t\t\t>> Ironman used Suit Regeneration <<\n";
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }

            else{
                playerLife -= 10;
                cout << "\t\t\t\t\t\t\t\tYour Life -> " << playerLife << "\n\n";
            }
        }
    }
}

void captainSkills(){
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t[1] - T H R O W  S H I E L D\n\n";
    cout << "\t\t\t\t\t\t\t\t[2] - K I C K\n\n";
    cout << "\t\t\t\t\t\t\t\t[3] - S H I E L D\n\n\n";
}

void thorSkills(){
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t[1] - L I G H T N I N G  S T R I K E\n\n";
    cout << "\t\t\t\t\t\t\t\t[2] - S T O R M  B R E A K I N G  S L A S H\n\n";
    cout << "\t\t\t\t\t\t\t\t[3] - F L Y\n\n\n";
}

void ironmanSkills(){
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t[1] - B E A M\n\n";
    cout << "\t\t\t\t\t\t\t\t[2] - M E A S I L E S\n\n";
    cout << "\t\t\t\t\t\t\t\t[3] - S U I T  R E G E N E R A T I O N\n\n\n";
}

void lifeStatus(){
    cout << "\t\t\t\t\t\t\t\tYour HP -> " << playerLife << "\t" << "Thanos HP -> " << thanosLife << endl;
    cout << endl;
}

void matchResult(){
    if(playerLife > thanosLife){
        cout << "\t\t\t\t\t\t\t\tT H A N O S  H A S  B E E N  D E F E A T E D\n";
    }

    else{
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\tY O U  H A V E  B E E N  D E F E A T E D\n";
    }
}

