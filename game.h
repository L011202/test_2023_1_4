#define ROW 3 //��Ҫn�еľ��޸ĳ�n
#define COL 3 //��Ҫn�еľ��޸ĳ�n

void InitBorad(char borad[ROW][COL], int row, int col);

void DisplayBorad(char borad[ROW][COL], int row, int col);

void PlayerMove(char borad[ROW][COL], int row, int col);

void ComputerMove(char borad[ROW][COL],int row,int col);

char IsWin(char borad[ROW][COL], int row, int col);
