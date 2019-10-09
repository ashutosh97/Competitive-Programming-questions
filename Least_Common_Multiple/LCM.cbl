       IDENTIFICATION DIVISION.

       PROGRAM-ID.LCM.

       ENVIRONMENT DIVISION.

       DATA DIVISION.

       WORKING-STORAGE SECTION.

       01 ARRAY.
       02 A PIC 9(5) OCCURS 10 TIMES.
       77 N PIC 9(2) VALUE 2.
       77 I PIC 9(2).
       77 J PIC 9(2).
       77 Q PIC 9(3).
       77 R PIC 9(3).
       77 K PIC 9(5).
       77 B PIC 9(3) VALUE 0.
       77 C PIC 9(3) VALUE 0.
       77 D PIC 9(3) VALUE 0.
       77 P PIC Z(5)9.
       01 num PIC 999 VALUE 0.
       01 num2 PIC 999 VALUE 0.
       01 chickens PIC 999 VALUE 0.
       01 dogs PIC 999 VALUE 0.
       01 total PIC 999 VALUE 0.
       01 result PIC 99 VALUE 0.
       01 result1 PIC 999 VALUE 0.
       01 result2 PIC 999 VALUE 0.
       01 count1 PIC 999 VALUE 0.

       PROCEDURE DIVISION.

       MAIN-PARA.
           DISPLAY "ENTER " N " NUMBERS".
           PERFORM X-PARA VARYING I FROM 1 BY 1 UNTIL I > N.
           PERFORM Y-PARA VARYING I FROM B BY 1 UNTIL C = N.
           MOVE K TO P.
           DISPLAY "THE LCM IS " P.

           DISPLAY "Enter Number of Head".
           ACCEPT num.
           DISPLAY "Enter number of legs".
           ACCEPT num2.
           PERFORM headleg-PARA.
           if count1 equals 2 DISPLAY "NONE"
           STOP RUN.

       X-PARA.
           ACCEPT A(I).
           IF (B < A(I))
           MOVE A(I) TO B.

       Y-PARA.
           MOVE 0 TO C.
           COMPUTE D = D + 1.
           PERFORM Z-PARA VARYING J FROM 1 BY 1 UNTIL J > N.

       Z-PARA.
           COMPUTE K = B * D.
           DIVIDE K BY A(J) GIVING Q REMAINDER R.
           IF (R = 0)
           COMPUTE C = C + 1.

       headleg-PARA.
           PERFORM VARYING chickens FROM 0 BY 1 UNTIL chickens >= num
           COMPUTE dogs = num - chickens
           COMPUTE result =2 * chickens
           COMPUTE result1 =4 * dogs
           COMPUTE result2 = result + result1
           IF result2 EQUALS num2
               DISPLAY "[", chickens,",",dogs,"]"
               SET count1 to 1
           ELSE IF count1 equals to 1 set count1 to 1
           else set count1 to 2
           END-IF
           END-PERFORM.
