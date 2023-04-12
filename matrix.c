#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** make_matrix(int row, int col);//�����Ҵ��� �̿��Ͽ� ����� ����� �Լ�
int print_matrix(int **arr,int row,int col);//����� ����ϴ� �Լ�
int additon_matrix(int **a,int **b,int row,int col,int row_x,int col_x);//������� ���� ���ϴ� �Լ�
int subtraction_matrix(int **a,int **b,int row,int col,int row_x,int col_x);//������� ���� ���ϴ� �Լ�
int transpose_matrix(int **a,int row,int col);//A�� ��ġ ����� ���ϴ� �Լ�
int multiply_matrix(int **a,int **b,int row_a,int col_a,int row_b,int col_b);//������� ���� ���ϴ� �Լ�
int free_matrix(int** matrix, int row);//�����޸��Ҵ� �����ϴ� �Լ�

int main()
{
    printf("[----- [������]   [2022041065] -----]\n");
    srand((unsigned)time(NULL));
    int row_a,row_b,column_a,column_b;
    while(1){

        printf("A�� : ");
        scanf("%d", &row_a);//A����� �� ���� �Է¹ޱ�
        printf("A�� : ");
        scanf("%d", &column_a);//A����� �� ���� �Է¹ޱ�
        printf("B�� : ");
        scanf("%d", &row_b);//B����� �� ���� �Է¹ޱ�
        printf("B�� : ");
        scanf("%d", &column_b);//B����� �� ���� �Է¹ޱ�

        if(row_a <0 || column_a<0||row_b<0||column_b<0){
            printf("�ٽ� �Է����ּ���\n");//���̳� ���� ������ �ԷµǸ� �ٽ� �Է��ϵ��� ���ѷ����� ����
        }
        else{
            break;
        }
    }

    int **a=make_matrix(row_a,column_a);//���� ������ a�� make_matrix�Լ��� �̿��Ͽ� �����Ҵ� ��Ų��

    int **b=make_matrix(row_b,column_b);//���� ������ b�� make_matrix�Լ��� �̿��Ͽ� �����Ҵ� ��Ų��
    
    printf("��� A\n");
    print_matrix(a,row_a,column_a);//print_matrix�Լ��� ����Ͽ� a��� ��� --> ��� a�� ���� Ȯ�� �ϱ� ���� 
    printf("��� B\n");
    print_matrix(b,row_b,column_b);//print_matrix�Լ��� ����Ͽ� b��� ���-->��� b�� ���� Ȯ�� �ϱ� ���� 

    additon_matrix(a,b,row_a,column_a,row_b,column_b);//additon_matrix�Լ��� ����Ͽ� ���A�� B�� ������ ���
    subtraction_matrix(a,b,row_a,column_a,row_b,column_b);//subtraction_matrix�Լ��� ����Ͽ� ���A�� B�� ������ ���

    transpose_matrix(a,row_a,column_a);//transpose_matrix�Լ��� ����Ͽ� ��� A�� ��ġ��� ���Ͽ� ���
    multiply_matrix(a,b,row_a,column_a,row_b,column_b);//multiply_matrix�Լ��� ����Ͽ� ��� A��B�� ������ ���Ͽ� ���

    return 0;
}

//���������͸� �����Ҵ��� ���� �޸𸮸� �Ҵ����ִ� �Լ�
int** make_matrix(int row, int column){

  int** arr = (int**)malloc(sizeof(int*) * row);//���������� arr�� �����޸� �Ҵ��Ŵ
  
  for(int i=0; i<row; i++)
  {
       arr[i]=(int*)malloc(sizeof(int)*column);//arr[i]�� �����޸� �Ҵ��Ŵ
  }

  for(int i=0; i<row; i++)
  {
    for(int j=0; j<column; j++)
    {
        arr[i][j]=(rand()%11);//rand�Լ��� ����Ͽ� 0���� 10������ �ϳ��� ���� arr[i][j]�� ����
    }
  }

  return arr;//arr�� ����
}

//A��B��� ���
int print_matrix(int **arr,int row,int column){ 

     for (int i = 0; i < row; i++) { 
        for(int j = 0; j < column; j++)
        { 
            printf("%d ", arr[i][j]);//�ݺ����� ���Ͽ� **arr�� ������ش�
        }
            printf("\n");
    }

    return 0;
}

//��� a�� b�� ���� ���ϴ� �Լ� 
int additon_matrix(int **a,int **b,int row,int col,int row_x,int col_x)
{
    if((row==row_x)&&(col==col_x))//��� a,b�� ��� ���� ũ�Ⱑ ���� ������ ���
    {
        int **sum=make_matrix(row, col);//**sum�� �����޸� �Ҵ��� ���� �޸𸮸� �Ҵ�
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                sum[i][j]=a[i][j]+b[i][j];//�ݺ����� ����ϸ� sum�� ��� a�� b�� ���� �����Ѵ�.
            }
        }
        printf("<Add Matrix : A+B>\n");
        print_matrix(sum, row, col);//print_matrix�Լ��� ����Ͽ� ��� sum �� ���
        free_matrix(sum,row);//free_matrix�Լ��� ȣ���Ͽ� sum�� �Ҵ�� �޸𸮸� ����
    }

    else{//��� ���� ���ǿ� �������� ���� ���
        printf("<Add Matrix : A+B>\n");
        printf("��� ũ�� ���� ����!\n");
    }

    return 0;
}

//��� A�� B�� ���� ���ϴ� �Լ�
int subtraction_matrix(int **a,int **b,int row,int col,int row_x,int col_x)
{
     if((row==row_x)&&(col==col_x))//A�� ��� B�� ���� ������ ���� A�� ���� B�� ���� ������ ������ ���� ����
    {
        int **sub=make_matrix(row, col);//sub�� �����޸� �Ҵ��� ���� �޸𸮸� �Ҵ�

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                sub[i][j]=a[i][j]-b[i][j];//�ݺ����� ���Ͽ� sub�� ��� a�� b�� ���� ����
            }
        }
        printf("<subrtact Matrix : A-B>\n");
        print_matrix(sub, row, col);//print_matrix�Լ��� ȣ���Ͽ� sub����� ���
        free_matrix(sub,row);//**sub�� �����޸� �Ҵ�
    }
    //��� ũ�Ⱑ ���� ���� ���� ��°�
    else{
        printf("<subrtact Matrix : A-B>\n");
        printf("��� ũ�� ���� ����!\n");
    }

    
    return 0;
}

//A�� ��ġ���
int transpose_matrix(int **a,int row,int col)
{
    printf("< A�� ��ġ��� >\n");
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            printf("%d ",a[j][i]);//�ݺ����� ����Ͽ� ��ġ����� ���ؼ� ���
        }
        printf("\n");
    }
   
    return 0;
}

//�� ����� ���ϴ� �Լ� 
int multiply_matrix(int **a,int **b,int row_a,int col_a,int row_b,int col_b)
{
    

    if(col_a!=row_b){//�� ����� ���Ҷ��� ���ǿ� �������� �� ��°�
        printf("< Multiply Matrix AxB >\n");
        printf("ũ�Ⱑ ���� ����!\n");
    }
    else{//�� ����� ũ�Ⱑ ���� ��
        int **multi=make_matrix(row_a,col_b);//**multi�� �����޸� �Ҵ��� ���� �޸𸮸� �Ҵ�
            for(int i=0; i<row_a; i++)
            {
                for(int j=0; j<col_b; j++)
                {
                    multi[i][j]=0;//�ݺ����� ���Ͽ� ���multi�� ���� 0���� �������
                    for(int k = 0; k < col_a; k++)
				        multi[i][j] += a[i][k] * b[k][j];//�ݺ����� ���� multi�� ��� a�� b�� ���� ���Ͽ� ���� ����
                }   
            }
           
            printf("< Multiply Matrix AxB  >\n");
            print_matrix(multi,row_a,col_b);//print_matrix�Լ��� ���Ͽ� multi���
            free_matrix(multi,row_a);//free_matrix�Լ��� ���Ͽ� multi�޸� ����
        }       
        return 0;
}

//�������� �Ҵ�� �޸𸮸� ���� �ϴ� �Լ� 
int free_matrix(int** arr, int row)
{
    for(int i=0; i<row; i++)
    {
        free(arr[i]);//�ݺ����� ����Ͽ� arr[i]�� �޸𸮸� ����
    }
    free(arr);//arr�޸� ����

    return 0;
}


