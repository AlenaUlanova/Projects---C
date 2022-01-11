#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int top;
    struct Node* next;
};

struct Node* createNode (int t);

struct Graph
{
    int numTops;
    int* visit;
    struct Node** Lists;
};

struct Node* createNode(int t)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->top = t;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int tops)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numTops = tops;

    graph->Lists = malloc(tops * sizeof(struct node*));

    graph->visit = malloc(tops * sizeof(int));

    int i;
    for (i = 0; i < tops; i++) {
        graph->Lists[i] = NULL;
        graph->visit[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dst)
{

    struct Node* newNode = createNode(dst);
    newNode->next = graph->Lists[src];
    graph->Lists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->Lists[dst];
    graph->Lists[dst] = newNode;
}

void DFS(struct Graph* graph, int top) {
    struct Node* List = graph->Lists[top];
    struct Node* temp = List;

    graph->visit[top] = 1;
    printf("Рассмотрено %d \n", top);

    while(temp!=NULL) {
        int connectTop = temp->top;

        if(graph->visit[connectTop] == 0) {
            DFS(graph, connectTop);
        }
        temp = temp->next;
    }
}

void printGraph(struct Graph* graph)
{
    int t;
    for (t = 0; t < graph->numTops; t++)
    {
        struct Node* temp = graph->Lists[t];
        printf("\n Смежные вершины:  %d\n ", t);
        while (temp)
        {
            printf("%d -> ", temp -> top);
            temp = temp->next;
        }
        printf("\n");
    }
}

/******for task2******/

void printCount(struct Graph* graph)
{
    for (int t = 0; t < graph->numTops; t++)
    {
        struct Node* temp = graph->Lists[t];
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        printf("В вершине %d кол-во ссылок: %d\n", t, count);
    }
}
void DFS_1(struct Graph* graph, int top, int connect) {
    struct Node* List = graph->Lists[top];
    struct Node* temp = List;

    graph->visit[top] = 1;
    graph->visit[connect] = 1;

    while(temp!=NULL) {
        int connectTop = temp->top;
        if(graph->visit[connectTop] == 0) {
            printf("Смежная вершина для %d -> %d \n", top, connectTop);
            DFS_1(graph, top, connectTop);
        }
        temp = temp->next;
    }
}

int main()
{
        //task1
        {
            struct Graph *graph = createGraph(4);
            addEdge(graph, 0, 1);
            addEdge(graph, 0, 2);
            addEdge(graph, 1, 2);
            addEdge(graph, 2, 3);
            printGraph(graph);
            DFS(graph, 2);
        }
        //task2
        {
            printCount(graph);
            DFS_1(graph, 2, -1);
        }
    return 0;
}
