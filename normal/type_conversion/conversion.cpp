#include<iostream>

int main(int argc, char*argv[])
{
    int a = 3;
    int b = 17;
    float c = 31.0f;

        //类型转换运算符优先级低于括号，高于运算符。
    
    printf("%f  float(a/b)*c \n",float (a/b)*c); //首先进行a/b运算，然后把结果转成float，然后与c相乘
    printf("%f  (float(a/b))*c \n",(float(a/b))*c); //首先进行a/b运算，然后把结果转成float，然后与c相乘
    printf("%f  (float(a/b))*c \n",(float) a/b*c); //首先把a转成浮点，然后除以b，然后乘以c

    printf("%f a/b*c \n", a/b*c); //运算规则同数学运算。a/b=0, 0*c=0.00000f
    printf("%f a/(b*c) \n", a/(b*c)); //运算规则同数学运算。b*c=527.00000f, a/527.0000f=0.005693
    return 0;
}
