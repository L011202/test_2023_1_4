#define ROW 3 //想要n行的就修改成n
#define COL 3 //想要n列的就修改成n

void InitBorad(char borad[ROW][COL], int row, int col);

void DisplayBorad(char borad[ROW][COL], int row, int col);

void PlayerMove(char borad[ROW][COL], int row, int col);

void ComputerMove(char borad[ROW][COL],int row,int col);

char IsWin(char borad[ROW][COL], int row, int col);
