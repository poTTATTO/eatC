#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

struct Node* InsertNode(struct Node* current,struct Node* head, int data);
void DestoryNode(struct Node* destory);
struct Node* CreateNode(int data);
void PrintNodeFrom(const struct Node* head);
int CountNode(const struct Node* head);
int SearchNode(const struct Node* search);



int main(){
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, Node1, 200);
   

    PrintNodeFrom(Node1);
    // int cnt = CountNode(Node1);
    // printf("%d\n", cnt);
    // printf("%d\n", SearchNode(Node5));
    // DestoryNode(Node4);
    // putchar('\n');
    // PrintNodeFrom(Node1);
    return 0;
}
// 새 노드를 만드는 함수 

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = newNode;
    newNode->prevNode = newNode;
    return newNode;
}

struct Node* InsertNode(struct Node* current, int data){
    struct Node* after = current->nextNode;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    after->prevNode = newNode;
    newNode->nextNode = after;
    newNode->data = data;
    newNode->prevNode = current;
    

    current->nextNode = newNode;
    
    return newNode;
}

void DestoryNode(struct Node* destroy){
    if(destroy == NULL) return;
    if(!(destroy->nextNode==destroy && destroy->prevNode ==destroy)){   
        destroy->prevNode->nextNode = destroy->nextNode;
        destroy->nextNode->prevNode = destroy->prevNode;
    }

    free(destroy);
}

void PrintNodeFrom(const struct Node* head){
    int flag = 0;
    const struct Node* from = head;
    while(!flag){

        printf("%d\tmy : %p\tprev : %p\tnext : %p\n",
            from->data, from, from->prevNode, from->nextNode);

        from = from->nextNode;
        if(from == head)
            flag = 1;
    }

}

int CountNode(const struct Node* head){
    const struct Node* next = head;
    int cnt = 0;
    int flag=0;
    while(!flag){
        ++cnt;
        next = next->nextNode;
        if(next == head)
            flag = 1;
    }

    return cnt;
}

int SearchNode(const struct Node* search){
    return search->data;
}