#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
} *root = 0;

struct node *adnd(int val, struct node *root){
    if (!root){
        struct node *ip = (struct node *) malloc(sizeof (struct node));
        ip->val = val;
        ip->left = 0;
        ip->right = 0;
        printf("adnd %d\n",val);
        return ip;
    }
    if (val <= root->val)
        root->left = adnd(val, root->left);
    else
        root->right = adnd(val, root->right);
    printf("return %p\n", root);
    return root;
}

void pt(struct node *root){
    if (root){
        pt(root->left);
        printf("%d ",root->val);
        pt(root->right);
    }
}

//##################################

struct valnode{
    struct valnode *next;
    int crd;
    int val;
}; //*valroot = 0;

struct chnode{
    struct chnode *next;
    int crd;
    char sym;
}; //*chrroot = 0;

struct lvnode{
    struct lvnode *next;
    struct chnode *pnthdch;
    struct valnode *pnthdval;
    int lev;
} *hdlv = 0;

struct lvnode *adlvnd(int lev){
    struct lvnode *pnt = (struct lvnode *)malloc(sizeof(struct lvnode));
    pnt->next = 0;
    pnt->pnthdch = 0;
    pnt->pnthdval = 0;
    pnt->lev = lev;
    return pnt;
}

void advalnd(struct valnode *pntval, struct valnode *pnthdval){
    if(!pnthdval)
        pnthdval = pntval;
    //for (struct lvnode *pnt = hdlv; pnt; pnt = pnt->next)

}

void adchrnd(){

}

void insvalnd(struct valnode *pntval, int lev){
    if(!hdlv)
        hdlv = adlvnd(0);
    for (struct lvnode *pnt = hdlv; pnt; pnt = pnt->next)
        if (pnt->lev == lev-1){
            if(!pnt->next)
                pnt->next = adlvnd(lev);
            if(!pnt->next->pnthdval)
                pnt->next->pnthdval = pntval;
            advalnd(pntval, pnt->next->pnthdval);
            if(lev)
               // adchrnd(pnt->next->pnthdch);
            pnt = 0;
        }
}

void inft(struct node *root, int crd, int lev){
    if (root){
        {
            struct valnode *pntval = (struct valnode *)malloc(sizeof(struct valnode));
            pntval->val = root->val;
            pntval->crd = crd;
            insvalnd(pntval, lev);
            if (lev){
                struct chnode *pntch = (struct chnode *)malloc(sizeof(struct chnode));
            }
        }
        inft(root->left, crd-1, lev+1);
        inft(root->right, crd+1, lev+1);
    }
}

//#########################

int main(){
    //ptsch(6, root);
    root = adnd(5, root);
    //pt(root);
    root = adnd(4, root);
    //printf("\n\n");
    root = adnd(7, root);
    root = adnd(6, root);
    //pt(root);
    //printf("\n\n");
    root = adnd(9, root);
    root = adnd(3, root);
    pt(root);
    printf("\n\n#############\n\n");
    //ptsch(7, root);
   // ptsch(3, root);
    //vis3(root);
    return 0;
}
