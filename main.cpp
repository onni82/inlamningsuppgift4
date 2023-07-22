//
//  Kurs: Programmering 1 PRRPRR01 100p
//  Uppgift Inlämningsuppgift 4
//  Elev: Onni Bucht
//
//Skapa ett enkelt registerprogram med hjälp av ett fält (array) med element av typen struct.
//T.ex. ett lagerhållningsprogram, en adressbok, en förteckning över en skivsamling. Alla ingående variabler i structen bör inte vara av samma typ. Programmet ska ha ett textbaserat gränssnitt där man via en meny ska kunna välja bland några olika alternativ. Minimum är att man ska kunna skriva ut en lista över alla element samt söka efter ett element. Programmet ska upprepas tills dess användaren väljer att avsluta det. Man ska alltså alltid komma tillbaka till menyn efter att ett alternativ har utförts. En meny för ett lagerhållningsprogram skulle kunna se ut så här:
//1. Skriv ut lagerlista
//2. Sök artikel
//3. Redigera artikel
//4. Avsluta programmet
//Koden ska innehålla minst en funktion (utöver main), vara kommenterad och korrekt indenterad. Läs mer om bedömning nedan.
//Skicka in källkodsfilen som du döpt till <ditt_namn>.cpp

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

struct Item {//Ett itemobjekt är ett objekt som syns i listan. Det kan t.ex. vara en inköpslista. namevariabeln är namnet på varan medan amountvariabeln är antalet an angivna vara.
    string name;
    int amount;
};

void AddItem(vector<Item> &itemList, string name, int amount) {//Funktion för att kunna lägga till varor i listan. Argument som skrivs in i funktionens anrop är namn och antal för just den vara man vill lägga in.
    Item item;
    item.name = name;
    item.amount = amount;
    itemList.push_back(item);
}

int Search(vector<Item> &itemList, string searchTerm) {//Sökfunktion för att kolla upp om en viss vara finns i listan. Funktionens argument är vektorn samt ordet man letar efter.
    //auto size = itemList.size();
    for (int i = 0; i < itemList.size(); i++) {
        if (itemList[i].name == searchTerm) {
            return i;//Kan hitta varan.
        }
    }
    
    return -1;//Kan ej hitta varan.
}

string Menu() {//Funktion för att skriva ut menyn på skärmen.
    return "[1] Skriv ut inköpslista\n[2] Sök vara\n[3] Redigera vara\n[4] Lägg till vara\n[5] Avsluta programmet\n";
}

string trim(string line) {//Funktion för att trimma strängvariabler.
    string newString;
    
    for (char ch : line) {
        if (ch == '\n' || ch == '\r')
            continue;
        newString += ch;
    }
    
    return newString;
}

bool isShutdown(int x) {//Booleanfunktion för att kolla om användaren vill avsluta programmet, vilket skrivs in med siffran 4.
    if (x == 5) {
        return true;
    } else{
        return false;
    }
}

int main() {
    vector<Item> groceryList;
    AddItem(groceryList, "enlitersmjölk", 3);
    AddItem(groceryList, "enlitersyoghurt", 5);
    AddItem(groceryList, "kilo potatis", 10);
    
    int option = 0;//Definiera variabeln för att kunna göra val i menyn.
    string searchTerm;//Definiera variabeln för att kunna söka i listan.
    //auto size = groceryList.size();//Konverterar vektorns storleks variabeltyp så att den kan användas som en intvariabel.
    
    while (true) {//While-loop för att skapa en meny som man kan återgå till.
        cout << Menu();
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (isShutdown(option)) {
            break;
        }
        
        switch (option) {//Läser in användarens val från huvudmenyn.
            case 1:
            {
                for (int i = 0; i < groceryList.size(); i++) {//Skriver ut inköpslista.
                    cout << i+1 << ". " << groceryList[i].amount << " " << groceryList[i].name << endl;
                }
                
                break;
            }
            case 2:
            {
                cout << "Vad vill du kolla efter i listan?\n";
                getline(cin, searchTerm);
                searchTerm = trim(searchTerm);
                
                int index = Search(groceryList, searchTerm);//Letar upp indexnummer för varan man söker efter.
                
                if (index == -1) {
                    cout << "Varan är ej uppskriven!\n";
                } else {
                    cout << "Varan är uppskriven och finns på rad " << index+1 << endl;
                }
                
                break;
            }
            case 3:
            {
                int editIndex;//Anger index för vilken vara man vill ändra.
                char editProperty;//Anger vilken attribut man vill ändra hos angiven vara.
                
                for (int i = 0; i < groceryList.size(); i++) {
                    cout << "[" << i << "] " << groceryList[i].amount << " " << groceryList[i].name << endl;
                }
                
                cout << "Vilken vara vill du ändra?\n";
                cin >> editIndex;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vill du ändra [a]ntal eller [n]amn?\n";
                cin >> editProperty;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                editProperty = tolower(editProperty);
                
                switch (editProperty) {
                    case 'a':
                    {
                        int editAmount;
                        cout << "Skriv ett nytt antal: ";
                        cin >> editAmount;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                        if (editAmount <= 0) {
                            if (groceryList.size() > 1) {
                                cout << "Tar bort " << groceryList[editIndex].name << " från listan.\n";
                                
                                if (editIndex == 0) {
                                    groceryList.erase(groceryList.begin());
                                } else {
                                    groceryList.erase(groceryList.begin() + editIndex);
                                }
                            } else {
                                cout << "Kan ej ta bort sista varan på listan. Testa att ändra namn på varan istället.\n";
                            }
                        } else {
                            cout << "Uppdaterat " << groceryList[editIndex].name << ". Antal: " << editAmount << ".\n";
                            groceryList[editIndex].amount = editAmount;
                        }
                        
                        break;
                    }
                    case 'n':
                    {
                        string editName;
                        cout << "Skriv ett nytt namn: ";
                        getline(cin, editName);
                        editName = trim(editName);
                        cout << "Uppdaterat " << groceryList[editIndex].name << ". Nytt namn: " << editName << ".\n";
                        groceryList[editIndex].name = editName;
                        break;
                    }
                    default:
                        cout << "Inte ett giltig val. Återgår till menyn.\n";
                        break;
                }
                break;
            }
            case 4:
            {
                string newItemName;
                int newItemAmount;
                cout << "Vilken vara vill du lägga till? ";
                getline(cin, newItemName);
                newItemName = trim(newItemName);
                cout << "Hur stort antal vill du lägga till? ";
                cin >> newItemAmount;
                AddItem(groceryList, newItemName, newItemAmount);
                cout << newItemAmount << " " << newItemName << " uppskriven på inköpslistan.\n";
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
