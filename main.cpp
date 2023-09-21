#include <exception>
#include <iostream>

using namespace std;

enum Alphabets {
  Latin = 0,
  Cyrillic,
};

Alphabets get_alphabet();
int get_key();

void clear() { system("clear"); }

int main() {
  Alphabets alphabet = get_alphabet();
  int key = get_key();

  return 0;
}

string prompt() {
  string tmp;
  bool end = false;

  do {
    if ((cin >> tmp) && (cin.peek() == '\n') || cin.eof())
      end = true;
  } while (!end);

  return tmp;
}

int get_key() {
  bool loop = true;
  int key;
  string error;
  while (loop) {
    clear();
    if (error.length() > 0)
      cout << error << endl << endl;
    cout << "Укажите ключ (сдвиг): ";
    int choose = atoi(prompt().c_str());
    if (choose < 1) {
      error = "Неверно указан ключ (<1)";
      continue;
    } else
      break;
  }

  return key;
}

Alphabets get_alphabet() {
  bool loop = true;
  string error;
  Alphabets alphabet;
  while (loop) {
    clear();
    if (error.length() > 0)
      cout << error << endl << endl;
    cout << "Выберите алфавит:" << endl;
    cout << "1. Латиница" << endl;
    cout << "2. Кириллица" << endl << endl;
    cout << "Ваш выбор: ";
    switch (atoi(prompt().c_str())) {
    case (1):
      alphabet = Latin;
      loop = false;
      break;
    case (2):
      alphabet = Cyrillic;
      loop = false;
      break;
    default:
      error = "Неверный выбор!";
      break;
    }
  }

  return Latin;
}
