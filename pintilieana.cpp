#include<stdio.h>
#include<malloc.h>
#include<conio.h>

// citire vector cu returnarea numarului de elemente prin numele subprogramului
// I: x(vectorul) ,  n(dimensiunea vectorului) 
int citireV ( float x[],int n)
{
int i ;
printf("n=");
scanf_s("&d",&n);
for (i=0;i<n;i++) 
{
printf ("x[%f]=",i);
scanf_s("%f",&x[i]);
}
return n;
}
// citirea elementelor unei matrice
// I: a (matricea) m(nr de linii), n(nr de coloane)
void citire_mat(float a[][100], int *m, int *n)
{
int i, j;
printf ("numarul de linii=");
scanf_s ("%d",m);
printf ("numarul de coloane=");
scanf_s ("&d", n);
for (i=0;i<*m;i++)
for (j=0;j<*n;j++)
{
printf ( "[%f][%f]=", i,j);
scanf_s("%f",&a[i][j]);
}
}

//afisare elemente dintr-un vector
//I:vectorul-x,dimensiunea vectorului-n
//E:elementele vectorului

void afisareV (float x[],int n)
    {int i;
for(i=0;i<n;i++)
	printf("%5.2f", x[i]);
    }


//afisare elementele unei matrice
//I:matricea-a,nr linii-m,nr coloane-n
//E:elementele matricei

void afisare_mat(float a[][100],int m,int n)
{int i,j;
printf("matricea este\n");
for(i=0;i<m;i++)
   {for(j=0;j<n;j++)
printf("%5.2f",a[i][j]);
printf("\n");
   }
}

   
// Suma elementelor vectorului
// I: v(vectorul), nr de linii=n
// E: s(suma)
float suma(int n, float v[])
{
int i;
float s=0;
for(i=1;i<=n;i++)
{
if(v[i]!=0)
{
s=s+v[i];
}
}
return s;
}
// Sortarea elementelor unui vector
// I: v(vectorul) ,nr de linii=n
// E: vectorul sortat
void sortare( float v[], int n)
{
	int i,j;
	float aux;
	for( i=0;i<n;i++)
		for ( j=i+1;j<n; j++)
			if (v[i]>v[j])
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
}
//Produsul a doua matrice
// I: m1(prima matrice), m2( a doua matrice), nr de linii=m, nr de coloane=n
// E: m3 ( matricea rezultat) 
void produs ( float a1[][100], float a2[][100],float a3[][100], int m , int n,int i,int j,int k,int p )
	
{
	a3[i][j]=0;
	for(i=0;i<m;i++)
		for (j=0;j<p;j++)
		{
			for(k=0;k<n;k++)
				a3[i][j]=a3[i][j]+a1[i][k]*a2[k][j];
		}
}

//Alocare vector
// I: m=dimensiune vector
// E: p(vectorul alocat)
int *alocareV ( int m)
{
	int *p;
	p= (int*)malloc (m*sizeof(int));
	return p;
}
// dezalocarea unei matrice
// I:  m- nr de linii
void dezalocare (int **mat, int m)
{
	int i;
	for (i=0;i<m;i++)
		free(*(mat +i));
	free (mat);
}
// Eliminarea unei coloane dintr-o matrice 
//I: m1 (matricea) , nr de coloane=m, nr de linii=n , nr de coloane de sters =k
//E: matricea rezultata
void eliminare_col(float **m1, int m, int *n, int k)
{
 int i,j;

 for(i=0;i<m;i++)
 for(j=k;j<(*n)-1;j++)
 m1[i][j]=m1[i][j+1];
 (*n)--;
}
// Produsul scalar 
//I: v1( primul vector), p2(al doilea vector), m=nr de linii
// E : p(produsul scalar)
void ps( float v1[],float v2[], int m)
{
	int i;
	float p;
	p=1;
	for (i=0;i<m;i++)
		p=p+v1[i]*v2[i];
}
//produs vectorial a doi vectori
//i:vectorul1-a,vectorul2-b,dimensiunea vectorilor-n
//e:produsul vectorial:p

void pv(float a[],float b[] ,float p[],int n)
{ for(int i=0;i<n;i++)
p[i]=a[i]*b[i];
}
//suma elementelor de sub diagonala secundara,exclusiv diagonala
//I:matricea –a,nr de linii-m
//E:suma-s

void suma(float a[][100],int m,float *s)
{*s=0;
for(int i=1;i<m;i++)
for(int j=m-i;j<m;j++)
*s+=a[i][j];
}

//alocare matrice
//I:nr de linii-m,nr coloane-n
//E:matricea-mat
int **alocare(int m,int n)
{int i,**mat;
mat=(int**)malloc(m*sizeof(int*));
for(i=0;i<m;i++)
*(mat+i)=(int*)malloc(n*sizeof(int));
return mat;
}



