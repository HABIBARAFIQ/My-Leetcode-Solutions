void create(int index,int left,int right,int arr[],int *st)
{
    if(left==right)
    {
        st[index]=arr[left];
        return;
    }
    else
    {
    int mid=(left+right)/2;
    create(2*index+1,left,mid,arr,st);
    create(2*index+2,mid+1,right,arr,st);
    st[index] = std::min(st[2 * index + 1], st[2 * index + 2]);
    }
}
int *constructST(int arr[],int n)
{
  //Your code here
  int* st = new int[4*n]; 
  create(0,0,n-1,arr,st);
  return st;
  
}


/* The functions returns the
 min element in the range
 from a and b */
 int find_minimum(int st[], int index, int left, int right, int L, int R) {
        if (L <= left && right <= R) {
            return st[index];
        }
        if (right < L || left > R) {
            return INT_MAX;
        }
        int mid = left + (right - left) / 2;
        return min(find_minimum(st, 2 * index + 1, left, mid, L, R) ,
               find_minimum(st, 2 * index + 2, mid + 1, right, L, R));
    }
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
int min=find_minimum(st,0,0,n-1,a,b);
return min;
}
