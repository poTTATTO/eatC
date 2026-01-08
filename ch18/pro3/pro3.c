#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

struct Node* InsertNode(struct Node* current, int data);
void DestoryNode(struct Node* destory);
struct Node* CreateNode(int data);
void PrintNodeFrom(struct Node* from);
int CountNode(const struct Node* head);
int SearchNode(const struct Node* search);



int main(){
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node2, 400);
    struct Node* Node5 = InsertNode(Node3, 500);

    PrintNodeFrom(Node1);
    // int cnt = CountNode(Node1);
    // printf("%d\n", cnt);
    // printf("%d\n", SearchNode(Node5));
    DestoryNode(Node4);
    putchar('\n');
    PrintNodeFrom(Node1);
    return 0;
}
// 새 노드를 만드는 함수 

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    return newNode;
}

struct Node* InsertNode(struct Node* current, int data){
    struct Node* after = current->nextNode;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(after != NULL)
        after->prevNode = newNode;
    newNode->data = data;
    newNode->nextNode = after;
    newNode->prevNode = current;

    current->nextNode = newNode;
    
    return newNode;
}

void DestoryNode(struct Node* destroy){
    if(destroy == NULL) return;

    
    if(destroy->prevNode == NULL){
        if(destroy->nextNode != NULL){
            destroy->nextNode->prevNode = NULL;
        }
    }else{
        if(destroy->nextNode != NULL){
            destroy->nextNode->prevNode = destroy->prevNode;
        }
        destroy->prevNode->nextNode = destroy->nextNode;
    }

    free(destroy);
}

void PrintNodeFrom(struct Node* from){

    while(from){

        printf("%d\tmy : %p\tprev : %p\tnext : %p\n",
            from->data, from, from->prevNode, from->nextNode);

        from = from->nextNode;
    }

}

int CountNode(const struct Node* head){
    const struct Node* next = head;
    int cnt = 0;
    while(next){
        ++cnt;
        next = next->nextNode;
    }

    return cnt;
}

int SearchNode(const struct Node* search){
    return search->data;
}