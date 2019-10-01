#include<stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

struct Array
{    int A[10];
     int size;
     int length;
};

void Display(struct Array arr)
{        int i;
        printf("\nElements are\n");
        for(i=0;i<arr.length;i++)
            printf("%d ",arr.A[i]);
        }

void Append(struct Array *arr,int x)
{        if(arr->length<arr->size)
         arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{    int i;
     if(index>=0 && index <=arr->length)
        {        for(i=arr->length;i>index;i--)
                 arr->A[i]=arr->A[i-1];
                 arr->A[index]=x;
                 arr->length++;
        }
}

int Delete(struct Array *arr,int index)
{    int x=0;
     int i;
     if(index>=0 && index<arr->length)
        {        x=arr->A[index];
                 for(i=index;i<arr->length-1;i++)
                    arr->A[i]=arr->A[i+1];
                    arr->length--;
                    return x;
        }
        return 0;
}

int RBinSearch(int a[],int l,int h,int key)
{        int mid=0;
            if(l<=h)
                {
                        mid=(l+h)/2;
                        if(key==a[mid])
                            return mid;
                        else if(key<a[mid])
                            return RBinSearch(a,l,mid-1,key);
                }
            else
                return RBinSearch(a,mid+1,h,key);

            return -1;
}


int main()
{ struct Array arr1={{2,3,4,5,6},10,5};
    int choice,pos, data;
    cout<<"current array = "<< Display(arr1);
    do
    {
        cout<<"\n Enter operations to be done on array:- \n#~ ADD new element =1  \n#~ DISPLAY the list = 2 \n #~ DELETE element from array =3 \n #~ SEARCH for an element =4 \n TYPE-  ";
        cin>>choice;

        switch  (choice)
        {
            case 1: cout<< "Enter position= ";
                        cin>>pos;
                    cout<< " Enter Value= "
                        cin>>data;
                        Insert(&arr1,pos,data);
                        break;
            case 2: Display(arr1); break;
            case 3: cout<<"Enter element's index to delete it= ";
                        cin>>pos;
                        Delete(&arr,pos); break;
            case 4: cout<<"Enter value of element to be searched= \n";
                        cin>>data;
                        cout<<"Element fount at position ="<<BinarySearch(arr1,data);
                        break;
            default : cout<<"Wrong choice \n";
        }

            return 0;

}
