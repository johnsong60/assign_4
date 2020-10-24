// Author: johnathan song
// GitHub:
// October 20, 2020
// csis 123a

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Currency {
 public:

  Currency(double exchangeRate, int amount) {
    this->exchangeRate = exchangeRate;
    this->amount = amount;
  };
  virtual void show() = 0;
 protected:
  int amount;
  double exchangeRate;
};

class Peso : public Currency {
 public:

  Peso(int amount) : Currency(21.1508, amount) {

  }

  void show() {
    cout << "MXN" << "\t" << exchangeRate * amount << "\n";
  }
};

class Euro : public Currency {
 public:

  Euro(int amount) : Currency(0.845989, amount) {

  }

  void show() {
    cout << "EUR" << "\t" << exchangeRate * amount << "\n";
  }
};

class JPY : public Currency {
 public:

  JPY(int amount) : Currency(105.639, amount) {

  }

  void show() {
    cout << "JPY" << "\t" << exchangeRate * amount << "\n";
  }
};

class KRW : public Currency {
 public:

  KRW(int amount) : Currency(1143.58, amount) {

  }

  void show() {
    cout << "KRW" << "\t" << exchangeRate * amount << "\n";
  }
};

/*
 *
 */
int main(int argc, char** argv) {

  char selection;
  int amount;
  vector<Currency *> v;
  do {
    cout << "Convert from USD to\n";
    cout << "A. Euro\n"
         << "B. Mexican Peso\n"
         << "C. Japanese Yen\n"
         << "D. Korean Won\n"
         << "E. Display All\n"
         << "Q. Quit\n";
    cin >> selection;

    if (selection == 'A' || selection == 'B'
        || selection == 'C' || selection == 'D') {
      cout << "Enter amount of money in USD: ";
      cin >> amount;
      switch (selection) {
        case 'A':
          v.push_back(new Euro(amount));
          break;
        case 'B':
          v.push_back(new Peso(amount));
          break;
        case 'C':
          v.push_back(new JPY(amount));
          break;
        case 'D':
          v.push_back(new KRW(amount));
          break;
      }
    } else if (selection == 'E') {
      cout << "\n";
      for (const auto &element : v) {
        element->show();
      }
    }

    cout << "\n";
  } while (selection != 'Q');


  return 0;
}
