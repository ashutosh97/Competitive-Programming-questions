class bs
{
    public boolean binary_search(int arr[], int n)
    {
        int right;int left; int mid;
        right= arr.length;
        left=0;
        do{
            mid= (right+left)/2;
            if(arr[mid]==n)
            return true;
            if(arr[mid]>n)
            right= mid-1;
            else
            left= mid+1;
           }while((arr[mid]!=n)&&(left!=right));
           return false;
    }
    public static void main(String args[])
    {
        bs obj = new bs();
        int a[]={1,2,3,4,5};
        int n= 5;
        if(obj.binary_search(a,n))
        System.out.println("Element found");
        else
        System.out.println("Element is not present");
    }
}
