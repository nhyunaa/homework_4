#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** make_matrix(int row, int col);//동적할당을 이용하여 행렬을 만드는 함수
int print_matrix(int **arr,int row,int col);//행렬을 출력하는 함수
int additon_matrix(int **a,int **b,int row,int col,int row_x,int col_x);//두행렬의 합을 구하는 함수
int subtraction_matrix(int **a,int **b,int row,int col,int row_x,int col_x);//두행렬의 차를 구하는 함수
int transpose_matrix(int **a,int row,int col);//A의 전치 행렬을 구하는 함수
int multiply_matrix(int **a,int **b,int row_a,int col_a,int row_b,int col_b);//두행렬의 곱을 구하는 함수
int free_matrix(int** matrix, int row);//동적메모리할당 해제하는 함수

int main()
{
    printf("[----- [노현아]   [2022041065] -----]\n");
    srand((unsigned)time(NULL));
    int row_a,row_b,column_a,column_b;
    while(1){

        printf("A행 : ");
        scanf("%d", &row_a);//A행렬의 행 개수 입력받기
        printf("A열 : ");
        scanf("%d", &column_a);//A행렬의 열 개수 입력받기
        printf("B행 : ");
        scanf("%d", &row_b);//B행렬의 행 개수 입력받기
        printf("B열 : ");
        scanf("%d", &column_b);//B행렬의 열 개수 입력받기

        if(row_a <0 || column_a<0||row_b<0||column_b<0){
            printf("다시 입력해주세요\n");//행이나 열이 음수가 입력되면 다시 입력하도록 무한루프를 돌림
        }
        else{
            break;
        }
    }

    int **a=make_matrix(row_a,column_a);//이중 포인터 a를 make_matrix함수를 이용하여 동적할당 시킨다

    int **b=make_matrix(row_b,column_b);//이중 포인터 b를 make_matrix함수를 이용하여 동적할당 시킨다
    
    printf("행렬 A\n");
    print_matrix(a,row_a,column_a);//print_matrix함수를 사용하여 a행렬 출력 --> 행렬 a의 값을 확인 하기 위해 
    printf("행렬 B\n");
    print_matrix(b,row_b,column_b);//print_matrix함수를 사용하여 b행렬 출력-->행렬 b의 값을 확인 하기 위해 

    additon_matrix(a,b,row_a,column_a,row_b,column_b);//additon_matrix함수를 사용하여 행렬A와 B의 덧셈을 출력
    subtraction_matrix(a,b,row_a,column_a,row_b,column_b);//subtraction_matrix함수를 사용하여 행렬A와 B의 뺄셈을 출력

    transpose_matrix(a,row_a,column_a);//transpose_matrix함수를 사용하여 행렬 A의 전치행렬 구하여 출력
    multiply_matrix(a,b,row_a,column_a,row_b,column_b);//multiply_matrix함수를 사용하여 행렬 A와B의 곱셈을 구하여 출력

    return 0;
}

//이중포인터를 동적할당을 통해 메모리를 할당해주는 함수
int** make_matrix(int row, int column){

  int** arr = (int**)malloc(sizeof(int*) * row);//이중포인터 arr를 동적메모리 할당시킴
  
  for(int i=0; i<row; i++)
  {
       arr[i]=(int*)malloc(sizeof(int)*column);//arr[i]를 동적메모리 할당시킴
  }

  for(int i=0; i<row; i++)
  {
    for(int j=0; j<column; j++)
    {
        arr[i][j]=(rand()%11);//rand함수를 사용하여 0부터 10까지중 하나의 값을 arr[i][j]에 대입
    }
  }

  return arr;//arr로 리턴
}

//A와B행렬 출력
int print_matrix(int **arr,int row,int column){ 

     for (int i = 0; i < row; i++) { 
        for(int j = 0; j < column; j++)
        { 
            printf("%d ", arr[i][j]);//반복문을 통하여 **arr를 출력해준다
        }
            printf("\n");
    }

    return 0;
}

//행렬 a와 b의 합을 구하는 함수 
int additon_matrix(int **a,int **b,int row,int col,int row_x,int col_x)
{
    if((row==row_x)&&(col==col_x))//행렬 a,b의 행과 열의 크기가 각각 동일한 경우
    {
        int **sum=make_matrix(row, col);//**sum을 동적메모리 할당을 통해 메모리를 할당
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                sum[i][j]=a[i][j]+b[i][j];//반복문을 사용하며 sum에 행렬 a와 b의 합을 대입한다.
            }
        }
        printf("<Add Matrix : A+B>\n");
        print_matrix(sum, row, col);//print_matrix함수를 사용하여 행렬 sum 을 출력
        free_matrix(sum,row);//free_matrix함수를 호출하여 sum에 할당된 메모리를 해제
    }

    else{//행렬 합의 조건에 부합하지 않을 경우
        printf("<Add Matrix : A+B>\n");
        printf("행렬 크기 맞지 않음!\n");
    }

    return 0;
}

//행렬 A와 B의 차를 구하는 함수
int subtraction_matrix(int **a,int **b,int row,int col,int row_x,int col_x)
{
     if((row==row_x)&&(col==col_x))//A의 행과 B의 행의 개수가 같고 A의 열과 B의 열의 개수가 같을때 구현 가능
    {
        int **sub=make_matrix(row, col);//sub를 동적메모리 할당을 통해 메모리를 할당

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                sub[i][j]=a[i][j]-b[i][j];//반복문을 통하여 sub에 행렬 a와 b의 차를 저장
            }
        }
        printf("<subrtact Matrix : A-B>\n");
        print_matrix(sub, row, col);//print_matrix함수를 호출하여 sub행렬을 출력
        free_matrix(sub,row);//**sub를 동적메모리 할당
    }
    //행렬 크기가 같지 않을 때의 출력값
    else{
        printf("<subrtact Matrix : A-B>\n");
        printf("행렬 크기 맞지 않음!\n");
    }

    
    return 0;
}

//A의 전치행렬
int transpose_matrix(int **a,int row,int col)
{
    printf("< A의 전치행렬 >\n");
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            printf("%d ",a[j][i]);//반복문을 사용하여 전치행렬을 구해서 출력
        }
        printf("\n");
    }
   
    return 0;
}

//두 행렬을 곱하는 함수 
int multiply_matrix(int **a,int **b,int row_a,int col_a,int row_b,int col_b)
{
    

    if(col_a!=row_b){//두 행렬을 곱할때의 조건에 맞지않을 때 출력값
        printf("< Multiply Matrix AxB >\n");
        printf("크기가 맞지 않음!\n");
    }
    else{//두 행렬의 크기가 같을 때
        int **multi=make_matrix(row_a,col_b);//**multi를 동적메모리 할당을 통해 메모리를 할당
            for(int i=0; i<row_a; i++)
            {
                for(int j=0; j<col_b; j++)
                {
                    multi[i][j]=0;//반복문을 통하여 행렬multi의 값을 0으로 만들어줌
                    for(int k = 0; k < col_a; k++)
				        multi[i][j] += a[i][k] * b[k][j];//반복문을 통해 multi에 행렬 a와 b의 곱을 구하여 값을 대입
                }   
            }
           
            printf("< Multiply Matrix AxB  >\n");
            print_matrix(multi,row_a,col_b);//print_matrix함수를 통하여 multi출력
            free_matrix(multi,row_a);//free_matrix함수를 통하여 multi메모리 해제
        }       
        return 0;
}

//동적으로 할당된 메모리를 해제 하는 함수 
int free_matrix(int** arr, int row)
{
    for(int i=0; i<row; i++)
    {
        free(arr[i]);//반복문을 사용하여 arr[i]의 메모리를 해제
    }
    free(arr);//arr메모리 해제

    return 0;
}


