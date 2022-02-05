// Programación 2 - Práctica 1
// DNI: 46087545F
// Nombre: Sergio Pérez Villanueva
#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()
#include <cstring>

using namespace std;

const int KNAME=32;
const int KENEMIES=5;
const int KPOINTS=200; // Tenemos 200 puntos para distribuir
const int KDICE=20; // Número de caras del dado

struct Core{
  int attack;
  int defense;
  int hp;
};

enum Breed{
  AXOLOTL,
  TROLL,
  ORC,
  HELLHOUND,
  DRAGON
};

struct Enemy{
  Breed name;
  Core features;
};

struct Hero{
  char name[KNAME];
  Core features;
  bool special; // ataque especial que puede utilizarse unicamente una vez por partida
  int runaways;
  int exp;
  int kills[KENEMIES];
};

int rollDice(){
  return rand()%KDICE+1;
}

// Función que utilizamos para crear a nuestro heroe y introducirse sus estadísticas
Hero createHero(Hero &hero){
  int valid;
  int ataq_pt = 0, defend_pt = 0, suma_pt = 0;

  do{
    valid = -1; // Si valid cambia de valor, el nombre tiene signo de puntuación
    cout << "Enter hero name: ";
    cin.getline(hero.name,KNAME-1);

    int tamany = strlen(hero.name);
    for (int i = 0; i < tamany; i++){
      if (ispunct(hero.name[i]) != 0){
        valid = 1;
      }
    }
    if (isdigit(hero.name[0]) != 0){
      valid = 1;
    }
    if (valid == 1){
      cout << "ERROR: wrong name" << endl; 
    } 
  }while (valid == 1);
  
  do{
    cout << "Enter attack/defense:";
    cin >> ataq_pt;
    cin.get();
    cin >> defend_pt;
    cin.get();

    suma_pt = defend_pt + ataq_pt;
    
    if (ataq_pt <= 0 || defend_pt <= 0 || suma_pt != 100 ||
        ataq_pt >= 100 || defend_pt >= 100){
      cout << "ERROR: wrong distribution" << endl;
    }
  }while (ataq_pt <= 0 || defend_pt <= 0 || suma_pt != 100 ||
          ataq_pt >= 100 || defend_pt >= 100);
  
  hero.features.attack = (KPOINTS * (ataq_pt * 0.01)); 
  hero.features.defense = (KPOINTS * (defend_pt * 0.01)); 
  hero.features.hp = hero.features.defense * 2;

  hero.special = true;
  hero.exp = 0;
  hero.kills[0] = 0;

  return hero;
}

void statsEnemies(Enemy enemy, Breed name){
  if (name == AXOLOTL){
    enemy.features.attack = 40;
    enemy.features.defense = 40;
    enemy.features.hp = 80;
  }
  else if (name == TROLL){
    enemy.features.attack = 60;
    enemy.features.defense = 80;
    enemy.features.hp = 160;
  }
  else if (name == ORC){
    enemy.features.attack = 80;
    enemy.features.defense = 120;
    enemy.features.hp = 240;
  }
  else if (name == HELLHOUND){
    enemy.features.attack = 120;
    enemy.features.defense = 100;
    enemy.features.hp = 200;
  }
  else if (name == DRAGON){
    enemy.features.attack = 160;
    enemy.features.defense = 140;
    enemy.features.hp = 280;
  }
}

// Función en la cual asignamos las estadisticas de cada enemigo
Enemy createEnemy(Enemy enemy){
  Breed name; 
  int cara_dado;
  cara_dado = rollDice();

  if (cara_dado <= 6){
    name = AXOLOTL;
    statsEnemies(enemy,name);
    cout << "[Enemy]" << endl;
    cout << "Breed: " << "Axolotl" << endl;
    cout << enemy.features.attack << endl;
    cout << enemy.features.defense << endl;
    cout << enemy.features.hp << endl;
  }
  else if (cara_dado > 6 && cara_dado <=11){
    name = TROLL;
    statsEnemies(enemy,name);
    cout << "[Enemy]" << endl;
    cout << "Breed: " << "Troll" << endl;
    cout << enemy.features.attack << endl;
    cout << enemy.features.defense << endl;
    cout << enemy.features.hp << endl;
  }
  else if (cara_dado > 11 && cara_dado <=15){
    name = ORC;
    statsEnemies(enemy,name);
    cout << "[Enemy]" << endl;
    cout << "Breed: " << "Orc" << endl;
    cout << enemy.features.attack << endl;
    cout << enemy.features.defense << endl;
    cout << enemy.features.hp << endl;
  }
  else if (cara_dado > 15 && cara_dado <=18){
    name = HELLHOUND;
    statsEnemies(enemy,name);
    cout << "[Enemy]" << endl;
    cout << "Breed: " << "Hellhound" << endl;
    cout << enemy.features.attack << endl;
    cout << enemy.features.defense << endl;
    cout << enemy.features.hp << endl;
  }
  else if (cara_dado > 18 && cara_dado <=20){
    name = DRAGON;
    statsEnemies(enemy,name);
    cout << "[Enemy]" << endl;
    cout << "Breed: " << "Dragon" << endl;
    cout << enemy.features.attack << endl;
    cout << enemy.features.defense << endl;
    cout << enemy.features.hp << endl;
  }
  return enemy;
}

void fight(Hero &hero,Enemy &enemy){
}

void report(const Hero &hero){
}

void showMenu(){
  cout << "[Options]" << endl
       << "1- Fight" << endl
       << "2- Run away" << endl
       << "3- Special" << endl 
       << "4- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
}

int main(int argc,char *argv[]){
  Hero hero;
  Enemy enemy;

  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
    cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar números aleatorios
    
    createHero(hero);
    createEnemy(enemy);
    showMenu();

    

    // Cout para comparar contadores con la función
    cout << "Función main: " << endl;
    cout << hero.features.attack <<endl;
    cout << hero.features.defense <<endl;
    cout << hero.features.hp <<endl;
    
  }
}

 