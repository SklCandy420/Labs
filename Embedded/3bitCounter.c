#include<p89v51rx2.h>

    void delay(unsigned int del) {
        unsigned int i, j;
        for (i = 0; i <= 10000; i++)
            for (j = 0; j <= del; j++);
    }
        void count3Bit()
        {
                INT0 = 0;
                RxD = 0;
                TxD = 0;
                delay(50);
                RxD = 1;
                delay(50);
                TxD = 1;
                RxD = 0;
                delay(50);
                RxD = 1;
                delay(50);
                INT0 = 1;
                TxD = 0;
                RxD = 0;
                delay(50);
                RxD = 1;
                delay(50);
                TxD = 1;
                RxD = 0;
                delay(50);
                RxD = 1;
                delay(50);
        }
    void main(void) {
			    T0=0;
					T1=0;
					WR=0;
					RD=0;
        while(1) {
          INT1=0;
          count3Bit();
          delay(50);
          INT1=1;
          count3Bit();
					
        }
    }