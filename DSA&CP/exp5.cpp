void main(){
    asm{
        SETB P0_0_bit //define P0.0 input
        AGAIN
        MOV C, P0_0_bit;
        JNC ONI
        SETB P0_7_bit;
        SJMP NEXT
        ONI;
        CLR P0_7_bit
        NEXT
        SJMP AGAIN
    }
}