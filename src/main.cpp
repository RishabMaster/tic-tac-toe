/*
    A tac-tac-toe command-line game written in C++,
    made with 💚 by Rishab kr. Gautam
*/

#include <iostream>
using namespace std;

string art = R"(                                                                                         
                                                            
          ,--,--'      ,--,--'        ,--,--'               
          `- | . ,-.   `- | ,-. ,-.   `- | ,-. ,-.          
           , | | |   -- , | ,-| |   -- , | | | |-'          
           `-' ' `-'    `-' `-^ `-'    `-' `-' `-'          
                                                                                                            
)";

char board[3][3] = { 
    { '_', '_', '_' },
    { '_', '_', '_' },
    { '_', '_', '_' } 
};

char coin = 'O';
int value = 1, count = 0;
int arr[8]; // zero initialised 3 for row, 3 for col, 2 for dia

void displayState () { 
// Draws the game's current state
  puts (" ");
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
        {
          cout << " " << board[i][j];
        }
      cout << '\n';
    }
  cout << endl;
}

void turn () {
  // to toss between -1 and 1

  if (coin == 'O')
    {
      coin = 'X'; value = -1;
    }
  else
    {
      coin = 'O'; value = 1;
    }
}

int check(){
    if(count > 4){
        for(int w = 0; w < 8; w++){
            if(abs(arr[w]) == 3){
                if (arr[w] > 0) {
                    cout << "----Player O wins!----\n" << endl;
                    return 0; 
                } else {
                    cout << "----Player X wins!----\n" << endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main () {
    int l, m;
    
    cout << art;
    
    puts ("Lets start the game. Positions have range from 1,1 to 3,3");
    
    displayState ();

    while (count < 9 && check()) {

      char input[10]; // Buffer to store input string

      cout << "Enter the position x,y : ";

      // Read the entire input as a string first
      if (scanf ("%9s", input) != 1)
        {
          puts ("----Invalid Input!----");
          while (getchar () != '\n')
            ; // Clear input buffer
          continue;
        }

      // parse x and y coordinates
      if (sscanf (input, "%d,%d", &l, &m) != 2)
        {
          puts ("----Invalid Input Format!----");
          continue;
        }

      if (!(l > 0 && l < 4) || !(m > 0 && m < 4))
        {
          puts ("----Invalid Move!----");
          continue;
        }

      if (board[l-1][m-1] != '_')
        {
          puts ("----Invalid Move!----");
          continue;
        }
        
      board[l - 1][m - 1] = coin;
      
      //Operations to keep track of moves and announce winner
      arr[l-1] += value;
      arr[m+2] += value;
      if(l==m){arr[6] += value;}
      if(l+m == 4) { arr[7] += value;}
      
      displayState ();
      
      //check();
      count++;
      turn (); // change the turn
    }
    
    if(count == 9){
        cout << "----It's a draw----\n" << endl;
    }
    
    return 0;
}

