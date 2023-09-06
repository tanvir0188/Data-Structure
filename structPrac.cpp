#include<iostream>
using namespace std;



struct rectangle{
    float length;
    float breadth;
};

float area(struct rectangle r){
     return r.length*r.breadth;
}

void initialize(struct rectangle *r, float lngt, float brdth){
    r->length = lngt;
    r->breadth=brdth;
}

void chngLngthbrdth(struct rectangle *p, float l, float b){
    p->length=l;
    p->breadth=b;

}

    

int main(){
    struct rectangle rect;
    initialize(&rect, 15, 2);

    cout<<area(rect)<<endl;
    chngLngthbrdth(&rect, 9.5, 2.0);
    cout<<rect.length<<" "<<rect.breadth<<endl;
    cout<<area(rect);


}