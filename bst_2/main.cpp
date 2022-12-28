#include <iostream>

using namespace std;

class node{
public:
    node *lchild;
    node *rchild;
    int data;

};

class tree{
public:
    node *loc;
    node *ploc;
    node *root;
 tree(){
     loc = nullptr;
     ploc = nullptr;
     root = nullptr;

 }

// Task # 1

bool isempty(){
     return root == nullptr;
 }


// Task # 2
void search(int value){
    ploc = nullptr;
    loc = root;

while (loc != nullptr && loc ->data != value){
        if (loc->data > value){
            ploc = loc;
            loc = loc->lchild;
        }
        else{
            ploc = loc;
            loc = loc ->rchild;
        }
}

 }

 // Task # 3
void insert(int value){
     search(value);
     if (loc == nullptr){
         node * nn = new node();
         nn -> data = value;
         if (ploc == nullptr && root == nullptr){
             root = nn;
         }
         else{
             if (value < ploc ->data){
                 ploc->lchild = nn;
             }
             else{
                 ploc->rchild = nn;
             }
         }
     }
     else{
         cout << "The value already exist" << endl;
     }
 }

// Task # 4 1
void preorder(node *root){
     if(root != nullptr){
         cout << root->data<<" ";
         preorder(root->lchild);
         preorder(root->rchild);
     }

 }
// Task # 4 2
 void postorder(node *root){
     if (root != nullptr){
         postorder(root->lchild);
         postorder(root->rchild);
         cout << root->data<<" ";
     }

 }
// Task # 4 3
 void inorder(node *root){
     if(root != nullptr){
         inorder(root -> lchild);
         cout<< root->data << " ";
         inorder(root->rchild);
     }
 }

// Task # 7


// Task # 9


 // Task  10
int heighttree(node *root){
    if (root == nullptr){
        return -1;
    }
    else{
        return  (max(heighttree(root->lchild), heighttree(root->rchild)) +1);
    }
}

//Task # 11
    int calculateDepth(node* root, int parentDepth){
        if(root==nullptr){
            return parentDepth;
        }
        return max(calculateDepth(root->rchild, parentDepth+1), calculateDepth(root->lchild, parentDepth+1));
    }



//Task # 12


    //Task # 13
void destroytree(node *root){
     if (root != nullptr){
         destroytree(root->lchild);
         destroytree(root->rchild);
         delete root;
     }
 }

// destroy leaf nodes



void deletenode(int value){
        search(value);
        if(loc!= nullptr)
        {
            node*ploc1;
            node*loc1;
            loc1=loc;
            ploc1=ploc;
            if (loc->lchild != nullptr && loc ->rchild != nullptr){

                ploc = loc;
                loc=loc->lchild;
                while(loc->rchild!= nullptr){
                    ploc = loc;
                    loc= loc->rchild;
                }
            }
            if(loc->lchild == nullptr && loc->rchild == nullptr){
                if (loc == root){
                    root = nullptr;
                }
                else if(loc==ploc->lchild){
                    ploc->lchild = nullptr;
                }
                else if (loc==ploc->rchild ){
                    ploc->rchild = nullptr;
                }
            }

            else if(loc->lchild != nullptr && loc ->rchild == nullptr)
            {
                if (ploc)  // the loc is not at root
                {
                    if(loc == ploc->lchild){
                        ploc->lchild = loc->lchild;
                    }
                    else{
                        ploc->rchild= loc->lchild;
                    }
                }
                else
                {
                    root = loc->lchild;
                }
            }

            else if (loc ->rchild != nullptr && loc ->lchild == nullptr){
                if (ploc)
                {


                    if(loc == ploc->lchild){
                        ploc->lchild= loc->lchild;
                    }
                    else{
                        ploc ->rchild = loc->lchild;
                    }
                }
                else
                {
                    root = loc->rchild;
                }
            }


            // deleting and replacing
            if(value == loc->data){
                delete loc;
            }
            else {
                loc->lchild = loc1->lchild;
                loc->rchild = loc1->rchild;
                if (ploc1)
                {


                    if(loc1==ploc1->lchild){
                        ploc1->lchild = loc;
                    }
                    else{
                        ploc1->rchild = loc;
                    }
                }
                else
                {
                    root = loc;
                }
            }

            avlcaller(root, nullptr);
        }
        else{
            cout<<"The value does not exsists"<<endl;
        }

    }

void avlcaller(node*root1,node*parent){
     if(root1!= nullptr){
    avlcaller(root1->lchild,root1);
    avlcaller(root1->rchild,root1);
    int a = height_diffchecker(root1);
    if (a == +2 || a == -2) {

        avl_converter(root1,parent);
    }}
     else{
         cout<<"";
     }
}


void avl_converter(node*root2,node*parent){
     int node_diff= height_diffchecker(root2);
     //left rotation
     if(node_diff==-2){

         node *x; node * y;

         x=root2;
         y=root2->rchild;
         int l_height= heighttree(y->lchild);
         int r_height = heighttree(y->rchild);
//         case true then there is right left rotation
         if(r_height+1 == l_height ){
             node*x1;
             node *  y1;
             x1=y;
             y1= y->lchild;
             x1->lchild= y1->rchild;
             y1->rchild=x1;
             x->rchild=y1;
             y=y1;

         }

         x->rchild=y->lchild;
         y->lchild=x;
         if(parent!= nullptr){
          if(parent->lchild==x){
              parent->lchild=y;
          }
          else{
              parent->rchild=y;
          }
         } else{
             root=y;
         }

     }
//     right rotation
        if(node_diff==+2){
            node *x; node * y;
            x=root2;

            y=x->lchild;
            int l_height= heighttree(y->lchild);
            int r_height = heighttree(y->rchild);
//            case true the left right rotation
            if(l_height+1==r_height){
                node*x1;
                node *  y1;
                x1=y;
                y1= y->rchild;
                x1->rchild= y1->lchild;
                y1->lchild=x1;
                x->lchild=y1;
                y=y1;
            }
            x->lchild=y->rchild;
            y->rchild=x;
            if(parent!= nullptr){
                if(parent->lchild==x){
                    parent->lchild=y;
                }
                else{
                    parent->rchild=y;
                }
            }
            else{
                root=y;
            }
        }
        cout<<"preorder"<<endl;
        preorder(root);
        cout<<endl;
 }

int height_diffchecker(node*alpha){
     if (alpha!= nullptr){
     int l_height=0;
     l_height = heighttree(alpha->lchild);
     int r_height=0;
     r_height = heighttree((alpha->rchild));
     int diff_height;
     diff_height= l_height-r_height;
     return diff_height;
     }

     else {
         return 0;
     }
 }

};

int main() {

    tree t1;
    int count =0;
    int depth = 0;
    for(int i = 0; i<11 ; i++){
        int x;
        cin>>x;
        t1.insert(x);
        cout<<"preorder"<<endl;
        t1.preorder(t1.root);
        cout<<endl;
        t1.avlcaller(t1.root, nullptr);
    }
    cout<<"preorder"<<endl;
    t1.preorder(t1.root);
    cout<<endl;






}

