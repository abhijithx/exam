#include <stdio.h>

int parent[10];

int main(){
    int v,i,j;
    int matrix[10][10];
    printf("ENTER NO OF VERTICES: ");
    scanf("%d", &v);

    printf("ENTER ADJACENCY MATRIX:\n");
    for (i = 0; i < v; i++)

    {
        parent[i] = i;
        for (j = 0; j < v; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                matrix[i][j] = 999;
        }
    }
    int edge,total;
    printf("minu mkjfjk cost tree\n");
    while(edge < v-1){
        int min = 99;
        int a = -1;
        int b = -1;
        for( i =0 ;i<v;i++){
            for(j = 0;j<v;j++){
                if(matrix[i][j] < min){
                    a = i;
                    b = j;
                }
            }
        }
        int u = find(a);
        int v2 = find(b);
        if(u != v2){
            printf{"%d -> %d  cost %d\n"}
        }

    }
    


}