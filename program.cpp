#include <iostream>
#include <random>

const int N=1; // number of cells
const double pInm=.4; //probability of surpass infection
const int boundaries=200; //boundariesXboundaries (size of map)
const int inicialInfected=15;
const double r=0.00218;//probability of get infected by one infected
//DIR:
//1: North, 2: East, 3: South, 4: West.
//SIR:
//S: 1, I: 2, R: 3 
struct Cell{
  int dir = 0, X = 0, Y = 0, SIR=1;
  void rotateCell(void);
  void moveCell(void);
  void painKiller(void);
};

int randomIntGenerator(int, int);
bool generateProbability(double);
void moveAllCells(Cell cells[]);
void cureCells(Cell cells[]);
void start(Cell cells[]);
void infected(Cell cells[]);
void howManyInf(Cell cells[], int infectedSurrounding[]);
void infectSafe(Cell cells[]);

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

void Cell::rotateCell(){
  dir=randomIntGenerator(1,4);
  while((Y==boundaries && dir==1) || (Y==0 && dir==3) || (X==boundaries && dir==2) || (X==0 && dir==4))
    dir=randomIntGenerator(1,4);//We take all conditions at same time to avoid troubles with corners
  
    
}

void Cell::moveCell(){
  if(dir==1)
    Y++;
  else if(dir==2)
    X++;
  else if(dir==3)
    Y--;
  else
    X--;
}

void Cell::painKiller(){
  if(SIR==2)
    if(generateProbability(pInm))
      SIR=3;
}

bool generateProbability(double percentage){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);

  return dis(gen)<percentage;

}

void moveAllCells(Cell cells[]){
  for(int ii=0; ii<N; ii++){
    cells[ii].rotateCell();
    cells[ii].moveCell();
  }
}

void cureCells(Cell cells[]){
  for(int ii=0; ii<N; ii++)
    cells[ii].painKiller();
}

void start(Cell cells[]){
  int cellsPerNode=N/(boundaries*boundaries);
  int count=0;
  for(int ii=0; ii<boundaries; ii++){
    for(int jj=0; jj<boundaries; jj++){
      for(int kk=0; kk<cellsPerNode; kk++){
	cells[count].X=ii;
	cells[count].Y=jj;
	count++;
      }
    }
  }
}
void infected(Cell cells[]){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, N-1);
  for(int ii=0; ii<inicialInfected; ii++ ){
    int ram=dis(gen);
    if (cells[ram].SIR!=2)
      cells[ram].SIR=2;
    else
      ii--;
  }

}
void howManyInf(Cell cells[], int infectedSurrounding[]){
  for(int ii=0; ii<N; ii++){
    int is=0;
    if(cells[ii].SIR==1)
      for(int jj=0; jj<N; jj++){
	if((cells[ii].X==cells[jj].X && cells[ii].Y==cells[jj].Y && cells[jj].SIR==2) ||
	   (cells[ii].X+1==cells[jj].X && cells[ii].Y==cells[jj].Y && cells[jj].SIR==2) ||
	   (cells[ii].X==cells[jj].X && cells[ii].Y+1==cells[jj].Y && cells[jj].SIR==2) ||
	   (cells[ii].X-1==cells[jj].X && cells[ii].Y==cells[jj].Y && cells[jj].SIR==2) ||
	   (cells[ii].X==cells[jj].X && cells[ii].Y-1==cells[jj].Y && cells[jj].SIR==2))
	  is++;
      }
    infectedSurrounding[ii]=is;
  }
}
void infectSafe(Cell cells[]){
  int infectedSurrounding[N];
  howManyInf(cells, infectedSurrounding);
  for(int ii=0; ii<N; ii++)
    if(infectedSurrounding[ii]!=0)
      if(generateProbability(infectedSurrounding[ii]*r))
	cells[ii].SIR=2;
  
}
