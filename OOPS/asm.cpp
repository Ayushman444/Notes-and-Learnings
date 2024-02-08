void main(){
    asm{
        MOV A,#0X06;
        MOV B,#0X02;
        ADD A,B;
    }
    return;
}