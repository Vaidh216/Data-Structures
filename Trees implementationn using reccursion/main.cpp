// Implementation
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* Create(int data){
    Node* NewNode = new Node();
    NewNode->data = data;
    NewNode->left=NULL;
    NewNode->right=NULL;

    return NewNode;
}

Node* insert(Node* root,int data){

    if(root==NULL){
        root = Create(data);
        return root;
    }else if(data<=root->data){
        root->left = insert(root->left,data);
        return root;
    }else{
        root->right = insert(root->right,data);
        return root;
    }
}

bool Search(Node* root,int data){

    if(root==NULL){
        return false;
    }else if(root->data==data){
        //cout<<"Here the data is : "<<root->data<<endl;
        return true;
    }else if(data<root->data){
        //cout<<"Here the data is : "<<root->data<<endl;
        return Search(root->left,data);
    }else{
        //cout<<"Here the data is : "<<root->data<<endl;
        return Search(root->right,data);
    }
}

int Height(Node* root){
    if(root==NULL){
        return -1;
    }
    return (max(Height(root->left),Height(root->right))+1);
}

int min(Node* root){
    Node* temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp->data;
}

int max(Node* root){
    Node* temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp->data;
}

void levelprint(Node *root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL)
            q.push(current->left);
        if(current->right!=NULL)
            q.push(current->right);
    }
}

void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node *FindMin(Node *root){
    while(root->left!=NULL)
        root = root->left;
    return root;
}

Node* Delete(Node* root,int data){
    if(root==NULL)
        return root;
    else if(data<root->data){
        root->left=Delete(root->left,data);
    }else if(data>root->data){
        root->right=Delete(root->right,data);
    }else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }else if(root->left==NULL){
            Node *temp=root;
            root = root->right;
            delete temp;
        }else if(root->right==NULL){
            Node *temp=root;
            root=root->left;
            delete temp;
        }else{
            Node* temp;
            temp = FindMin(root->right);
            root->data = temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}

int main(){
    cout<<"Here First type of binary Search tree is created by me Ghurrahu Singh : "<<endl;
    Node* root=NULL;
    /*int n;
    cout<<"How many values you want to enter : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        //cout<<"Enter the value : ";
        int temp;
        cin>>temp;
        root = insert(root,temp);
    }
    cout<<"The data of the root is " <<root->data;
    */

    root = insert(root,5);
    root = insert(root,10);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,1);
    root = insert(root,11);

    cout<<"The data is Entered : "<<endl;

    /*cout<<"The Height of the tree is : "<<Height(root)<<endl;

    cout<<"Now Enter the value you want to search : "<<endl;
    int temp;
    cin>>temp;
    if(Search(root,temp)==false){
        cout<<"The Given value is not found : "<<endl;
    }else{
        cout<<"The Given data is found : "<<endl;
    }

    cout<<"The maximum values is "<<max(root)<<endl;
    cout<<"The Minumun values is "<<min(root)<<endl;
    */

    cout<<"Printing level order : ";
    levelprint(root);
    cout<<endl;

    cout<<"Printing Preorder : "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Printting Inorder : "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Printing Postorder : "<<endl;
    postorder(root);
    cout<<endl;

    root = Delete(root,5);
    cout<<"Printing level order : ";
    levelprint(root);
    cout<<endl;

    cout<<"Printing Preorder : "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Printting Inorder : "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Printing Postorder : "<<endl;
    postorder(root);
    cout<<endl;

}
