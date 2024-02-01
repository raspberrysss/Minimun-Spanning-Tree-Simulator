#ifndef MST_H
#define MST_H

#include <QWidget>

const int MAX=100;
const double MAXInt=32767;

namespace Ui {
class MST;
}

struct edge_k
{
   QString head;//边的始点
   QString tail;//边的终点
   double lowcost_k;//边上的权值
};//kruscal辅助数组

class MST : public QWidget
{
    Q_OBJECT

public:
    explicit MST(QWidget *parent = nullptr);
    ~MST();
    double distance(QPoint p1,QPoint p2);//计算两点间距离
    void clean();//清除提示信息和右边框信息
    bool is_in(QPoint p1,QPoint p2,int n=14);//判断鼠标是否点击成功,即在半径为14的范围内点击，都算成功
    void Prim(int k);//普里姆算法求最小生成树,k为起点下标
    void Kruscal();//克鲁斯卡尔算法求最小生成树
    void Sort();
    int locate(QString qs);
   // bool cmp(edge_k &a,edge_k &b);

private:
    Ui::MST *ui;
    int condition;//状态，点击不同的按钮变换，在不同状态下有不同的后续操作，方便配合鼠标事件与绘图事件
    int vex_num;//顶点数与边数
    int edge_num;
    double edge[MAX][MAX];//邻接矩阵
    QPoint vex[MAX];//顶点集，每个坐标代表一个顶点
    QString vex_in[MAX];//顶点信息
    int num_mst;//最小生成树的边数
    int count;//默认点信息
    QPoint P1,P2;//两个临时点，用来临时存储点信息，方便做添加边时的比较
    int Vexset[MAX];//kruscal辅助数组，排除环出现
    edge_k EK[MAX];//kruscal辅助数组，包含边与点，类似于edge_two

public:
    bool show_b;

//public slots private slots different?
public slots:
    //？这两个函数名字固定，是特殊函数
    void mousePressEvent(QMouseEvent * event);//鼠标功能实现
    void paintEvent(QPaintEvent *);//绘图函数，一定要用paintEvent

private slots:
    void on_addvex_clicked();
    void on_addadj_clicked();
    void on_showweight_clicked();
    void on_changew_clicked();
    void on_delevex_clicked();
    void on_changein_clicked();
    void on_deleadj_clicked();
    void on_prim_clicked();
    void on_k_clicked();
    void on_clean_2_clicked();
    void on_clean_clicked();
};

struct edge_two//由两个点组成的边，方便后续进行变色
{
    int a;//点下标
    int b;//点下标
    bool flag=false;//false 不变色
};
//?字节对齐警告
/*
struct close_edge
{
    QString adjvex;//最小边在u中的顶点
    double lowcost;//最小权值
};//prim算法辅助数组
*/
extern struct edge_two edge_two[100];
extern struct edge_two ed;

//extern struct close_edge closeedge[100];
//extern struct close_edge close;

int min(struct close_edge c[],int n_v);
bool cmp(edge_k &a,edge_k &b);

#endif // MST_H
