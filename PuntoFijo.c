#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char const *argv[]) {
  float f, fa, fb, g, x, dg, sup, inf, a, b, e, re;
  int i, d, j;
  printf("\tDeterminar la raiz positiva de la ecuación\n\n");
  printf("\t\t(sen x)^2  1\n");
  printf("\t\t-------  = -\n");
  printf("\t\t  x^2      2\n\n");
  printf("\t x en radianes utilizando el metodo de punto fijo, para\n");
  printf("una tolerancia <=0.0001 . Incluir el criterio de convergencia.\n\n");
  //Desarrollando algebra, se obtuvo la expresión de f
  //f=(sin(x))^2-(0.5*x^2);
  //g=(sin(x))^2-(0.5*x^2)+x; //g=f+x;
  //dg=(2*sin(x)*cos(x))-x+1; //derivada de la función g
  printf("\t\tf(x) = (sen x)^2 - 1/2(x^2)\n");
  printf("\t\tG(x) = (sen x)^2 - 1/2(x^2) + x\n");
  printf("\t\tG'(x) = 2 sen x cos x - x + 1\n\n");
  printf("\tTabulación de la función\n\n");
  printf("\t\t   x     |  f(x)\n");
  i=1;
  do{
    d=i-1;
    fa=(sin(d)*sin(d))-((float)(d*d)/(float)2);
    fb=(sin(i)*sin(i))-((float)(i*i)/(float)2);
    if(d==0){
      printf("\t\t   %i     |%f  \n",d,fa);
      printf("\t\t   %i     |%f  \n",i,fb);
    }else{
      printf("\t\t   %i     |%f  \n",i,fb);
    };
    a=(float)d;
    b=(float)i;
    i++;
  }while(fa*fb>=0);
  printf("\n\ta=%f\t\tb=%f\n",a,b);
  printf("\n\tCriterio de convergencia\n");
  printf("\n\t\tG'(T)<1\n");
  printf("\t\tT=x0=(a+b)/2\n");
  x=(a+b)/(float)2;
  dg=(2.0*sin(x)*cos(x))-x+(float)1;
  printf("\nT=x0=%f\n",x);
  printf("\nG'(T)=%f\n",dg);
  if(dg<1){
    printf("Si converge\n");
    j=0;
    printf("\n\tEcuacion de recurrencia\n");
    printf("\n\t\tx i+1 = G(xi)\n\n");
    printf("\tError absoluto o tolerancia\n\n");
    printf("\t\tE = | xi - x i-1 |\n");
    printf("\n\tEfectuando el método:\n");
    printf("\n\t   i     |   xi   |  x i+1 |   E\n");
    do{
      g=(sin(x)*sin(x))-((float)(x*x)/(float)2)+x;
      if(j==0){
        printf("\t   %i     |%f|%f|   N.A.\n",j,x,g);
        e=1;
      }else{
        e=fabs(g-x);
        printf("\t   %i     |%f|%f|%f\n",j,x,g,e);
      }
      x=g;
      j++;
    }while(e>0.0001);
    printf("\n\tPor lo tanto la raiz de la función es:\tx=%f\n",x);
  }else{
    printf("No converge\n");
  }
  return 0;
}
