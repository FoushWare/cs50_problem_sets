/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];                  //array of board 

// dimensions
int d;                                       //dimension  is global 
int i,j;
 int tile_i,tile_j;      // to get the location of the tile required to move 
// prototypes
void clear(void);
void greet(void);
void init(void);                             // fill the array 
void draw(void);                                  //draw the value of array
bool move(int tile);
bool won(void);
bool tile_search(int tile);   // to search for chosen tile 
bool check(void);   // to check if there is blank  adjacent to the selected tile  

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for ( i = 0; i < d; i++)
        {
            for (j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // fill the 2d array with values
    int num_dec=d*d-1;
    for( i=0;i<d;i++)
    {
        for( j=0;j<d;j++)
        {
         board[i][j]=num_dec;
         num_dec-=1;
        
        }
        
    }
    if(d%2==0)
{
    int temp=board[d-1][d-2];
    board[d-1][d-2]=board[d-1][d-3];
    board[d-1][d-3]=temp;
    
}
    
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // print the shape of numbers 
    for( i=0;i<d;i++)
    {
        for( j=0;j<d;j++)
        {
            if (board[i][j]==0)
            printf("[ ]");
            else
            printf("[%d]",board[i][j]);
            
        }
         printf("\n");
    }
   
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    //
 if(tile_search(tile)==true)  // if find the tile chosen go to move_check 
 {
     if( check()==true)
     return true;
     return false;
 }
 // if the tile wasn't found return false 
 return false;
  
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // check if the user finish the puzzle or not 
    int n=1;
     for (i=0;i<d;i++)
     {
         for(j=0;j<d;j++)
         {
             if(board[i][j]==n)
             {
                n++;
                            if(n==d*d&&board[d-1][d-1]==0)
                              return true;
                             
             }
             
         }
      }  
      
      return false;
}

// tile search for valiadation 
 bool tile_search(tile)
 {
     for (i=0;i<d;i++)
     {
         for(j=0;j<d;j++)
         {
             if(tile==board[i][j])
             {
                 tile_i=i;
                 tile_j=j;
                 return true;
             }
            
         }
    }
     return false;
      
 }
  bool check(void )
  {
      if(tile_i>0&&board[tile_i-1][tile_j]==0)  ////////  // //check up 
     {
         int temp_tile=board[tile_i][tile_j];
         
      board[tile_i][tile_j]=board[tile_i-1][tile_j];
      board[tile_i-1][tile_j]=temp_tile;
      return true;
         
     }
      if(tile_i>=0&&board[tile_i+1][tile_j]==0&&tile_i<d-1)////////check down 
      { 
      int temp_tile=board[tile_i][tile_j];
      board[tile_i][tile_j]=board[tile_i+1][tile_j];
      board[tile_i+1][tile_j]=temp_tile;
      return true;}
      if(tile_j<d-1&&board[tile_i][tile_j+1]==0)//////////////////check right
      { 
      int temp_tile=board[tile_i][tile_j];
      board[tile_i][tile_j]=board[tile_i][tile_j+1];
      board[tile_i][tile_j+1]=temp_tile;
      return true;}
      if(tile_j>0&&board[tile_i][tile_j-1]==0)//////////////////check left
    {   
        
      int temp_tile=board[tile_i][tile_j];
      board[tile_i][tile_j]=board[tile_i][tile_j-1];
      board[tile_i][tile_j-1]=temp_tile;
      return true;}
       return false;
  }
  
  
  
  