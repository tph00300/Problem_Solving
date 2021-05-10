#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Node{
    private:
        int data;
        Node* prev;
        Node* next;
    public:
        Node (int input){
            prev=NULL,next=NULL,data=input;
        }
        int GetData() {return data;}
        Node* GetPrviousNode(){return prev;}
        Node* GetNextNode(){return next;}
        void InsertPreviousNode(Node* node){
            if(prev!=NULL)
            {
                node->prev=prev;
                prev->next=node;
            }
            prev=node;
            node->next=this;
        }
        void InsertNextNode(Node* node){
            if(next!=NULL)
            {
                node->next=next;
                next->prev=node;
            }
            next=node;
            next->prev=this;
        }
        void ErasePreviousNode(){
            remove(this->prev);
        }
        void EraseNextNode(){
            remove(this->next);
        }
        void remove(Node* node){
            Node* pNode=node->prev;
            Node* nNode=node->next;
            pNode->next=nNode;
            nNode->prev=pNode;
        }
};
int main()
{
    int n,m,i,j,k;

    scanf("%d %d",&n,&m);
    vector<int> arr(m+1,0);
    Node* Head;

    for(i=1; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
               
        Head->InsertNextNode(cnt);
    }

    return 0;
}