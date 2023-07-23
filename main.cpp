//
//  Kurs: Programmering 1 PRRPRR01 100p
//  Uppgift: Inlämningsuppgift 4
//  Elev: Onni Bucht
//

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

string trim(string input) {//Funktion för att trimma strängvariabler för att inte innehålla nya rader.
    string output;
    
    for (char ch : input) {
        if (ch == '\n' || ch == '\r')
            continue;
        output += ch;
    }
    
    return output;
}

bool isShutdown(int x) {//Booleanfunktion för att kolla om användaren vill avsluta programmet, vilket skrivs in med siffran 4.
    if (x == 5) {
        return true;
    } else {
        return false;
    }
}

int main() {
    vector<Item> groceryList;
    //AddItem(groceryList, "enlitersmjölk", 3);
    //AddItem(groceryList, "enlitersyoghurt", 5);
    //AddItem(groceryList, "kilo potatis", 10);
    
    int option = 0;//Definiera variabeln för att kunna göra val i menyn.
    string searchTerm;//Definiera variabeln för att kunna söka i listan.
    
    while (true) {//While-loop för att skapa en meny som man kan återgå till.
        cout << Menu();
        if (cin >> option) {//Kollar att användaren har skrivit in ett heltal.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (isShutdown(option)) {
                break;
            }
            
            switch (option) {//Läser in användarens val från huvudmenyn.
                case 1://Val för att skriva ut inköpslistan
                {
                    for (int i = 0; i < groceryList.size(); i++) {//Skriver ut inköpslista.
                        cout << i+1 << ". " << groceryList[i].amount << " " << groceryList[i].name << endl;
                    }
                    
                    break;
                }
                case 2://Val för att söka i inköpslistan
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
                case 3://Val för att redigera inköpslistan
                {
                    int editIndex;//Anger index för vilken vara man vill ändra.
                    char editProperty;//Anger vilken attribut man vill ändra hos angiven vara.
                    
                    for (int i = 0; i < groceryList.size(); i++) {
                        cout << "[" << i << "] " << groceryList[i].amount << " " << groceryList[i].name << endl;
                    }
                    
                    cout << "Vilken vara vill du ändra?\n";
                    cin >> editIndex;
                    
                    if (editIndex >= groceryList.size()) {
                        cout << "Varan finns inte. Återgår till menyn.\n";
                        break;
                    }
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Vill du ändra [a]ntal eller [n]amn?\n";
                    cin >> editProperty;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    editProperty = tolower(editProperty);
                    
                    switch (editProperty) {//Kollar om användaren vill ändra antal eller namn på vara. 'a' för antal och 'n' för namn.
                        case 'a'://Valet för att uppdatera antal av en vara.
                        {
                            int editAmount;
                            cout << "Skriv ett nytt antal: ";
                            
                            if (cin >> editAmount) {
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                
                                if (editAmount <= 0) {//Kollar om det nya antalet är 0, för att användaren ska kunna ta bort varor i listan.
                                    if (groceryList.size() > 1) {//Tar endast bort varor om det finns mer än en vara i listan.
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
                            } else {
                                cin.clear();//Återställer inmatningen av antal varor vid uppdatering av vara för att undvika en oändlig loop.
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');//Rensar inmatningen av antal varor vid uppdatering av vara.
                                cout << "Fel val.\n";
                                break;
                            }
                            break;
                        }
                        case 'n'://Valet för att uppdatera namnet på en vara.
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
                case 4://Val för att lägga till vara
                {
                    string newItemName;
                    int newItemAmount;
                    cout << "Vilken vara vill du lägga till? ";
                    getline(cin, newItemName);
                    newItemName = trim(newItemName);
                    cout << "Hur stort antal vill du lägga till? ";
                    if (cin >> newItemAmount) {
                        AddItem(groceryList, newItemName, newItemAmount);
                        cout << newItemAmount << " " << newItemName << " uppskriven på inköpslistan.\n";
                        break;
                    } else {
                        cin.clear();//Återställer inmatningen av antal nya varor för att undvika en oändlig loop.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');//Rensar inmatningen av antalet nya varor.
                        cout << "Fel val.\n";
                        break;
                    }
                    
                    break;
                }
                default://Val nummer 5 för att avsluta programmet finns inte som ett case. Booleanfunktionen isShutdown används istället för att kolla om man vill stänga av. Funktionen kallas innan switchen.
                    break;
            }
        } else {
            cin.clear();//Återställer inmatningen av val i huvudmenyn för att undvika en oändlig loop.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//Rensar inmatningen av val i huvudmenyn.
            cout << "Fel val.\n";
        }
    }
    return 0;
}
