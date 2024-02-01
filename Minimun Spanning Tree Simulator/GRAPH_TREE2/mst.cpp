#include "mst.h"
#include "ui_mst.h"

#include<QPaintEvent>
#include<QPainter>
#include<QMessageBox>
#include<QDebug>
#include<QInputDialog>

#include<cmath>
#include<algorithm>//sort函数

struct edge_two edge_two[100];
struct edge_two ed;

//!有很多不统一的地方，有时间再看看，改一下
//! 动态实现，学习QTime类
//! 点变色
//! struct和class的结合
//! private slots和public slots
//! extern 的使用
//! closeedge数组分文件定义为什么不可以
//! bool cmp sort static

//struct close_edge colseedge[100];

//struct close_edge close;

//using namespace std;

struct close_edge
{
    QString adjvex;//最小边在u中的顶点
    double lowcost;//最小权值
}closeedge[100];//prim辅助数组


MST::MST(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MST)
{
    ui->setupUi(this);
    condition=0;//初始为0，当点击按钮时发生改变
    vex_num=0;//初始化邻接矩阵
    edge_num=0;
    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<MAX;j++)
        {
            edge[i][j]=MAXInt;
        }
    }
    num_mst=0;
    count=0;
    show_b=false;
    //对顶点集和顶点信息先不进行初始化，因为现在还不会

}

double MST::distance(QPoint p1, QPoint p2)
{
    //两点间距离公式中间符号是加号！
    return sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+(p1.y()-p2.y())*(p1.y()-p2.y()));
}

void MST::clean()
{
    ui->listWidget->clear();
    ui->qidian->setText("");
    for (int i = 1; i <= edge_num; i++)
    {
        if (edge_two[i].flag)
        {
            edge_two[i].flag = false;
        }//红线变回蓝线
    }
    update();//调用paintEvent函数
}

int min(struct close_edge c[],int n_v)
{
    //找结构体数组中的最小边的下标，返回下标
    int i;
    int j=0;
    double min=MAXInt;
    for(i=1;i<=n_v;i++)
    {
        if(c[i].lowcost<min&&c[i].lowcost!=0)
        {
            min=c[i].lowcost;
            j=i;
        }
    }
    return j;
}

void MST::Prim(int k)
{
    int i,j,w,e,r;
    for(j=1;j<=vex_num;j++)//等于1等于0，明天再看，今天好困
    {
        if(j!=k)
        {
            closeedge[j].adjvex=vex_in[k];//vex_in存的是顶点标签，先这样写，或者QString改成QPoint
            closeedge[j].lowcost=edge[k][j];
        }
    }
    closeedge[k].lowcost=0;
    for( i=1;i<vex_num;i++)//循环n-1次，不知道会不会有错误，先不改
    {
        //里面的判断不能都用i，不然循环会出错
           k=min(closeedge,vex_num);
           QString u0,v0;
           int u0_i=0;
           int v0_i=0;
           u0=closeedge[k].adjvex;
           v0=vex_in[k];
           //当第一个顶点的下标为u0的下标，第二个顶点的下标为v0的下标，则变色
           for(w=1;w<=vex_num;w++)
           {
               if(u0==vex_in[w])
               {
                   qDebug()<<"hello2";
                    u0_i=w;
               }
           }
           for(e=1;e<=vex_num;e++)
           {
               //qDebug()<<vex_in[e];
               if(v0==vex_in[e])
               {
                   qDebug()<<"hello3";
                    v0_i=e;
               }
           }
           for(r=1;r<=edge_num;r++)
           {
               //edge_two均是小下标在前，比较时也要调整一下
               //qDebug()<<edge_two[r].a<<" "<<edge_two[r].b;
               if(edge_two[r].a==u0_i&&edge_two[r].b==v0_i)
               {
                   qDebug()<<"hello4";
                    edge_two[r].flag=true;
               }
               else if(edge_two[r].a==v0_i&&edge_two[r].b==u0_i)
               {
                   qDebug()<<"hello5";
                    edge_two[r].flag=true;
               }
           }
           //edge_two[k].flag=true;//变色
           ui->listWidget->addItem(u0+"->"+v0);//无法循环？
           qDebug()<<u0<<"->"<<v0;//结果正确，接下来要将其与可视化连接
           closeedge[k].lowcost=0;
           for(j=1;j<=vex_num;j++)
           {
               if(edge[k][j]<closeedge[j].lowcost)
               {
                   closeedge[j].adjvex=vex_in[k];
                   closeedge[j].lowcost=edge[k][j];
               }
           }
           qDebug()<<i;

    }
    update();
}

bool cmp(edge_k &a,edge_k &b)//它要放在外面，或者都声明为static
{
    return a.lowcost_k<b.lowcost_k;
}//重载

void MST:: Sort()
{
    std::sort(EK,EK+edge_num+1,cmp);//sort要在std里使用,下标从一开始，最后的地址要再加一
}

int MST::locate(QString qs)
{
    for(int i=1;i<=vex_num;i++)
    {
        if(qs==vex_in[i])
        {
            return i;
        }
    }
    return -1;
}

void MST::Kruscal()
{

    int i,j,v1,v2,vs1,vs2;
    int p,l,m;
   /* for(i=1;i<=edge_num;i++)
    {
        qDebug()<<EK[i].head<<" "<<EK[i].tail<<" "<<EK[i].lowcost_k;
    }*/
    for(i=1;i<=edge_num;i++)
    {
        EK[i].head=vex_in[edge_two[i].a];
        EK[i].tail=vex_in[edge_two[i].b];
        EK[i].lowcost_k=edge[edge_two[i].a][edge_two[i].b];
    }
   /* for(i=1;i<=edge_num;i++)
    {
        qDebug()<<EK[i].head<<" "<<EK[i].tail<<" "<<EK[i].lowcost_k;
    }*/
    Sort();
    //排序出现错误,别忘了下标从1开始
    //先赋值，再排序
    qDebug()<<"排好序的EK数组";
    for(i=1;i<=edge_num;i++)
    {
        qDebug()<<EK[i].head<<" "<<EK[i].tail<<" "<<EK[i].lowcost_k;
    }
    for(i=1;i<=vex_num;i++)
    {
        Vexset[i]=i;
    }
    for(i=1;i<=edge_num;i++)
    {
        v1=locate(EK[i].head);
        v2=locate(EK[i].tail);
        vs1=Vexset[v1];
        vs2=Vexset[v2];
        //qDebug()<<vs1<<" "<<vs2;
        if(vs1!=vs2)
        {
            //qDebug()<<EK[i].head<<" "<<EK[i].tail;
            ui->listWidget->addItem(EK[i].head+"->"+EK[i].tail);
            p=locate(EK[i].head);
            l=locate(EK[i].tail);
            for(m=1;m<=edge_num;m++)
            {
                //edge_two均是小下标在前，比较时也要调整一下
                //qDebug()<<edge_two[r].a<<" "<<edge_two[r].b;
                if(edge_two[m].a==p&&edge_two[m].b==l)
                {
                    qDebug()<<"hello4";
                     edge_two[m].flag=true;
                }
                else if(edge_two[m].a==l&&edge_two[m].b==p)
                {
                    qDebug()<<"hello5";
                     edge_two[m].flag=true;
                }
            }
            for(j=1;j<=vex_num;j++)
            {
                if(Vexset[j]==vs2)
                {
                     Vexset[j]=vs1;
                }

            }
        }
    }
    update();
}

void MST::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//定义画笔，在当前窗口绘图
    QFont font1("Microsoft YaHei", 9);//字体
    QFont font2("Microsoft YaHei", 12);
    painter.drawRect(140, 70, 450, 350);//矩形大小，分别是x，y，weight，height
    painter.setFont(font1);
    painter.setRenderHint(QPainter::Antialiasing, true);//使接下来的绘图光滑
    for (int i = 1; i <= edge_num; i++)
    {
        if (!edge_two[i].flag)
        {
            painter.setPen(Qt::blue);//设置画笔颜色为蓝色
        }
        else
        {
            painter.setPen(Qt::red);//不然则变色为红
        }
        painter.drawLine(vex[edge_two[i].a], vex[edge_two[i].b]);//两点连线
    }

    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    painter.setFont(font2);
    //!如何让点变色呢，如果有时间，再想想写一下
    for (int i = 0; i <= vex_num; i++)//先把点存好，然后统一画出来
    {
        painter.drawEllipse(vex[i],7,7);//分别是QPoint qreal qreal qreal是qt中的数据类型，相当于浮点型 这里代表rx，ry半径。把点画出来
        painter.drawText(QPoint(vex[i].x() + 5, vex[i].y() + 6), vex_in[i]);//画出点的标签，pl[i]为标签
    }
    ui->vexnum->setText("点数：" + QString::number(vex_num));
    ui->edgenum->setText("边数：" + QString::number(edge_num));
   // qDebug()<<vex_num;
    painter.setPen(Qt::darkMagenta);
    if (show_b)//如果显示边
    {
        for (int i = 1; i < vex_num; i++)
        {
            //qDebug()<<"hello1";
            for (int j = i+1 ; j <=vex_num; j++)
            {
                if (edge[i][j]<MAXInt)//若边存在
                {
                    //qDebug()<<"hello";
                    int x1, y1;
                    x1 = (vex[i].x() + vex[j].x()) / 2 - 10;//中央偏左
                    y1 = (vex[i].y() + vex[j].y()) / 2 + 4;//中央偏下
                    painter.drawText(QPoint(x1, y1), QString::number(edge[i][j]));//权值显示在（x,y）位置处
                }
            }
        }

    }
   /* for(int i=1;i<=vex_num;i++)
    {
        for(int j=1;j<=vex_num;j++)
        {
            qDebug()<<edge[i][j];
        }
    }*/



}

void MST::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)//button（）返回影响产生这个事件的按钮,点击的是左按钮
    {
        QPoint temp=event->pos();//定义这个点为鼠标左键点击的位置
        //qDebug()<<temp;
        switch(condition)
        {
            case 1://添加点
            {
                if (vex_num < MAX && temp.x() >= 140 && temp.x() <= 590 && temp.y()>70 && temp.y() <= 420)//判断所加的点是否在窗口范围内
                {
                    int t=vex_num++;
                   // vex_num++;
                    //t=vex_num;
                    for (int i = 1; i < vex_num; i++)
                        if (is_in(temp, vex[i], 20))//判断两点是否太近，选中条件为“半径10的圆邻域”，故两点距离需要大于20
                        {
                            vex_num--;
                            QMessageBox::warning(this, "警告", "无法在附近点创建点");
                        }
                    if (t == vex_num)
                        {
                            break;//证明添加的点无法添加，直接退出
                        }
                    vex[vex_num] = event->pos();//当前位置赋给最新顶点
                    vex_in[vex_num] = QString::number(++count);//创建默认标签
                    update();
                }
                else if (vex_num == MAX)
                {
                    QMessageBox::warning(this, "警告", "点数已达上限");
                }
                else
                {
                     QMessageBox::warning(this, "警告", "点超出边界");
                }
                break;
            }
            case 2://添加边，选择第一个点
                {
                if (edge_num == MAX*MAX)
                   {
                        QMessageBox::warning(this, "警告", "边数已达上限");
                   }
                else
                {
                    for (int i = 1; i <= vex_num; i++)
                       {
                            if (is_in(temp, vex[i]))//选中，点击的位置是顶点集存在的位置，并且选中
                            {
                                //qDebug()<<"hello";
                                P1 = vex[i];//将这个顶点赋给临时点p1
                                //qDebug()<<vex[i];
                                edge_two[edge_num+1].a = i;//最开始是零，让其下标均从1开始
                                //存储下两个点连成的边的前一个边edge_two[1]=1
                                condition = 3;
                                ui->tishiinformation->setText("请选择第二个点");
                                break;//将第一个点信息存入P1，edge_two[edge_num]，并开始case3功能
                            }
                       }
                }
                 break;

                }
            case 3://添加边，选择第二个点
            {
                    int t;
                    for (int i = 1; i <= vex_num; i++){
                        if (vex[i] != P1 && is_in(temp, vex[i]))//若选中了与第一个点不同的点
                      {

                            t=edge_num++;//边的数量加一
                            P2 = vex[i];
                            edge_two[edge_num].b = i;//此时已经edge_num加一,所以它和前一个点构成第一个edge_two【1】
                            condition = 2;
                            if (edge_two[edge_num].a > edge_two[edge_num].b)//保证边的第一个点下标比第二个小,不然会出现nan错误
                            {//让a永远存小下标
                                int t1 = edge_two[edge_num].a;
                                edge_two[edge_num].a = edge_two[edge_num].b;
                                edge_two[edge_num].b = t1;
                            }
                            for (int j = 0; j < edge_num; j++)//判断是否边已经存在
                            {
                                if (edge_two[edge_num].a == edge_two[j].a && edge_two[edge_num].b ==edge_two[j].b)
                                {
                                    edge_two[j] = edge_two[0];
                                    QMessageBox::warning(this, "警告", "两条边重合");
                                    break;
                                }
                            }

                            if (t != edge_num)
                            {

                                edge[edge_two[edge_num].a][edge_two[edge_num].b] = edge[edge_two[edge_num].b][edge_two[edge_num].a] = distance(vex[edge_two[edge_num].a], vex[edge_two[edge_num].b]);
                                // qDebug()<<edge[edge_two[edge_num].a][edge_two[edge_num].b];
                            }


                            ui->tishiinformation->setText("请选择第一个点");
                            break;
                        }
                    }
                            update();
                            break;



            }
            case 4://修改权值，第一个点
            {

            if (edge_num== 0)
            {
                QMessageBox::warning(this, "警告", "无任何路径");
            }
            else
            {
                for (int i = 1; i <= vex_num; i++)
                {
                    if (is_in(temp, vex[i]))//选中
                    {
                        P1 = vex[i];
                        condition = 5;
                        ui->tishiinformation->setText("请选择要修改权值的第二个点");//转入下一个case
                        ed.a = i;//临时使用结构体
                        break;
                    }
                }
            }
                 break;
            }
            case 5://修改权值，第二个点
            {
            for (int i = 1; i <= vex_num; i++)
                if (vex[i] != P1 && is_in(temp, vex[i]))//不与第一个点重合
                {
                    P2 = vex[i];
                    ed.b = i;
                    condition = 4;
                    if (ed.a > ed.b)//保证线的第二个点下标大于第一个
                    {
                        int t1 = ed.a;
                        ed.a = ed.b;
                        ed.b = t1;
                    }
                    bool f0 = false;
                    for (int j = 1; j <= edge_num; j++)
                    {
                        if (ed.a == edge_two[j].a && ed.b == edge_two[j].b)
                        {
                            double number = QInputDialog::getDouble(this, "编辑权值", "输入浮点数(0.0001~999999)", edge[ed.a][ed.b], 0.0001, 999999, 4);
                            if (number<MAXInt)
                            {
                                edge[ed.a][ed.b] = edge[ed.b][ed.a] = number;
                            }
                            f0 = true;
                            break;
                        }
                    }
                    ui->tishiinformation->setText("请选择要修改权值的第一个点");
                    if (!f0) QMessageBox::warning(this, "警告", "找不到这条路径");
                    update();
                    break;
                }
            break;

            }
            case 6://删除点
            {
            if (vex_num == 0) QMessageBox::warning(this, "警告", "无任何点");
            else
                for (int i = 1; i <= vex_num; i++)
                    if (is_in(temp, vex[i]))//选中想要删除的点
                    {
                        for (int j = i; j < vex_num; j++)
                        {
                            vex[j] = vex[j + 1];//将删除的点后的点前移,没有前移，为什么？
                            vex_in[j] = vex_in[j + 1];//点的标签同理
                            for (int k = 1; k <= vex_num; k++)//此一系列对edge的操作使该点下标对应的行列删除
                                edge[j][k] = edge[j + 1][k];
                        }
                        for (int j = i; j < vex_num; j++)
                            for (int k = 1; k <= vex_num; k++)
                                edge[k][j] = edge[k][j + 1];
                        for (int j = 1; j <= vex_num; j++)
                            edge[j][vex_num] = edge[vex_num][j] = 0;
                        vex_in[vex_num] = vex_in[0];//最后一个点标签消失
                        vex[vex_num--] = vex[0];//最后一个点消失，从1开始，方便删除
                        for (int j = 1; j <= vex_num; j++)
                        {
                            if (i == edge_two[j].a || i == edge_two[j].b)
                            {
                                for (int k = j; k < edge_num; k++)
                                    edge_two[k] = edge_two[k + 1];
                                edge_two[edge_num--] = edge_two[0];//将最后一条边消除，同时线数量减一
                                j--;
                            }
                            else//下标原在被选中的点之后的点所在线的下标前移
                            {
                                if (edge_two[j].a > i) edge_two[j].a--;
                                if (edge_two[j].b > i) edge_two[j].b--;
                            }
                        }
                        update();
                        break;
                    }
            break;
            }
            case 7://改变点信息
            {
            if (vex_num== 0) QMessageBox::warning(this, "警告", "无任何点");
            else
                for (int i = 1; i <= vex_num; i++)
                    if (is_in(temp, vex[i]))
                    {
                        QString s0 = QInputDialog::getText(this, "编辑标签", "输入文本(最多13个字)");
                        if (s0 != "") vex_in[i] = s0.left(13);
                        break;
                    }
            break;
            }
            case 8://删除边的第一个点
            {
            if (edge_num == 0) QMessageBox::warning(this, "警告", "此图已无边，无法删除");
            else
                for (int i = 1; i <= vex_num; i++)
                    if (is_in(temp, vex[i]))//判断选中
                    {
                        P1 = vex[i];
                        ed.a = i;
                        condition = 9;
                        ui->tishiinformation->setText("请选择要删除边的第二个点");
                    }
            break;
            }
            case 9://删除边的第二个点
                {
            for (int i = 1; i <= vex_num; i++)
            {
                if (vex[i] != P1 && is_in(temp, vex[i]))//选中
                {
                    P2 = vex[i];
                    ed.b = i;
                    condition = 8;//第二个点信息载入
                    if (ed.a > ed.b)//保证边的第二个点下标大于第一个
                    {
                        int t1 = ed.a;
                        ed.a = ed.b;
                        ed.b = t1;
                    }
                    int t3 = edge_num;
                    for (int j = 1; j <= edge_num; j++)
                    {
                        if (ed.a == edge_two[j].a && ed.b == edge_two[j].b)
                        {
                            edge[edge_two[j].a][edge_two[j].b] = edge[edge_two[j].b][edge_two[j].a] = MAXInt;//点之间边的权值变为无穷大
                           { for (int k = j; k < edge_num; k++)
                                edge_two[k] = edge_two[k + 1];//边下标前移
                            edge_two[edge_num--] = edge_two[0];
                            break; }
                        }
                    }
                    ui->tishiinformation->setText("请选择要删除边的第一个点");
                    if (edge_num == t3) QMessageBox::warning(this, "警告", "找不到这条边");
                    else break;
                }
            }
            update();
            break;
                }
            case 10://prim
            {
            for (int i = 1; i <= vex_num; i++)
            {    if (is_in(temp, vex[i]))
                {
                   // P1 = vex[i];
                    //ed.a = i;//起点下标赋给ed
                    qDebug()<<"hello";
                     Prim(i);//对起点进行Prim算法，为什么在这里不行？无法显示，只能显示在可视化这里
                    ui->qidian->setText("起点：" + vex_in[i]);
                    qDebug()<<"hello1";
                    break;
                }
             }   break;
                //Prim(1);
               // break;
            }
            case 11://Kruscal
            {
                    //Kruscal不需要起点终点
                    qDebug()<<"hellok";
                    Kruscal();
                    qDebug()<<"hellok2";
                    break;
            }
        }

    }
}
bool MST::is_in(QPoint p1, QPoint p2, int n)
{
    if(distance(p1,p2)<=n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

MST::~MST()
{
    delete ui;
}



void MST::on_addvex_clicked()
{
    clean();
    if (condition!= 1)
    {
        condition = 1;
        ui->tishiinformation->setText("请选择一个位置添加点");
    }//转到case 1
    else if(condition ==0)
    {
        ui->tishiinformation->setText("");
    }//跳出
}

void MST::on_addadj_clicked()
{
    clean();
    if (condition!= 2)
    {
        condition = 2;
        ui->tishiinformation->setText("请选择第一个点");//转到case 2
    }
    else if(condition==0)
    {
        ui->tishiinformation->setText("");
    }//跳出
}

void MST::on_showweight_clicked()
{
    if (!show_b)
    {
        show_b = true;
        ui->showweight->setText("隐藏权值");
    }
    else
    {
        show_b = false;
        ui->showweight->setText("显示权值");//每点一下切换状态
    }
    update();
}

void MST::on_changew_clicked()
{
    clean();
    if (condition!= 4)
    {
        condition = 4;
        ui->tishiinformation->setText("请选择要修改权值的第一个点");//转到case5
    }
    else
    {
        condition = 0;
        ui->tishiinformation->setText("");//跳出
    }
}

void MST::on_delevex_clicked()
{
    clean();
    if (condition != 6)
    {
        condition = 6;
        ui->tishiinformation->setText("请选择一个位置删除点");//转到case 6
    }
    else
    {
        condition = 6;ui->tishiinformation->setText("");//跳出
    }
}

void MST::on_changein_clicked()
{
    clean();
    if (condition!= 7)
    {
        condition= 7;
        ui->tishiinformation->setText("请选择要修改信息的点");//转到case 7
    }
    else
    {
             condition = 0;
            ui->tishiinformation->setText("");//跳出
    }
}

void MST::on_deleadj_clicked()
{
    clean();
    if (condition!= 8)
    {
        condition= 8;
        ui->tishiinformation->setText("请选择要删除边的第一个点");//转到case 7
    }
    else
    {
             condition = 0;
            ui->tishiinformation->setText("");//跳出
    }
}

void MST::on_prim_clicked()
{
    clean();
    if (condition!= 10) {
        if ( edge_num== 0) { QMessageBox::warning(this, "警告", "无任何边"); return; }//判断整个地图是否存在边
        condition =10 ;
        ui->tishiinformation->setText("请选择起点");//转到case10
        ui->qidian->setText("起点："); ui->listWidget->clear();
        //ui->label_5->setText("");
        ui->listWidget->addItem("Prim算法的结果将会显示在这里");
    }
    else
    {
        condition= 0;
        ui->tishiinformation->setText("");//跳出
    }
}

void MST::on_k_clicked()//克鲁斯卡尔算法
{
    clean();
    if (condition!= 11) {
        if ( edge_num== 0) { QMessageBox::warning(this, "警告", "无任何边"); return; }//判断整个地图是否存在边
        condition =11 ;
        //ui->tishiinformation->setText("请选择起点");//转到case11
        //ui->qidian->setText("起点：");
        ui->tishiinformation->setText("点击任意区域开始kruscal算法");
        ui->listWidget->clear();
        //ui->label_5->setText("");
        ui->listWidget->addItem("Kruskal算法的结果将会显示在这里");
    }
    else
    {
        condition= 0;
        ui->tishiinformation->setText("");//跳出
    }
}

void MST::on_clean_2_clicked()
{
    clean();
}

void MST::on_clean_clicked()
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, "提示", "确认要清除此图吗？", QMessageBox::Yes | QMessageBox::No);
    if (btn == QMessageBox::Yes)//清除地图
    {

        for (int i = 1; i <= vex_num; i++)
        {
            vex[i] = vex[0];
            vex_in[i] = vex_in[0];
            for (int j = 1; j <= vex_num; j++)
                edge[i][j] =MAXInt;
        }
        for (int i = 1; i <=edge_num; i++)
        {
            edge_two[i] = edge_two[0];
        }

        for(int i=1;i<edge_num;i++)
        {
            EK[i].head="";
            EK[i].tail="";
            EK[i].lowcost_k=MAXInt;
        }
        for(int i=1;i<edge_num;i++)
        {
           closeedge[i].adjvex="";
           closeedge[i].lowcost=MAXInt;
        }
        condition=vex_num=edge_num= count = 0;
        clean();
        ui->tishiinformation->setText("");
    }
}
