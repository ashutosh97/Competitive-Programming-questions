class Sum{
    public void print(int arr[],int n)
    {
        int b[] = new int[arr.length-1];
        if(arr.length>1)
        {
            for(int i =0;i<arr.length-1;i++)
            {
                b[i] = arr[i] + arr[i+1];
            }
            print(b,n);
        }
        
        System.out.println();
        for(int j=0;j<n-b.length;j++)
        {
            System.out.print(" ");
        }
        for(int j=0;j<b.length;j++)
        {
            System.out.print(b[j]+" ");
        }
    }
    public static void main(String args[])
    {
        Sum s = new Sum();
        //int a[] = {1,1,1,1,1};
         int a[] = {1,2,1,3,1};
        s.print(a,a.length);
        System.out.println();
        for(int j=0;j<a.length;j++)
        {
            System.out.print(a[j]+" ");
        }
    }
}