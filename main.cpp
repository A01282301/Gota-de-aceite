#include <iostream>

#include <queue> 

using namespace std;
#define Rows 5 //Defines the number of 
#define Columns 5
int area =1;
char COLORED = 'C';

//Representa la busqueda NOSE
int row[] = {-1, 0, 1, 0}; //y
int col[] = { 0,-1, 0, 1}; //x

//   -1
// -1 0 1 
//    1

char replaceFor = 'B';
bool inBounds(char colorMatrix[Rows][Columns], int y, int x);
void displayMatrix(char Matrix[Rows][Columns]);
void gotaDeAceite(char colorMatrix[Rows][Columns], int y, int x, char COLORED);



void displayMatrix(char Matrix[Rows][Columns]){
for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
			cout << ' ' << Matrix[i][j];
		    cout << '\n';
	}
}

bool inBounds(char colorMatrix[Rows][Columns], int y, int x)
{
    if(x >=0 && x < Columns && y >= 0  && y <Rows && colorMatrix[y][x] == replaceFor){
        return true;
        
    }else{
        return false;
    }
}
 


void gotaDeAceite(char colorMatrix[Rows][Columns], int y, int x, char COLORED)
{
	queue< pair<int, int> > grupo; //Grupo con par de coordenadas x, y

	grupo.push({y, x}); //Agregar al grupi
 
	while (!grupo.empty()) //Mientras haya sin agrupar
	{
		pair<int, int> node = grupo.front();
		grupo.pop();
 
		int y = node.first, x = node.second;
 
		for (int i = 0; i < 4; i++)
		{
			if (inBounds(colorMatrix, y + row[i], x + col[i]))
			{
			    colorMatrix[y+row[i]][x+col[i]] = COLORED;
			    grupo.push({y + row[i], x+ col[i]});
                area = area +1;
			}
		}
	}
}

int main()
{
    int SEEDX = rand();
    int SEEDY = rand();

    cout <<"Matrix de entrada\n";

	char colorMatrix[Rows][Columns] =
	{  
		{ 'W', 'W', 'W', 'W', 'B'},
		{ 'W', 'B', 'B', 'B', 'B'},
		{ 'W', 'B', 'B', 'B', 'W'},
		{ 'W', 'B', 'B', 'W', 'W'},
		{ 'W', 'W', 'B', 'B', 'B'},
	};
    
    
    displayMatrix(colorMatrix);

    while(!inBounds(colorMatrix, SEEDX, SEEDY)){
        SEEDX = rand();
        SEEDY = rand();
    }
    
	colorMatrix[SEEDX][SEEDY] = COLORED;
	gotaDeAceite(colorMatrix, SEEDX, SEEDY, COLORED);

    cout <<"Matrix de salida\n";
    displayMatrix(colorMatrix);
    cout <<"Area: " << area;
}