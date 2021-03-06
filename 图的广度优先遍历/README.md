【问题描述】

根据输入信息创建图，采用邻接表的形式存储该图，并用广度优先遍历算法遍历该图，输出遍历序列。

【输入形式】

第一行为图的结点个数n，第二行为图的顶点数据，之后的n行为邻接矩阵的内容，每行n个数表示。其中A[i][j]=1表示两个结点邻接，而A[i][j]=0表示两个结点无邻接关系。

【输出形式】

图的广度优先遍历序列

【样例输入】
 5

1 2 3 4 5 

0 1 1 0 0

1 0 1 1 0

1 1 0 0 0

0 1 0 0 1

0 0 0 1 0

【输出形式】

1 2 3 4 5

【样例输入】

4

1 2 3 4

0 1 1 0

0 0 0 0

0 0 0 1

1 0 0 0

【样例输出】

1 2 3 4

【样例说明】

邻接矩阵中对角线上的元素都用0表示。

【评分标准】

输入时的邻接矩阵只是用来表示顶点之间的关系，而存储时一定要用邻接表存储，否则不得分。

由于遍历序列与图的存储有关，遍历序列不唯一，只需要得到其中一种序列便得分。
