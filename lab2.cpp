#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;
// Created by User on 2021/11/2.
//状态 整数集 int []
//目标 给定的值 int
//选择 0-len(集合)
//结果

int* read_data(int num,int len){
    int *index=new int[len];
    int* data=new int[len];
    int datalen=0;
    string a="D:\\onedrive\\OneDrive - sjtu.edu.cn\\c++files\\suanfa_lab3\\data";
    string b=to_string(num);
    string c=".dat";

//    ifstream file(a+b+c);
    ifstream file(a+b+c,ios::in);
    if(!file) {//文件没打开
        cout<<("文件打不开");
    }
    while( ! file.eof()&&datalen<2*len ) {
        if (datalen%2==0)
        {file >> index[datalen/2];
            datalen++;

        }
        else {
            file >> data[datalen/2];
            datalen=datalen+1;
        }
//        cout<<"写入第"<<datalen<<"个数";
    }

//    for(int i=0;i<datalen;i++)
//    {
//        cout<<data[i]<<" ";
//    }

    file.close();
    return data;
}
int   ** initialize_2d(int side,int height) {

    int **array;
    int i;
    array = new int *[side];//申请side个面
    for (i = 0; i < side; i++)   //对每个面申请height行
    {
        array[i] = new int[height];
        //array[i]={0};
    }
    return array;
}

void pretty_print(bool * index,int * items){
    int sum=0;
    for (int i=0;i<1000;i++){
        if (index[i]==1){
            cout<<i<<endl;
            sum+=items[i];
        }

    }
    cout<<"sum:"<<sum;
}
int dynamicProgramming1(int * items, int n, int w)
{
    bool* states = new bool[w + 1];
    bool** path = new bool *[n];
        for (int i = 0; i < n; i++)
        {
            path[i] = new bool[w];
        }
    for (int i = 0; i != w + 1; ++i) {
        states[i] = false;
    }
    states[0] = true;
    if (items[0]<=w){states[items[0]] = true;//先进行一些初始化
    path[0][items[0]]=1;}

    for (int i = 1; i != n; ++i) {//依次处理第i个物体

        for (int j = w - items[i]; j >= 0; --j) {//依次遍历重量，更新states
            if (states[j] == true)
                {
                states[j + items[i]] = true;
                path[i][j + items[i]]=1;
                }
        }
    }
    int final_sum;
    for (int i = w; i >= 0; --i) {//找到最终result
        if (states[i] == true){
            //pretty_print(index,items);
            final_sum=i;
            break;
        }
    }
    int index=final_sum;
    int test=0;
    for (int i = n-1; i >= 0; i--)//路径回溯
        {
            if (path[i][index] == 1)
            {
                cout << "no." << i << " " << items[i] << endl;
                test+=items[i];
                index = index - items[i];
            }
        }
    cout<<"sum:"<<final_sum;
    if (test!=final_sum)cout<<"error!";
    else cout<<"数组下标选择正确！";
//    for (int i = w; i >= 0; --i) {
//        if (states[i] == true){
//            //pretty_print(index,items);
//            return i;
//        }
//    }
    return final_sum;
    return 0;
}

int lab2(int num,int len) {
    int *w = read_data(num, len);
    //for (int i = 0; i < len; i++) cout<<w[i]<<endl;
    int *b=&w[1];
    //cout << w[0];
    dynamicProgramming1(b,len-1,w[0]);
    //for (int i = 0; i < 4; i++) cout<<w[i]<<endl;
    //cout<<"3到这没问题";
    //for (int i = 0; i < len; i++) cout<<w[i]<<endl;
    //int **dp=initialize_2d(len,w[0]+1);
    //int **dp=initialize_2d(len,w[0]+1);
    //cout<<"1到这没问题";
//    static int dp[w[0] + 1] = 0;
//    //for (int j=0;j<w[0]+1;j++)dp[0][j]=0;
//    //cout<<"2到这没问题";
//    for (int i = 1; i < len; i++) {
//        for (int j = 0; j < w[0] + 1; j++) {
//            if (j >= w[i - 1])
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + w[i - 1]);
//            else
//                dp[i][j] = dp[i - 1][j];
//        }
//    }
//}
//    for(i=0;i<n;i++)
//    {
//        for(v=sum;v>=w[i];v--)
//        {
//            dp[v] = max_2( dp[v], dp[v-w[i]]+p[i] );
//        }
//    }
//return dp[len-1][w[0]];
//}

}
int main()
{


    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    lab2(2,4);
    std::chrono::steady_clock::time_point  t2 = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<milliseconds>(t2 - now);
    std::cout << "It took me " << time_span.count() << " milliseconds";

//    static  int array  [1111111]={0};
//    array[1111110]=1;
//    cout<<array[1111110];
}