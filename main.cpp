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

struct item {
    string name;
    int amount;
};

string Menu() {//Funktion för att skriva ut menyn på skärmen.
    return "[1] Skriv ut lagerlista\n[2] Sök artikel\n[3] Redigera artikel\n[4] Avsluta programmet\n";
}

int main() {
    //Definiera mjölk och yoghurt som objekt av struct.
    item milk;
    milk.name = "Enlitersmjölk";
    milk.amount = 3;
    
    item yogurt;
    yogurt.name = "Yoghurt";
    yogurt.amount = 5;
    while (true) { //While-loop för att skapa en meny som man kan återgå till.
        int option = 0; //Definiera variabeln för att kunna göra val i menyn.
        
        cout << Menu();
        cin >> option;
        
        switch (option) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                goto ExitMenu;
                break;
                
            default:
                break;
        }
    }
    ExitMenu:
    return 0;
}
