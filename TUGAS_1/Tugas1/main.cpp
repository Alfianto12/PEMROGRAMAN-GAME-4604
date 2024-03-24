#include <iostream>

using namespace std;

class character{
public:

    int herbs = 5;
    int manapot = 5;
    int hppot = 5;
    int swords[4] = {
    swords[0] = 100, // Wooden Sword
    swords[1] = 200, // Iron sword
    swords[2] = 300, // Diamond Sword
    swords[3] = 500, // Netherite Sword
    };
    int equipedsword = 0;
    int hp = 900;
    int mana = 1000;
    int dmg = swords[equipedsword];
//===================================================

//===================================================
    void useherb(){
        if(herbs<1){
            cout << "you dont have herbs" << endl;
        }else if(hp>=1000){
            cout << "you dont need to use herbs" << endl;
        }else{
        herbs=herbs-1;
        hp=hp+10;
        cout << "you used herbs +10hp" << endl;
        }
    }
//===================================================
    void usehppot(){
        if(hppot<=1){
            cout << "you dont have hp pot" << endl;
        }else if(hp>=1000){
            cout << "you dont need to use hp pot" << endl;
        }else{
        hppot=hppot-1;
        hp=hp+50;
        cout << "you used hp pot +50hp" << endl;
        }
    }
//===================================================
    void usemanapot(){
        if(manapot<=1){
            cout << "you dont have mana pot" << endl;
        }else if(mana>=1000){
            cout << "you dont need to use mana pot" << endl;
        }else{
        manapot=manapot-1;
        mana=mana+50;
        cout << "you used mana pot +10mana" << endl;
        }
    }
//===================================================
    void changeSword(int a) {
        if (a >= 0 && a < 4) {
            dmg = swords[a];
            equipedsword = a;
            cout << "You equipped ";
            if(a == 1) cout << "Wooden Sword";
            else if(a == 2) cout << "iron sword";
            else if(a == 3) cout << "Diamond Sword";
            else if(a == 4) cout << "Netherite Sword";
            cout << " New damage: " << dmg << endl;
        } else {
            cout << "Invalid sword number." << endl;
        }
    }
//===================================================
    void showstat(){
        cout << "hp = " << hp << endl;
        cout << "mana = " << mana << endl;
        cout << "dmg = " << dmg << endl;
         cout << "Equipped Sword: ";
        if(equipedsword == 0) cout << "Wooden sword." << endl;
        else if(equipedsword == 1) cout << "iron sword." << endl;
        else if(equipedsword == 2) cout << "Diamond sword." << endl;
        else if(equipedsword == 3) cout << "Netherite sword." << endl;
        cout << endl;
    }
    void showbag(){
        cout << "======== inventory ========" << endl;
        cout << "herbs = " << herbs << endl;
        cout << "mana pot = " << manapot << endl;
        cout << "hp pot = " << hppot << endl;
        cout << "Sword Inventory:" << endl;
        for (int i = 0; i < 4; ++i) {
            cout << "Sword " << i+1 << ": ";
            if (i == equipedsword)
                cout << "Used";
            else
                cout << "Not Used";
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    character alfi;
    int choice;
    cout << "===Welcome to the game! ===" << endl;
    cout << "======= Alfi Status =======" << endl;
    alfi.showstat();
    alfi.showbag();
    do {
        cout << "===========================" << endl;
        cout << "Menu:" << endl;
        cout << "1. Status" << endl;
        cout << "2. Inventory" << endl;
        cout << "3. Use Herb" << endl;
        cout << "4. Use HP Pot" << endl;
        cout << "5. Use Mana Pot" << endl;
        cout << "6. Change Sword" << endl;
        cout << "0. Exit" << endl;
        cout << "===========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 0:
                cout << "Exiting..." << endl;
                break;
            case 1:
                cout << "==== Alfi Status ====" << endl;
                alfi.showstat();
                break;
            case 2:
                alfi.showbag();
                break;
            case 3:
                alfi.useherb();
                break;
            case 4:
                alfi.usehppot();
                break;
            case 5:
                alfi.usemanapot();
                break;
            case 6:
                cout << "List Sword :" << endl;
                cout << "1. Wooden Sword " << endl;
                cout << "2. Iron Sword " << endl;
                cout << "3. Diamond Sword " << endl;
                cout << "4. Netherite Sword " << endl;
                cout << "Enter the number of the sword you want to equip (1 - 4): ";
                int choice;
                cin >> choice;
                alfi.changeSword(choice - 1);
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 6." << endl;
                break;
        }

    } while(choice != 0);

    return 0;
}
