#include <iostream>
//打印矩阵
void print_matrix(double **A,int m,int n)
{
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < n;j++)
        {
            std::cout<<A[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
//使用代数余子式求矩阵的值
double determinant_value(double **D,int n)
{
    //递归终点
    if(n==1)
    {
        return  D[0][0];
    }
    else if(n==2)
    {
        return D[1][1]*D[0][0]-D[0][1]*D[1][0];
    }
    else{
        double D_value=0;
        for(int k=0;k<n;k++)
        {
            double **D_temp=new double *[n-1];
            int i2=1;//由于是根据第0行第j列展开，所以原本的行列式直接从第一行开始拷贝
            for(int i1=0;i1<n-1;i1++)
            {
                D_temp[i1]=new double[n-1];
                int j2=0;
                for(int j1=0;j1<n-1;j1++)
                {
                    if(j2==k)
                    {
                        j2++;
                    }//去除第j列
                    D_temp[i1][j1]=D[i2][j2++];
                }
                i2++;
            }
            D_value+=((k&0x0001)?(-1):1)*D[0][k]*determinant_value(D_temp,n-1);//计算代数余子式与对应项的乘积
        }
        return D_value;
    }
}
//求伴随矩阵 
void Adjoint_matrices(double **A,double **A_adj,int n)
{
    double **A_AlgebraicRemainder=new double *[n-1];//暂时存放代数余子式的矩阵
    for (int i = 0; i < n-1;i++)
    {
        A_AlgebraicRemainder[i]=new double[n-1];//初始化分配空间
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            int i1 = 0;
            for (int i = 0; i < n-1; i++)
            {
                if(i1==x)
                {
                    i1++;
                }
                int j1 = 0;
                for (int j = 0; j < n-1; j++)
                {
                    if(j1==y)
                    {
                        j1++;
                    }
                    A_AlgebraicRemainder[i][j]=A[i1][j1++];
                }
                i1++;
            }
            //实现了转置
            A_adj[y][x]=((x+y)&0x0001?(-1):1)*determinant_value(A_AlgebraicRemainder, n - 1);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        delete[] A_AlgebraicRemainder[i];
    }
    delete[] A_AlgebraicRemainder;
}

//求逆矩阵
void matrix_inverse(double **A,double **A_inverse,int n)
{
    double A_D=determinant_value(A,n);
    
    if (A_D == 0.0f)
        {
            std::cout << "矩阵不可逆" << std::endl;
            return;
        }
        else{
            if(n==1)
            {
                A_inverse[0][0]=1/A[0][0];
                return;
            }
            
            double **A_adj=new double *[n];
            for (int i = 0; i < n;i++)
            {
                A_adj[i]=new double[n];
            }
            Adjoint_matrices(A, A_adj, n);
            for (int i = 0; i < n;i++)
            {
                for (int j = 0; j < n;j++)
                {
                    A_inverse[i][j]=A_adj[i][j]/A_D;
                }
            }
            for (int i = 0; i < n; i++)
            {
                delete[] A_adj[i];
            }
            delete[] A_adj;
    }
}

int main() 
{
    int n;
    std::cout<<"输入矩阵维度";
    std::cin>>n;//输入数组维度
    double **A=new double *[n];
    std::cout<<"输入矩阵元素:"<<std::endl;
    for(int i=0;i<n;i++)
    {
        A[i]=new double[n];
        for(int j=0;j<n;j++)
        {
            std::cin>>A[i][j];//每次输入一个数字都用空格隔开,输入样例
            //1 2 3\enter
            //4 5 6\enter
            //7 8 9\enter
        }
    }
    double **A_inverse=new double *[n];
    for(int i=0;i<n;i++)
    {
        A_inverse[i]=new double[n];
    }
    matrix_inverse(A, A_inverse, n);
    std::cout<<"The inverse matrix is:"<<std::endl;
    print_matrix(A_inverse, n, n);
    return 0;
}
