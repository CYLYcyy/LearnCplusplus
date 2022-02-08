#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;
//版本1,先缓存每点上下点

//class BlackBox {
//public:
//    BlackBox(int n, int m) :mm(m),nn(n){
//        init(n, m);
//    }
//
//    int open(int index, int direction) {
//        pointOpen[index] = true;
//        
//        if (index == mm || index == 2 * mm + nn)
//        {
//            if (direction == -1)
//            {
//                cout << "错误";
//                return -1;
//            }
//        }
//        if (index == 0 || index == mm + nn)
//        {
//            if (direction == 1)
//            {
//                cout << "错误";
//                return -1;
//            }
//        }
//
//        direction *= -1;
//        if (direction == 1)
//            return reflect(pointRefectPosi[index], -direction);
//        else
//            return reflect(pointRefectNega[index], -direction);
//    }
//
//    void close(int index) {
//        pointOpen[index] = false;
//    }
//
//private:
//    vector<bool> pointOpen;
//    vector<int> pointRefectPosi;
//    vector<int> pointRefectNega;
//
//    int reflect(int index, int direction)
//    {
//        if (pointOpen[index])
//            return index;
//        else if (direction == 1)
//            return reflect(pointRefectPosi[index], -direction);
//        else
//            return reflect(pointRefectNega[index], -direction);
//    }
//
//    void init(int n, int m)
//    {
//        pointOpen.push_back(false);
//        pointRefectPosi.push_back(2 * m);
//        pointRefectNega.push_back(0);
//
//
//        for (int i = 1; i < m; i++)
//        {
//            pointOpen.push_back(false);
//            pointRefectPosi.push_back(m + (m - i));
//            pointRefectNega.push_back(2 * (m + n) - i);
//        }
//
//        pointOpen.push_back(false);
//        pointRefectPosi.push_back(m);
//        pointRefectNega.push_back(m + 2 * n);
//
//        for (int i = 1; i < n; i++)
//        {
//            pointOpen.push_back(false);
//            pointRefectPosi.push_back(m - i >= 0 ? m - i : 3 * m + 2 * n - i);
//            pointRefectNega.push_back(m + n + n - i);
//        }
//
//        pointOpen.push_back(false);
//        pointRefectPosi.push_back(3 * m + n < 2 * m + 2 * n ? 3 * m + n : m - n);
//        pointRefectNega.push_back(m + n);
//
//        for (int i = 1; i < m; i++)
//        {
//            pointOpen.push_back(false);
//            pointRefectPosi.push_back(3 * m + n - i < 2*m+2*n ? 3 * m + n - i : m - n - i);
//            pointRefectNega.push_back(m + n - i);
//        }
//
//        pointOpen.push_back(false);
//        pointRefectPosi.push_back(2 * m + n);
//        pointRefectNega.push_back(n);
//
//        for (int i = 1; i < n; i++)
//        {
//            pointOpen.push_back(false);
//            pointRefectPosi.push_back(2 * m + n - i);
//            pointRefectNega.push_back(n - i);
//        }
//    }
//
//    int mm;
//    int nn;
//};

//版本2,运行时计算路线

//class BlackBox {
//public:
//    BlackBox(int n, int m) :mm(m), nn(n) {
//        init(n, m);
//    }
//
//    int open(int index, int direction) {
//        pointOpen[index] = true;
//
//        if (index == mm || index == 2 * mm + nn)
//        {
//            if (direction == -1)
//            {
//                cout << "错误";
//                return -1;
//            }
//        }
//        if (index == 0 || index == mm + nn)
//        {
//            if (direction == 1)
//            {
//                cout << "错误";
//                return -1;
//            }
//        }
//
//        direction *= -1;
//        if (direction == 1)
//            return reflect(getNext1(index), -direction);
//        else
//            return reflect(getNext2(index), -direction);
//    }
//
//    void close(int index) {
//        pointOpen[index] = false;
//    }
//
//private:
//    vector<bool> pointOpen;
//
//    int reflect(int index, int direction)
//    {
//        if (pointOpen[index])
//            return index;
//        else if (direction == 1)
//            return reflect(getNext1(index), -direction);
//        else
//            return reflect(getNext2(index), -direction);
//    }
//
//    void init(int n, int m)
//    {
//        pointOpen.push_back(false);
//
//        for (int i = 1; i < m; i++)
//        {
//            pointOpen.push_back(false);
//        }
//
//        pointOpen.push_back(false);
//
//        for (int i = 1; i < n; i++)
//        {
//            pointOpen.push_back(false);
//        }
//
//        pointOpen.push_back(false);
//
//
//        for (int i = 1; i < m; i++)
//        {
//            pointOpen.push_back(false);
//        }
//
//        pointOpen.push_back(false);
//
//        for (int i = 1; i < n; i++)
//        {
//            pointOpen.push_back(false);
//        }
//    }
//    int getNext1(int index)
//    {
//        int i;
//        if (index >= 0 && index < mm)
//        {
//            i = index;
//            return mm + (mm- i);
//        }
//        else if (index >= mm && index < mm + nn)
//        {
//            i = index - mm;
//            return mm - i >= 0 ? mm - i : 3 * mm + 2 * nn - i;
//        }
//        else if (index >= mm + nn && index < 2 * mm + nn)
//        {
//            i = index - mm - nn;
//            return 3 * mm + nn - i < 2 * mm + 2 * nn ? 3 * mm + nn - i : mm - nn - i;
//        }
//        else if (index >= 2 * mm + nn && index < 2 * mm + 2 * nn)
//        {
//            i = index - 2*mm - nn;
//            return 2 * mm + nn - i;
//        }
//        return -1;
//    }
//    int getNext2(int index)
//    {
//        int i;
//        if (index >= 0 && index < mm)
//        {
//            i = index;
//            return 2 * (mm + nn) - i < 2 * (mm + nn) ? 2 * (mm + nn) - i : i;
//        }
//        else if (index >= mm && index < mm + nn)
//        {
//            i = index - mm;
//            return mm + nn + nn - i;
//        }
//        else if (index >= mm + nn && index < 2 * mm + nn)
//        {
//            i = index - mm - nn;
//            return mm + nn - i;
//        }
//        else if (index >= 2 * mm + nn && index < 2 * mm + 2 * nn)
//        {
//            i = index - 2 * mm - nn;
//            return nn - i;
//        }
//        return -1;
//    }
//    int mm;
//    int nn;
//};

//大佬版本
class BlackBox {
private:
    int n, m, cnt;

    //辅助数组
    vector<int> group;              //每个index对应的组（线路）的序号
    vector<int> seq;                //每个index在自己组里的序号
    vector<int> direct;             //每个index在自己组里正序时的光线方向
    vector<vector<int>> table;      //由组号和组内的序号反查index的表
    void record(int index, int g, int s, int d) {
        group[index] = g;
        seq[index] = s;
        direct[index] = d;
        table[g].push_back(index);
    }

    //核心数组
    vector<set<int>> T;             //用于快速找下一个出口

    //辅助函数
    int getNext(int index, int d) {
        if (d == 1) return ((cnt - index) % cnt + cnt) % cnt;
        else return ((2 * m - index) % cnt + cnt) % cnt;
    }

    //生成线路
    void generate(int start, int d) {
        if (group[start] != -1) return;
        int g = T.size(), index = start, s = 0;     //g取T.size()，每生成一条线路，序号加1
        T.push_back({});
        table.push_back({});
        record(index, g, s, d);
        while (true) {
            index = getNext(index, d);
            if (index == start) return;
            s++;
            d = (d == 1 ? -1 : 1);
            record(index, g, s, d);
            if (index == 0 || index == m || index == m + n || index == 2 * m + n) {
                return;
            }
        }
    }

public:
    BlackBox(int n, int m) : n(n), m(m), cnt(2 * (m + n)) {
        group = seq = direct = vector<int>(cnt, -1);

        //生成包含顶点的两条线路，注意只会生成两条。因为是最先生成的，所以group值为0和1，下面会用到
        generate(0, -1);
        generate(m, 1);
        generate(m + n, -1);
        generate(2 * m + n, 1);
    }

    int open(int index, int direction) {
        generate(index, 1);                             //在需要的时候生成，没必要在初始化时生成所有线路
        int g = group[index];                           //获取组号
        T[g].insert(seq[index]);                        //添加开孔
        auto it = T[g].find(seq[index]);
        if (direction == direct[index]) {               //正向搜索
            it = next(it);
            if (it == T[g].end()) {
                if (g == 0 || g == 1) return index;     //如果是包含顶点的线路，直接折返
                it = T[g].begin();                      //否则循环到开头
            }
        }
        else {                                        //反向搜索
            if (it == T[g].begin()) {
                if (g == 0 || g == 1) return index;     //如果是包含顶点的线路，直接折返
                it = prev(T[g].end());                  //否则循环到结尾
            }
            else {
                it = prev(it);
            }
        }
        return table[g][*it];
    }

    void close(int index) {
        T[group[index]].erase(seq[index]);
    }
};
/**
 * Your BlackBox object will be instantiated and called as such:
 * BlackBox* obj = new BlackBox(n, m);
 * int param_1 = obj->open(index,direction);
 * obj->close(index);
 */