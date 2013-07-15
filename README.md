imageskeletonisation
====================
ALGORITHM 
P5  P4  P3
P6	P1 P2

P7	P8	P9		 

              Figure 1, Pixel Connection 
A binary image is scanned from top to bottom and also from left to right during each scanning pass.  A pixel, P1, is deleted if four relationships with its 8-connected neighbors are satisfied, the relations are listed below. 
2 ≤ B(P1) ≤ 6 
A(P1) =  1 
P2  & P4 & P8 = 0 
P2 & P4 & P6 = 0 
   Where:  
A (P1) is the number of 0→1 transitions where the point that is set to 1 is not flagged in the ordered set {P2, P3, P4… P8, P9, P2} 
B (P1) is the number of non-zero neighbors of P1. 
The pixels are tagged for deletion and after each left to right and top to bottom pass they are removed. Without tagging, the removal of pixel P1 could alter the number of 0->1 transitions and the number of non-zero neighbors of pixels P2, P7, P8 or P9 when they are processed. 
 
 The algorithm continues until no pixels are removed in iteration.  
  
