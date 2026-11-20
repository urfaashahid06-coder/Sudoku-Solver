#include <iostream>
using namespace std;

// Check duplicate in a row
bool rowrepeat(int grid[9][9], int r)
{
    for(int i=0;i<9;i++)
    {
        if(grid[r][i]==0) continue;
        for(int j=i+1;j<9;j++)
        {
            if(grid[r][i]==grid[r][j]) return true;
        }
    }
    return false;
}

// Check duplicate in a column
bool colrepeat(int grid[9][9], int c)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][c]==0) continue;
        for(int j=i+1;j<9;j++)
        {
            if(grid[i][c]==grid[j][c]) return true;
        }
    }
    return false;
}

// Check duplicate in 3x3 subgrid
bool minigrid(int grid[9][9], int r, int c)
{
    bool isused[10] = {false};
    int start_of_row = r - (r % 3);
    int start_of_col = c - (c % 3);

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int n = grid[start_of_row+i][start_of_col+j];
            if(n != 0)
            {
                if(isused[n]) return true;
                isused[n] = true;
            }
        }
    }
    return false;
}

void printgrid(int grid[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout << grid[i][j]<<" ";
        cout << endl;
    }
}

bool isSafe(int grid[9][9], int row, int col, int num)
{
    for(int j=0;j<9;j++){
        if(grid[row][j] == num) 
        return false;
    }
    for(int i=0;i<9;i++){
        if(grid[i][col] == num) 
        return false;
    }
    int start_row = row - (row % 3);
    int start_col = col - (col % 3);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(grid[start_row+i][start_col+j] == num) return false;

    return true;
}

bool solvesod(int grid[9][9])
{
    int row, col;
    bool emptyfound = false;
    for(int i=0;i<9 && !emptyfound;i++)
        for(int j=0;j<9 && !emptyfound;j++)
            if(grid[i][j] == 0)
            {
                row = i;
                col = j;
                emptyfound = true;
            }

    if(!emptyfound) return true;

    for(int num=1;num<=9;num++)
    {
        if(isSafe(grid,row,col,num))
        {
            grid[row][col] = num;
            if(solvesod(grid)) return true;
        }
        grid[row][col] = 0;
    }

    return false;
}

int main() {
    int grid[9][9] = {0};
    bool validInput1 = true;
    bool failed = false;
    cout << "Sudoku Solver!!" << endl;

    for(int i=0;i<9;i++)
    {
        bool rowAccepted = false;
        while(!rowAccepted)
        {
            cout << "Enter 9 numbers for row " << i+1 << " (0 for missing digit):" << endl;
           
            for(int j=0;j<9;j++)
            {
                cin >> grid[i][j];
                
                if(grid[i][j] < 0 || grid[i][j] > 9)
                {
                    validInput1 = false;
                    cout << "Invalid input! Enter numbers between 0-9 only." << endl;
                    break;
                }
                if(cin.fail()){
                    failed = true;
                    cin.clear();
                    cin.ignore(30,'\n');
                    cout<<"Invalid input!! type a number only \n";
                    break;
                }
            
            }

            if(!validInput1){ 
                continue;
            }
           if(failed){
               continue;
           }
            
            if(rowrepeat(grid, i))
            {
                cout << "Duplicate numbers in this row! Re-enter the row." << endl;
                continue;
            }

            bool colConflict = false;
            for(int j=0;j<9;j++)
            {
                if(colrepeat(grid,j))
                {
                    colConflict = true;
                    break;
                }
            }
            if(colConflict)
            {
                cout << "Duplicate numbers in some column! Re-enter the row." << endl;
                continue;
            }

          bool subgridConflict = false;

int startRow = i - (i % 3);

for(int startCol = 0; startCol < 9; startCol += 3)
{
    if(minigrid(grid, startRow, startCol))
    {
        subgridConflict = true;
        break;
    }
}

if(subgridConflict)
{
    cout << "Conflict in 3x3 subgrid! Re-enter the row." << endl;
    continue;
}

            // Show the row for confirmation
            cout << "You entered row " << i+1 << ": ";
            for(int j=0;j<9;j++) cout << grid[i][j] << " ";
            cout << endl;
            
           while(true) {
            cout << "Do you want to accept this row or edit it? (A=accept / E=edit): ";
            char cmd;
            cin >> cmd;

            if(cmd=='A' || cmd=='a')
            {
                rowAccepted = true;
                break;
            }
            else if(cmd=='E' || cmd=='e')
            {
                cout << "Re-entering row " << i+1 << "..." << endl;
                break;
            }
            else
            {
                cout << "Invalid choice. Please type A to accept or E to edit.\n";
            }
          }
        }
    }

    cout << "SOLVING..." << endl;
    if(solvesod(grid))
    {
        cout << "Solved Sudoku:\n";
        printgrid(grid);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}