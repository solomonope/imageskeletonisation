#ifndef      _SKELETONISATION_H
  
#define      _SKELETONISATION_H
  
#define  NULL  0
  
static int  neighbours(int * src, int prow,int pcol,int ncol,int  * p2,int * p3,int  *p4,int  * p5, int * p6, int * p7 ,int  * p8,int * p9);
  
  
int  A(int* src,int prow,int pcol,int ncol);
  
  
int  B(int * src, int prow, int pcol,int ncol);
  
  
int skeletonise(int * src ,int * tag, int nrow,int ncol);
  
int   l2r(int * src, int * tag, int nrow, int ncol);
  
int   r2l(int * src, int * tag, int nrow, int ncol);
  
  
  
#endif


