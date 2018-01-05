public class Cell
{
    private int PosColumn = 0;
    private int  PosRow = 0;
    private char CellValue;

    public Cell(int PosC, int PosR, char val)
    {
        PosColumn = PosC;
        PosRow= PosR;
        CellValue = val;
    }
    public int GetPosRow() { return PosRow; }
    public int GetPosColumn() { return PosColumn; }
    public void SetCellValue( char col) { CellValue = col; }
    public char GetCellValue() { return CellValue; }
};