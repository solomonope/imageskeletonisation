#include<stdio.h>
#include "skelatonisation.h"
void pdisplay(char *s, int *A,int nrow,int ncol)
{
int i, j;
 printf("%s\n", s);
 for (i=0; i<nrow; i++)
    {for (j=0; j<ncol; j++) printf("%1d", A[i*ncol+j]);
     printf("\n");
    }
 printf("\n\n");
  
}  
static int  neighbours(int *src, int prow,int pcol,int ncol ,int  * p2,int * p3,int  *p4,int  * p5, int * p6 ,int * p7, int  * p8,int * p9){
  
  
if(src == NULL || p2 ==NULL || p3 == NULL || p4 == NULL ||p5 == NULL || p6 == NULL || p7 == NULL || p8 == NULL|| p9 == NULL) return -1;
  
if(!(prow >= 0) || !(pcol >=0)) return -1;
  
  
     
*p2 = src[(prow+1)*ncol+pcol];  //* (*(src + (prow+1)) + pcol);//src[(prow+1)][pcol];
*p3 = src[(prow+1)*ncol+(pcol-1)]; //src[(prow+1)][(pcol+1)];
*p4 = src[prow*ncol+(pcol-1)]; //src[prow][pcol+1];
*p5 = src[(prow-1)*ncol+(pcol-1)]; // src[prow-1][pcol+1];
*p6 = src[(prow-1)*ncol+pcol]; //src[prow-1][pcol];
*p7 = src[(prow-1)*ncol+(pcol+1)]; //src[prow-1][pcol-1];
*p8 = src[prow*ncol+(pcol+1)]; //src[prow][pcol-1];
*p9 = src[(prow+1)*ncol+(pcol+1)]; //src[prow+1][pcol-1];
  
return 0;
  
}
  
  
int  A (int  *src,int prow,int pcol,int ncol){
  
int n=0;
int p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0,p9=0;
if(src == NULL) return -1;
  
if(!(prow >=0) || !(pcol >=0)) return -1;
  
if(neighbours(src,prow,pcol,ncol,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9) < 0) return -1;
    n += (p2  == 0  && p3 == 1) ? 1 : 0;
    n += (p3  == 0  && p4== 1) ? 1 : 0;
    n += (p4  == 0  && p5 == 1) ? 1 : 0;
    n += (p5  == 0  && p6 == 1) ? 1 : 0;
    n += (p7  == 0  && p8 == 1) ? 1 : 0;
    n += (p8  == 0  && p9 == 1) ? 1 : 0;
    n += (p9  == 0  && p2 == 1) ? 1 : 0;
    return n;
  
}
  
  
int B(int * src,int prow,int pcol,int ncol){
  
int p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0,p9=0;
if(src == NULL) return -1;
  
if((prow <0) || (pcol <0)) return -1;
  
if(neighbours(src,prow,pcol,ncol,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9) < 0) return -1;
  
return (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9);
  
}
  
  
int skeletonise(int* src,int * tag, int nrow,int ncol){
  
int i=0,j=0;
 int changed = 0; 
int re = src[4*ncol+j];
if(src == NULL ||tag == NULL) return -1;
  
if(nrow<0 || ncol < 0) return -1;
  
do{
  
  changed  = 0;
if(l2r(src,tag,nrow,ncol) < 0) return -1;
  
  
if(r2l(src,tag,nrow,ncol)<0) return -1;
  
  
  
for(;i<nrow;i++){
  
    for(j=0;j<ncol;j++)
    {
        if(tag[i*ncol+j] ==1 && src[i*ncol+j] ==1){
			changed = 1;
        src[i*ncol+j] = 0;
		tag[i*ncol+j] =0;
		} 
     
    }
  
}
 pdisplay("SKEL", src,nrow,ncol);
  pdisplay("TAG2", tag,nrow,ncol);
  
}while(changed); // not quite clear on the stop condition.
  
//Set all tagged pixels to 0 in image

  
  
  
  
  
}//end of function
  
int   l2r(int  * src , int  * tag, int nrow, int ncol)
{
     
int i=0,j=0;
int a=0,b=0;
int p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0,p9=0;
if(src == NULL ||tag == NULL) return -1;
  
if(nrow<0 || ncol < 0) return -1;
  
  
  
for(i=1;i<nrow-1 ;i++)
{
  
for(j=1;j<ncol-1;j++){
if(neighbours(src,i,j,ncol,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9) < 0) continue;
a =A(src,i,j,ncol);
b = B(src,i,j,ncol);
if ( (b >= 2 && b <= 6) && (a == 1) && !(p2 && p4 && p8) && !(p2 && p4 && p8)) {
             
            tag[i*ncol+j] = 1; 
             
        }
}
  
  
}
  
  
return 0;
  
}
  
int   r2l(int * src , int  * tag, int nrow, int ncol){
     
  
int i=0,j=0;
int a=0,b=0;
int p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0,p9=0;
if(src == NULL ||tag == NULL) return -1;
  
if(nrow<0 || ncol < 0) return -1;
  
  
  
for(j=1;j<ncol-1 ;j++)
{
  
for(i=1;i<nrow-1;i++){
if(neighbours(src,i,j,ncol,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9) < 0) return -1;
a =A(src,i,j,ncol);
b = B(src,i,j,ncol);
if ( (b >= 2 && b <= 6) && (a == 1) && !(p2 && p4 && p8) && !(p2 && p4 && p8)) {
  
                        tag[i*ncol+j] = 1; 
                }
}
  
  
}
  
  
return 0;
}