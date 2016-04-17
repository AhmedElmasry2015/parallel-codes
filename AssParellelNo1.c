#include <stdio.h>
#include <stdlib.h>

/*void fill(int row1, int col1,int row2,int col2);
void print_matrix(int rows, int cols, double **mat);
void free_matrix(int rows, double **mat);*/
int **matrix1;
int **matrix2;
int frow1,frow2,fcol1,fcol2;
void FillFirstMatrix(int row1, int col1){
     matrix1 = (int **) malloc(sizeof(int *)*row1);
    int i=0,j=0;
    printf("\n");
    printf("please enter the first matrix");
    printf("\n");
    for(i=0; i<row1; i++)
        matrix1[i] = (int *) malloc(sizeof(int)*col1);

       for(i=0; i<row1; i++){
           for(j=0; j<col1; j++){
               scanf("%d",&matrix1[i][j]);
           }
       }
   }
void FillSecondMatrix(int row2,int col2){
matrix2 = (int **) malloc(sizeof(int *)*row2);
  int k=0,l=0;
printf("\n");
    printf("please enter the second matrix");
    printf("\n");
       for(k=0; k<row2; k++)
        matrix2[k] = (int *) malloc(sizeof(int)*col2);

       for(k=0; k<row2; k++){
           for(l=0; l<col2; l++){
               scanf("%d",&matrix2[k][l]);
           }
       }


}
int fileReadMatrix(){
	FILE *File;
    int num;
    int matrixOneSize,matrixTwoSize;
    
   File = fopen("matrix.txt", "r");
    if ((File=fopen("matrix.txt","r"))==NULL){
       printf("Error! opening file");
       exit(1);          //Program exits if file pointer returns NULL. 
   }
   
   fscanf(File, "%d,", &frow1 );
   fscanf(File, "%d,", &fcol1 );
   matrixOneSize=frow1*fcol1;
   int matrixOneArray[matrixOneSize];
   //  access elements of first matrix to first array
   int j=0;
   for(;j<matrixOneSize;j++){
        fscanf(File, "%d,", &matrixOneArray[j] );}
    //ini of malloc array
   matrix1=(int **)malloc(sizeof(int *)*frow1);
   int counter1=0;
       for(; counter1<frow1; counter1++)
        matrix1[counter1] = (int *) malloc(sizeof(int)*fcol1);
	int b=0,c=0;
		for(;b<frow1;b++){
			c=0;
			for(;c<fcol1;c++){
				
				matrix1[b][c]=matrixOneArray[b*fcol1+c];
			}
		}
		// matrix number 2
   fscanf(File, "%d,", &frow2 );   
   fscanf(File, "%d,", &fcol2 );
   matrixTwoSize=frow2*fcol2;
   int matrixTwoArray[matrixTwoSize];
   int l=0;
   for(;l<matrixTwoSize;l++){
        fscanf(File, "%d,", &matrixTwoArray[l] );}

	matrix2=(int **)malloc(sizeof(int *)*frow2);
   int counter2=0;
       for(; counter2<frow2; counter2++)
        matrix2[counter2] = (int *) malloc(sizeof(int)*fcol2);
	int v=0,m=0;
		for(;v<frow2;v++){
			m=0;
			for(;m<fcol2;m++){
				
				matrix2[v][m]=matrixTwoArray[v*fcol2+m];
			}
		}

   fclose(File);
    //return frow1;
}
int ffrow1(){
	return frow1;
}
int ffrow2(){
	return frow2;
}
int ffcol1(){
	return fcol1;
}
int ffcol2(){
	return fcol2;
}
    int **multiply(int row1,int col1,int row2,int col2){

     if(col1==row2)
    {
    int **matix_multi = (int **) malloc(sizeof(int *)*row1);
    int i=0,j=0,k=0;
    for(i=0; i<row1; i++)

        matix_multi[i] = (int *) malloc(sizeof(int)*col2);

        for(i=0;i<row1;i++)
        {
            for(j=0;j<col2;j++)
            {
                matix_multi[i][j]=0;
                for(k=0;k<row2;k++)
                {
                    matix_multi[i][j]=matix_multi[i][j]+matrix1[i][k]*matrix2[k][j];
                }
            }
        }


return matix_multi;
}

}


void print(int row1,int row2 ,int col1,int col2,int **mat_mult){
    
printf("\n");
printf("***********************");
printf("\n");


   if(col1 == row2){

    printf("the result of multiply is:");
    printf("\n");
    printf("************************\n");
    int k=0,l=0;
  for(k=0; k<row1; k++){
        for(l=0; l<col2; l++){
            printf("%d ",mat_mult[k][l]);
        }
        printf("\n");
    }
}
printf("\n");
printf("************************");
if(col1 !=row2)
{
    printf("it can't be multiply/n");
}

}



int main(){

printf("******Welcome	to	vector	Matrix	multiplication	program!!******\n\n\n");
printf("******if you want program to enter matrices from file Enter '1' ******\n");
printf("******if you want program to enter matrices from Console Enter '2' ******\n");
int enter;
scanf("%d",&enter);
if(enter==2){	
int **matrix_mult;
int row1,row2,col1,col2;
 /* First matrix */
  printf("Matrix 1\n");
printf("Please enter the dimensions of the first matrix");
printf("\n");
scanf("%d%d",&row1,&col1);
FillFirstMatrix(row1,col1);
/* second matrix*/
printf("Please enter the dimensions of the second matrix");
printf("\n");
scanf("%d%d",&row2,&col2);
FillSecondMatrix(row2,col2);

matrix_mult=multiply(row1,col1,row2,col2);
print(row1,row2,col1,col2,matrix_mult);}
else if(enter ==1){
int w,x,y,z;
int **matrix_mult;
fileReadMatrix();
w=ffrow1();
x=ffcol1();
y=ffrow2();;
z=ffcol2();
matrix_mult=multiply(w,x,y,z);
print(w,x,y,z,matrix_mult);
}
else{
	printf("you entered non-acceptable foramt please press 1 for console 2 for file\n\n");
}
system("pause");
  return 0;
 }

