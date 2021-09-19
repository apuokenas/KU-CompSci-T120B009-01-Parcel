/**
 * 01-PostOffice.cpp
 *
 * 1 uždavinys: "Siuntinys" (banderolė, registruotas laiškas, kasininkės uždavinys).
 * Apskaičiuoti, kiek mažiausiai pašto ženklų po 10, 4 ir 1 ct reikia užklijuoti ant voko paprastos banderolės (laiško), kurios svoris yra pradinis duomuo.
 * Mokestis už banderolės siuntimą skaičiuojamas taip: už banderolę iki 50 g imama 10 ct, už kiekvienus papildomus pilnus ar nepilnus 50 g – dar po 5 ct.
 * Pavyzdys:
 * Pradinis duomuo: siuntos svoris = 185 g.
 * Tarpinis duomuo: mokestis = 25 ct.
 * Galutinis rezultatas: 2 pašto ženkliukai po 10 ct, 1 x 4 ct, 1 x 1 ct.
 * Programos struktūra. Programą turi sudaryti tokios dalys:
 * 1) visi reikalingi aprašai: direktyvos – bibliotekos prijungimas, pagrindinė funkcija (programa), kintamųjų aprašai;
 * 2) pradinio duomens įvedimas ("Banderoles svoris:" ar panašiai);
 * 3) mokesčio už banderolės siuntimą skaičiavimas;
 * 4) pašto ženklų skaičiaus nustatymas;
 * 5) rezultatų spausdinimas ("Zenklu skaicius:", "Is ju:",  "po 10 ct", "po 4 ct", "po 1 ct" ar pan.).
 *
 * @author Mantas Tumėnas
*/

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
  int weight = 0;
  string weightToString = "0";
  // Accept only natural numbers so that tax for items of <=0 grams won't cost 10 ct
  while (!regex_match(weightToString, regex("^[1-9][0-9]*$")))
  {
    cout << "Please enter parcel weight in grams (only natural numbers are accepted): ";
    cin >> weight;
    weightToString = to_string(weight);
  }

  const int tax = 10 + (weight - 1) / 50 * 5; // Since 50 is inclusive, "10 + weight / 50 * 5" would be invalid
  const int stamps_of_10ct = tax / 10;
  const int stamps_of_4ct = tax % 10 / 4; // (tax - stamps_of_10ct * 10) / 4;
  const int stamps_of_1ct = tax % 10 % 4; // (tax - stamps_of_10ct * 10 - stamps_of_4ct * 4) / 1;

  cout << "Stamp value (tax in cents): " << tax << "\nStamps in total: " << stamps_of_10ct + stamps_of_4ct +
    stamps_of_1ct << "\nIn that number:\n\t* stamps of 10ct: " << stamps_of_10ct << "\n\t* stamps of 4ct: " <<
    stamps_of_4ct << "\n\t* stamps of 1ct: " << stamps_of_1ct;
}
