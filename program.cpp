#include <iostream>
#include <random>

const int N=1; // number of cells

int randomIntGenerator(int, int);

struct Cell{
  int dir = 0, X = 0, Y = 0, SIR=0;
  void rotateCell(void);
   
};

// functions
  
void Cell::rotateCell(){
  dir=randomIntGenerator(1,4);  
}

int main(void){
  Cell cells[N];
  std::default_random_engine generator;
  cells[0].rotateCell();
  std::cout<< cells[0].dir<<std::endl;
}

int randomIntGenerator(int low, int high){
  // Taken from http://stackoverflow.com/questions/23838194/c-fast-random-number-generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(low, high);

  return dis(gen);
}
