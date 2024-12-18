#include <iostream>
using namespace std;

const int V=6;

int *Dijkstra(int **GR, int V, int st) {
//�������� �������� - ������� ���������� ������� ����� st
//����� GR ������������ V	�� ���� ���������
//������ ������ ����������, INT_MAX - ������� ���
     int *distance, count, index, i, u;
     bool *visited;
     distance = new int [V];
     visited = new bool [V];
     for (i=0; i<V; i++) { distance[i]=INT_MAX; visited[i]=false; }
        distance[st]=0;
     for (count=0; count<V-1; count++) {
          int min=INT_MAX;
          for (i=0; i<V; i++)
            if (!visited[i] && distance[i]<=min) { min=distance[i]; index=i; }
          u=index;
          visited[u]=true;
          for (i=0; i<V; i++)
            if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX &&
               distance[u]+GR[u][i]<distance[i])
           distance[i]=distance[u]+GR[u][i];
     }
     return distance;
}

void main() {
     setlocale(LC_ALL, "Rus");
     int start, **GR;
     GR = new int * [V];
     for (int i=0; i<V; i++) GR[i] = new int [V]; //���������������� ������� ��������� GR
  
     int DATA[] = { //0 - ��� �����, ����� ������������� "���" �����
          0, 0, 11, 26, 0, 12,
          0, 0, 17, 20, 0, 0,
          11, 17, 0, 0, 15, 0,
          26, 20, 0, 0, 38, 0,
          0, 0, 15, 38, 0, 23,
          12, 0, 0, 0, 23, 0
     };
     int i,j,k=0;
     for (i=0; i<V; i++)
     for (j=0; j<V; j++) GR[i][j]=DATA[k++];

     start=5; //��������� �������, ��������� � 0

     int *distance=Dijkstra(GR, V, start);

     int m=start+1;
     cout << "���������� ���������� �� ������� 6 �� ���������:\n";
     for (i=0; i<V; i++) 
      if (distance[i]!=INT_MAX)
       cout << m << " > " << i+1 << " = " << distance[i] << endl;
      else cout << m << " > " << i+1 << " = " << "������� ����������" << endl;

     system("pause>>void");
}