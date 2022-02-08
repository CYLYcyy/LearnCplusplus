#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;
//�汾1,�Ȼ���ÿ�����µ�

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
//                cout << "����";
//                return -1;
//            }
//        }
//        if (index == 0 || index == mm + nn)
//        {
//            if (direction == 1)
//            {
//                cout << "����";
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

//�汾2,����ʱ����·��

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
//                cout << "����";
//                return -1;
//            }
//        }
//        if (index == 0 || index == mm + nn)
//        {
//            if (direction == 1)
//            {
//                cout << "����";
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

//���а汾
class BlackBox {
private:
    int n, m, cnt;

    //��������
    vector<int> group;              //ÿ��index��Ӧ���飨��·�������
    vector<int> seq;                //ÿ��index���Լ���������
    vector<int> direct;             //ÿ��index���Լ���������ʱ�Ĺ��߷���
    vector<vector<int>> table;      //����ź����ڵ���ŷ���index�ı�
    void record(int index, int g, int s, int d) {
        group[index] = g;
        seq[index] = s;
        direct[index] = d;
        table[g].push_back(index);
    }

    //��������
    vector<set<int>> T;             //���ڿ�������һ������

    //��������
    int getNext(int index, int d) {
        if (d == 1) return ((cnt - index) % cnt + cnt) % cnt;
        else return ((2 * m - index) % cnt + cnt) % cnt;
    }

    //������·
    void generate(int start, int d) {
        if (group[start] != -1) return;
        int g = T.size(), index = start, s = 0;     //gȡT.size()��ÿ����һ����·����ż�1
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

        //���ɰ��������������·��ע��ֻ��������������Ϊ���������ɵģ�����groupֵΪ0��1��������õ�
        generate(0, -1);
        generate(m, 1);
        generate(m + n, -1);
        generate(2 * m + n, 1);
    }

    int open(int index, int direction) {
        generate(index, 1);                             //����Ҫ��ʱ�����ɣ�û��Ҫ�ڳ�ʼ��ʱ����������·
        int g = group[index];                           //��ȡ���
        T[g].insert(seq[index]);                        //��ӿ���
        auto it = T[g].find(seq[index]);
        if (direction == direct[index]) {               //��������
            it = next(it);
            if (it == T[g].end()) {
                if (g == 0 || g == 1) return index;     //����ǰ����������·��ֱ���۷�
                it = T[g].begin();                      //����ѭ������ͷ
            }
        }
        else {                                        //��������
            if (it == T[g].begin()) {
                if (g == 0 || g == 1) return index;     //����ǰ����������·��ֱ���۷�
                it = prev(T[g].end());                  //����ѭ������β
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